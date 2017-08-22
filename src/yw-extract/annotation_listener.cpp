#include "annotation_listener.h"
#include "annotation.h"

using namespace yw::sqlite;
using namespace yw::db;

using Tag = yw::db::Annotation::Tag;

namespace yw {
    namespace extract {


        auto AnnotationListener::getRangeInLine(antlr4::ParserRuleContext* context) {
            auto startInSource = static_cast<long>(context->getStart()->getStartIndex());
            auto endInSource = static_cast<long>(context->getStop()->getStopIndex());
            auto startInLine = static_cast<long>(context->getStart()->getCharPositionInLine());
            auto endInLine = startInLine + endInSource - startInSource;
            return AnnotationRange{ startInLine, endInLine };
        }

        auto AnnotationListener::getLineId(antlr4::ParserRuleContext* context) {
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

        void AnnotationListener::enterBegin(YWParser::BeginContext *begin)
        {
            auto lineId = getLineId(begin);
            auto rangeInLine = getRangeInLine(begin);
            primaryAnnotationStack.push(currentPrimaryAnnotation);
            auto beginAnnotation = std::make_shared<Annotation>(
                auto_id, extractionId, Tag::BEGIN, 
                (currentPrimaryAnnotation == nullptr ? null_id: currentPrimaryAnnotation->id), 
                lineId, currentRankOnLine++, 
                rangeInLine.start, rangeInLine.end, begin->BeginKeyword()->getText(),
                nullable_string(begin->blockName()->phrase()->unquotedPhrase()->getText()) );
            ywdb.insert(*beginAnnotation);
            currentPrimaryAnnotation = beginAnnotation;
        }

        void AnnotationListener::enterEnd(YWParser::EndContext *end)
        {
            auto lineId = getLineId(end);
            auto rangeInLine = getRangeInLine(end);
            auto optionalBlockName = (end->blockName() != nullptr) ? 
                nullable_string(end->blockName()->phrase()->unquotedPhrase()->getText()) : null_string;
            ywdb.insert(Annotation{
                auto_id, extractionId, Tag::END, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                end->EndKeyword()->getText(), optionalBlockName });
            currentPrimaryAnnotation = primaryAnnotationStack.top();
            primaryAnnotationStack.pop();
        }

        void AnnotationListener::enterDesc(YWParser::DescContext *desc)
        {
            auto lineId = getLineId(desc);
            auto rangeInLine = getRangeInLine(desc);
            ywdb.insert(Annotation{ auto_id, extractionId, Tag::DESC, currentPrimaryAnnotation->id, lineId,
                                       currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                                       desc->DescKeyword()->getText(),
                                       nullable_string(desc->description()->phrase()->unquotedPhrase()->getText()) });
        }

        Annotation::Tag getPortTag(YWParser::PortContext *port)
        {
            if (port->inputKeyword() != NULL) {
                if (port->inputKeyword()->InKeyword() != NULL) return Tag::IN;
                if (port->inputKeyword()->ParamKeyword() != NULL) return Tag::PARAM;
            }
            else if (port->outputKeyword() != NULL) {
                if (port->outputKeyword()->OutKeyword() != NULL) return Tag::OUT;
                if (port->outputKeyword()->ReturnKeyword() != NULL) return Tag::RETURN;
            }

            throw std::runtime_error("unrecognized port type");
        }

        void AnnotationListener::enterPort(YWParser::PortContext *port) {
            portTag = getPortTag(port);
            portLineId = getLineId(port);
            portKeyword = port->inputKeyword() != NULL ? 
                port->inputKeyword()->getText() : 
                port->outputKeyword()->getText();
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

        void AnnotationListener::exitIo(YWParser::IoContext *context) {
            currentPrimaryAnnotation = primaryAnnotationStack.top();
            primaryAnnotationStack.pop();
        }

    }
}