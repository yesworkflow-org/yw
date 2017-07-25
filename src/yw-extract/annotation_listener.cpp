#include "annotation_listener.h"
#include "annotation_row.h"

using namespace yw::sqlite;
using namespace yw::db;

namespace yw {
	namespace extract {

		AnnotationListener::AnnotationListener(YesWorkflowDB& ywdb, yw::sqlite::row_id sourceId) :
			ywdb(ywdb), sourceId(sourceId) {}

		struct CharacterRange { long start; long end; };

		auto getCharacterRangeOnLine(antlr4::ParserRuleContext* context) {
			auto startInSource = static_cast<long>(context->getStart()->getStartIndex());
			auto endInSource = static_cast<long>(context->getStop()->getStopIndex());
			auto startInLine = static_cast<long>(context->getStart()->getCharPositionInLine());
			auto endInLine = startInLine + endInSource - startInSource;
			return CharacterRange{ startInLine, endInLine };
		}

		row_id AnnotationListener::getLineId(antlr4::ParserRuleContext* context) {
			auto lineNumber = static_cast<long>(context->getStart()->getLine());
			return ywdb.selectLineIdBySourceAndLineNumber(sourceId, lineNumber);
		}

		nullable_string AnnotationListener::getNullableArgument(antlr4::ParserRuleContext* context) {
			if (context == NULL) {
				return null_string;
			}
			else {
				return nullable_string(context->getText());
			}
		}

		void AnnotationListener::enterAlias(YWParser::AliasContext *alias)
		{
			auto rangeInLine = getCharacterRangeOnLine(alias);
			ywdb.insert(AnnotationRow{ auto_id, currentPrimaryAnnotationId, getLineId(alias),
				rangeInLine.start, rangeInLine.end,
				alias->AsKeyword()->getText(),
				nullable_string(alias->dataName()->getText()) });
		}

		void AnnotationListener::enterBegin(YWParser::BeginContext *begin) 
		{
			auto rangeInLine = getCharacterRangeOnLine(begin);
			primaryAnnotationId.push(currentPrimaryAnnotationId);
			currentPrimaryAnnotationId = ywdb.insert(
				AnnotationRow{ auto_id, null_id, getLineId(begin),
							   rangeInLine.start, rangeInLine.end,
							   begin->BeginKeyword()->getText(),
							   nullable_string(begin->blockName()->getText()) });
		}

		void AnnotationListener::enterEnd(YWParser::EndContext *end) 
		{
			auto rangeInLine = getCharacterRangeOnLine(end);
			ywdb.insert(AnnotationRow{ auto_id, currentPrimaryAnnotationId, getLineId(end),
									   rangeInLine.start, rangeInLine.end, 
									   end->EndKeyword()->getText(), 
									   getNullableArgument(end->blockName()) });
			currentPrimaryAnnotationId = primaryAnnotationId.top();
			primaryAnnotationId.pop();
		}

		void AnnotationListener::enterDesc(YWParser::DescContext *desc) 
		{
			auto rangeInLine = getCharacterRangeOnLine(desc);
			ywdb.insert(AnnotationRow{ auto_id, currentPrimaryAnnotationId, getLineId(desc),
				                       rangeInLine.start, rangeInLine.end,
				                       desc->DescKeyword()->getText(),
				                       nullable_string(desc->description()->getText()) });
		}
		
		void AnnotationListener::enterPort(YWParser::PortContext *port) {
			auto rangeInLine = getCharacterRangeOnLine(port);
			nullable_row_id lastPortId;
			for (auto portName : port->portName()) {
				auto keyword = port->inputKeyword() != NULL ? port->inputKeyword()->getText() : port->outputKeyword()->getText();
				lastPortId = ywdb.insert(
					AnnotationRow{ auto_id, currentPrimaryAnnotationId, getLineId(port),
						           rangeInLine.start, rangeInLine.end,
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