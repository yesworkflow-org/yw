#include "annotation_listener.h"
#include "annotation.h"
#include "annotation_syntax_exception.h"
#include "unexpected_annotation_exception.h"
#include "invalid_argument_exception.h"
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

            auto aliasName = safelyGetAliasNameFromAliasContext(alias);

            ywdb.insert(Annotation{ auto_id, extractionId, Tag::AS, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                safelyGetAsKeywordText(alias),
                nullable_string(aliasName) });
        }

        void AnnotationListener::enterBegin(YWParser::BeginContext *begin)
        {
            auto lineId = getLineId(begin);
            auto rangeInLine = getRangeInLine(begin);
            auto beginText = safelyGetBeginKeywordText(begin);
            auto blockNameText = safelyGetBlockNameFromBeginContext(begin);

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
            auto endKeywordText = safelyGetEndKeywordText(end);
            auto optionalBlockName = safelyGetOptionalBlockNameFromEndContext(end);

            ywdb.insert(Annotation{
                auto_id, extractionId, Tag::END, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                endKeywordText, optionalBlockName });
            currentPrimaryAnnotation = primaryAnnotationStack.top();
            primaryAnnotationStack.pop();
        }

        void AnnotationListener::enterBlockDesc(YWParser::BlockDescContext *desc)
        {
            auto lineId = getLineId(desc);
            auto rangeInLine = getRangeInLine(desc);
            auto descText = safelyGetBlockDescKeywordText(desc);
            auto blockDescriptionText = safelyDescriptionTextFromBlockDescContext(desc);

            ywdb.insert(Annotation{ auto_id, extractionId, Tag::DESC, currentPrimaryAnnotation->id, lineId,
                                    currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                                    descText, nullable_string(blockDescriptionText) }
            );
        }

        void AnnotationListener::enterPortDesc(YWParser::PortDescContext *desc)
        {
            auto lineId = getLineId(desc);
            auto rangeInLine = getRangeInLine(desc);
            auto descText = safelyGetPortDescKeywordText(desc);
            auto portDescriptionText = safelyDescriptionTextFromPortDescContext(desc);

            ywdb.insert(Annotation{ auto_id, extractionId, Tag::DESC, currentPrimaryAnnotation->id, lineId,
                currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                descText, nullable_string(portDescriptionText) });
        }

        void AnnotationListener::enterPort(YWParser::PortContext *port) {

            portTag = safelyGetPortTagFromPortContext(port);
            portLineId = getLineId(port);
            portKeyword = safelyGetPortKeywordText(port);
            portDirection = safelyGetPortDirection(port);
            portRangeInLine = getRangeInLine(port);

            if (port->portName().size() == 0) {
                throw yw::parse::MissingArgumentException(
                    portKeyword,
                    "port name",
                    portRangeInLine.start + 1,
                    currentLineNumber
                );
            }
        }

        void AnnotationListener::enterPortName(YWParser::PortNameContext *context) {

            portName = nullable_string{ safelyGetPortNameFromPortNameContext(context) };

            lastPortAnnotation = std::make_shared<Annotation>(
                auto_id, extractionId, portTag, currentPrimaryAnnotation->id, portLineId,
                currentRankOnLine++, portRangeInLine.start, portRangeInLine.end,
                portKeyword, nullable_string{ portName });
            
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

        void AnnotationListener::enterResource(YWParser::ResourceContext *context) {
            auto lineId = getLineId(context);
            auto rangeInLine = getRangeInLine(context);

            if (context->file() != nullptr) {
                auto uri = safelyGetComponentsFromFileResourceContext(context->file());
                flowTemplateScheme = null_string;
                flowTemplatePath = std::get<0>(uri);
                auto flowTemplateText = std::get<1>(uri);
                auto fileKeywordText = safelyGetFileKeywordText(context->file());
                ywdb.insert(Annotation{ auto_id, extractionId, Tag::FILE, currentPrimaryAnnotation->id, lineId,
                    currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                    fileKeywordText, nullable_string(flowTemplateText) });
            }
            else if (context->uri() != nullptr) {
                auto uri = safelyGetComponentsFromUriResourceContext(context->uri());
                flowTemplateScheme = std::get<0>(uri);
                flowTemplatePath = std::get<1>(uri);
                auto uriTemplateText = std::get<2>(uri);
                auto uriKeywordText = safelyGetUriKeywordText(context->uri());
                ywdb.insert(Annotation{ auto_id, extractionId, Tag::URI, currentPrimaryAnnotation->id, lineId,
                    currentRankOnLine++, rangeInLine.start, rangeInLine.end,
                    uriKeywordText, nullable_string(uriTemplateText) });
            }
            else {
                flowTemplateScheme = null_string;
                flowTemplatePath = null_string;
            }
        }
    }
}