#include "annotation_listener.h"
#include "annotation.h"
#include "annotation_syntax_exception.h"
#include "unexpected_annotation_exception.h"
#include "missing_argument_exception.h"
#include "misplaced_begin_child_exception.h"
#include "misplaced_port_child_exception.h"
#include "misplaced_end_exception.h"

#include <istream>
#include <regex>

using namespace yw::sqlite;
using namespace yw::db;

using Tag = yw::db::Annotation::Tag;

namespace yw {
    namespace extract {

        AnnotationListener::AnnotationRange AnnotationListener::getRangeInLine(antlr4::ParserRuleContext* context) {
            auto startInSource = static_cast<long>(context->getStart()->getStartIndex());
            auto endInSource = static_cast<long>(context->getStop()->getStopIndex());
            auto startInLine = static_cast<long>(context->getStart()->getCharPositionInLine());
            auto endInLine = startInLine + endInSource - startInSource;
            return AnnotationRange{ startInLine, endInLine };
        }

        row_id AnnotationListener::getLineId(antlr4::ParserRuleContext* context) {
            auto lineNumber = static_cast<long>(context->getStart()->getLine());
            if (lineNumber != currentLineNumber) {
                currentLineNumber = lineNumber;
                currentRankOnLine = 1;
            }
            return ywdb.selectLineIdBySourceAndLineNumber(sourceId, lineNumber);
        }

        void AnnotationListener::enterAlias(YWParser::AliasContext *alias)
        {
            auto lineId = getLineId(alias);
            auto rangeInLine = getRangeInLine(alias);
            ywdb.insert(Annotation{ auto_id, extractionId, Tag::AS, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                alias->AsKeyword()->getText(),
                nullable_string(alias->dataName()->phrase()->unquotedPhrase()->getText()) });
        }

        std::string safelyGetBlockNameFromBeginContext(YWParser::BeginContext *begin) {

            YWParser::BlockNameContext* blockName;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string blockNameText;

            if ( ((blockName = begin->blockName()) == nullptr) ||
                 ((phrase = blockName->phrase()) == nullptr) ||
                 ((unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                 ((blockNameText = unquotedPhrase->getText())) == "<missing WORD>") ||
                 (blockNameText.empty()) 
            ) {
                throw std::exception();
            }

            return blockNameText;
        }

        void AnnotationListener::enterBegin(YWParser::BeginContext *begin)
        {
            auto lineId = getLineId(begin);
            auto rangeInLine = getRangeInLine(begin);
            auto beginText = begin->BeginKeyword()->getText();

            std::string blockNameText;
            try {
                blockNameText = safelyGetBlockNameFromBeginContext(begin);
            }
            catch (std::exception) {
                throw yw::parse::MissingArgumentException(
                    beginText,
                    "block name",
                    rangeInLine.start + 1,
                    currentLineNumber
                );
            }

            primaryAnnotationStack.push(currentPrimaryAnnotation);
            auto beginAnnotation = std::make_shared<Annotation>(
                auto_id, extractionId, Tag::BEGIN, 
                (currentPrimaryAnnotation == nullptr ? null_id: currentPrimaryAnnotation->id), 
                lineId, currentRankOnLine++, 
                rangeInLine.start, rangeInLine.end, beginText,
                nullable_string(blockNameText));
            ywdb.insert(*beginAnnotation);
            currentPrimaryAnnotation = beginAnnotation;
        }

        bool AnnotationListener::inProgramBlock() {
            return currentPrimaryAnnotation != nullptr;
        }

        void AnnotationListener::enterEnd(YWParser::EndContext *end)
        {
            auto lineId = getLineId(end);
            auto rangeInLine = getRangeInLine(end);

            auto endKeywordText = end->EndKeyword()->getText();

            auto optionalBlockName = (end->blockName() != nullptr) ? 
                nullable_string(end->blockName()->phrase()->unquotedPhrase()->getText()) : null_string;
            ywdb.insert(Annotation{
                auto_id, extractionId, Tag::END, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                endKeywordText, optionalBlockName });
            currentPrimaryAnnotation = primaryAnnotationStack.top();
            primaryAnnotationStack.pop();
        }

        std::string AnnotationListener::safelyDescriptionTextFromDescContext(YWParser::DescContext *desc) {

            YWParser::DescriptionContext* description;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string descriptionText;

            if ((description = desc->description()) == nullptr ||
                (phrase = description->phrase()) == nullptr ||
                (unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                (descriptionText = unquotedPhrase->getText()) == "<missing WORD>" ||
                descriptionText.empty()
                ) {
                throw std::exception();
            }
            return descriptionText;
        }

        void AnnotationListener::enterDesc(YWParser::DescContext *desc)
        {
            auto lineId = getLineId(desc);
            auto rangeInLine = getRangeInLine(desc);
            auto descText = desc->DescKeyword()->getText();

            std::string blockDescriptionText;
            try {
                blockDescriptionText = safelyDescriptionTextFromDescContext(desc);
            }
            catch (std::exception) {
                throw yw::parse::MissingArgumentException(
                    descText,
                    "block description",
                    rangeInLine.start + 1,
                    currentLineNumber
                );
            }

            ywdb.insert(Annotation{ auto_id, extractionId, Tag::DESC, currentPrimaryAnnotation->id, lineId,
                                       currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                                       descText, nullable_string(blockDescriptionText) });
        }

        Annotation::Tag getPortTag(YWParser::PortContext *port)
        {
            if (port->inputKeyword() != NULL) {
                if (port->inputKeyword()->InKeyword() != NULL) return Tag::IN;
                if (port->inputKeyword()->ParamKeyword() != NULL) return Tag::PARAM;
            }
            else if (port->outputKeyword() != NULL) {
                if (port->outputKeyword()->OutKeyword() != NULL) return Tag::OUT;
            }

            throw std::runtime_error("unrecognized port type");
        }

        void AnnotationListener::enterPort(YWParser::PortContext *port) {

            portTag = getPortTag(port);
            portLineId = getLineId(port);
            if (port->inputKeyword() != NULL) {
                portKeyword = port->inputKeyword()->getText();
                portDirection = Flow::Direction::IN;
            }
            else {
                portKeyword = port->outputKeyword()->getText();
                portDirection = Flow::Direction::OUT;
            }
            portRangeInLine = getRangeInLine(port);
        }

        void AnnotationListener::enterPortName(YWParser::PortNameContext *context) {

            portName = nullable_string(context->word()->unquotedWord()->getText());
            lastPortAnnotation = std::make_shared<Annotation>(
                auto_id, extractionId, portTag, currentPrimaryAnnotation->id, portLineId,
                currentRankOnLine++, portRangeInLine.start, portRangeInLine.end,
                portKeyword, portName);
            ywdb.insert(*lastPortAnnotation);
        }

        void AnnotationListener::exitPort(YWParser::PortContext *port) {
            primaryAnnotationStack.push(currentPrimaryAnnotation);
            currentPrimaryAnnotation = lastPortAnnotation;
        }

        void AnnotationListener::enterIo(YWParser::IoContext *io) 
        {
        }

        void AnnotationListener::exitIo(YWParser::IoContext *io) {
            currentPrimaryAnnotation = primaryAnnotationStack.top();
            primaryAnnotationStack.pop();
        }

    }
}