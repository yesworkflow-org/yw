#include "annotation_listener.h"
#include "annotation_row.h"

using namespace yw::sqlite;
using namespace yw::db;

using Tag = yw::db::AnnotationRow::Tag;

namespace yw {
	namespace extract {

		AnnotationListener::AnnotationListener(YesWorkflowDB& ywdb, yw::sqlite::row_id sourceId) :
			ywdb(ywdb), sourceId(sourceId) {}

		struct AnnotationRange { long start; long end; };

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

		auto AnnotationListener::getNullableArgument(antlr4::ParserRuleContext* context) {
			if (context == NULL) {
				return null_string;
			}
			else {
				return nullable_string(context->getText());
			}
		}

		void AnnotationListener::enterAlias(YWParser::AliasContext *alias)
		{
			auto lineId = getLineId(alias);
			auto rangeInLine = getRangeInLine(alias);
			ywdb.insert(AnnotationRow{ auto_id, Tag::AS, currentPrimaryAnnotationId, lineId,
				currentRankOnLine++, rangeInLine.start, rangeInLine.end,
				alias->AsKeyword()->getText(),
				nullable_string(alias->dataName()->getText()) });
		}

		void AnnotationListener::enterBegin(YWParser::BeginContext *begin) 
		{
			auto lineId = getLineId(begin);
			auto rangeInLine = getRangeInLine(begin);
			primaryAnnotationId.push(currentPrimaryAnnotationId);
			currentPrimaryAnnotationId = ywdb.insert(
				AnnotationRow{ auto_id, Tag::BEGIN, currentPrimaryAnnotationId, lineId,
							   currentRankOnLine++, rangeInLine.start, rangeInLine.end,
							   begin->BeginKeyword()->getText(),
							   nullable_string(begin->blockName()->getText()) });
		}

		void AnnotationListener::enterEnd(YWParser::EndContext *end) 
		{
			auto lineId = getLineId(end);
			auto rangeInLine = getRangeInLine(end);
			ywdb.insert(AnnotationRow{ auto_id, Tag::END, currentPrimaryAnnotationId, lineId,
									   currentRankOnLine++, rangeInLine.start, rangeInLine.end,
									   end->EndKeyword()->getText(), 
									   getNullableArgument(end->blockName()) });
			currentPrimaryAnnotationId = primaryAnnotationId.top();
			primaryAnnotationId.pop();
		}

		void AnnotationListener::enterDesc(YWParser::DescContext *desc) 
		{
			auto lineId = getLineId(desc);
			auto rangeInLine = getRangeInLine(desc);
			ywdb.insert(AnnotationRow{ auto_id, Tag::DESC, currentPrimaryAnnotationId, lineId,
									   currentRankOnLine++, rangeInLine.start, rangeInLine.end,
				                       desc->DescKeyword()->getText(),
				                       nullable_string(desc->description()->getText()) });
		}
		
		AnnotationRow::Tag getPortTag(YWParser::PortContext *port)
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
			auto tag = getPortTag(port);
			auto lineId = getLineId(port);
			auto rangeInLine = getRangeInLine(port);
			nullable_row_id lastPortId;
			for (auto portName : port->portName()) {
				auto keyword = port->inputKeyword() != NULL ? port->inputKeyword()->getText() : port->outputKeyword()->getText();
				lastPortId = ywdb.insert(
					AnnotationRow{ auto_id, tag, currentPrimaryAnnotationId, lineId,
								   currentRankOnLine++, rangeInLine.start, rangeInLine.end,
						           keyword, nullable_string(portName->getText()) });
			}
			primaryAnnotationId.push(currentPrimaryAnnotationId);
			currentPrimaryAnnotationId = lastPortId;
		}

		void AnnotationListener::exitIo(YWParser::IoContext *context) {
			currentPrimaryAnnotationId = primaryAnnotationId.top();
			primaryAnnotationId.pop();
		}

		void AnnotationListener::enterCall(YWParser::CallContext *context) {};
		void AnnotationListener::enterUri(YWParser::UriContext *context) {};
		void AnnotationListener::enterFile(YWParser::FileContext *context) {};
		void AnnotationListener::enterResource(YWParser::ResourceContext *context) {};
	}
}