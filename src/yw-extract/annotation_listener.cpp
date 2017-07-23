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

		void AnnotationListener::enterBegin(YWParser::BeginContext *begin) 
		{
			auto rangeInLine = getCharacterRangeOnLine(begin);
			lastPrimaryAnnotationId = ywdb.insert(
				AnnotationRow{ auto_id, null_id, getLineId(begin),
							   rangeInLine.start, rangeInLine.end,
							   begin->BeginKeyword()->getText(),
							   nullable_string(begin->blockName()->getText()) });
		}

		void AnnotationListener::enterEnd(YWParser::EndContext *end) 
		{
			auto rangeInLine = getCharacterRangeOnLine(end);
			ywdb.insert(AnnotationRow{ auto_id, null_id, getLineId(end), 
									   rangeInLine.start, rangeInLine.end, 
									   end->EndKeyword()->getText(), 
									   getNullableArgument(end->blockName()) });
		}

		void AnnotationListener::enterDesc(YWParser::DescContext *desc) 
		{
			auto rangeInLine = getCharacterRangeOnLine(desc);
			ywdb.insert(AnnotationRow{ auto_id, lastPrimaryAnnotationId, getLineId(desc),
				                       rangeInLine.start, rangeInLine.end,
				                       desc->DescKeyword()->getText(),
				                       nullable_string(desc->description()->getText()) });
		}
		
		void AnnotationListener::enterPort(YWParser::PortContext *port) {
			auto rangeInLine = getCharacterRangeOnLine(port);
			nullable_row_id lastPortId;
			if (port->inputKeyword() != NULL) {
				for (auto portName : port->portName()) {
					lastPortId = ywdb.insert(
						AnnotationRow{ auto_id, lastPrimaryAnnotationId, getLineId(port),
						               rangeInLine.start, rangeInLine.end,
						               port->inputKeyword()->getText(),
						               nullable_string(portName->getText()) });
				}
			}
			lastPrimaryAnnotationId = lastPortId;
		}

		void AnnotationListener::enterAlias(YWParser::AliasContext *context) {};
		void AnnotationListener::enterCall(YWParser::CallContext *context) {};
		void AnnotationListener::enterUri(YWParser::UriContext *context) {};
		void AnnotationListener::enterFile(YWParser::FileContext *context) {};
		void AnnotationListener::enterResource(YWParser::ResourceContext *context) {};
	}
}