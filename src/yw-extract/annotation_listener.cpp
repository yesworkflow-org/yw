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

		void AnnotationListener::enterBegin(YWParser::BeginContext *context) 
		{
			auto rangeInLine = getCharacterRangeOnLine(context);
			lastBeginId = ywdb.insert(
				AnnotationRow{ auto_id, null_id, getLineId(context),
							   rangeInLine.start, rangeInLine.end,
							   context->BeginKeyword()->getText(),
							   nullable_string(context->blockName()->getText()) });
		}

		void AnnotationListener::enterEnd(YWParser::EndContext *context) 
		{
			auto rangeInLine = getCharacterRangeOnLine(context);
			ywdb.insert(AnnotationRow{ auto_id, null_id, getLineId(context), 
									   rangeInLine.start, rangeInLine.end, 
									   context->EndKeyword()->getText(), 
									   getNullableArgument(context->blockName()) });
			lastBeginId = null_id;
		}

		void AnnotationListener::enterDesc(YWParser::DescContext *context) 
		{
			auto rangeInLine = getCharacterRangeOnLine(context);
			ywdb.insert(AnnotationRow{ auto_id, lastBeginId, getLineId(context),
				                       rangeInLine.start, rangeInLine.end,
				                       context->DescKeyword()->getText(),
				                       nullable_string(context->description()->getText()) });
		}
		
		void AnnotationListener::enterPort(YWParser::PortContext *context) {
			auto rangeInLine = getCharacterRangeOnLine(context);
			if (context->inputKeyword() != NULL) {
				for (auto portName : context->portName()) {
					ywdb.insert(AnnotationRow{ auto_id, lastBeginId, getLineId(context),
						rangeInLine.start, rangeInLine.end,
						context->inputKeyword()->getText(),
						nullable_string(portName->getText()) });
				}
			}
		}

		void AnnotationListener::enterAlias(YWParser::AliasContext *context) {};
		void AnnotationListener::enterCall(YWParser::CallContext *context) {};
		void AnnotationListener::enterUri(YWParser::UriContext *context) {};
		void AnnotationListener::enterFile(YWParser::FileContext *context) {};
		void AnnotationListener::enterResource(YWParser::ResourceContext *context) {};
	}
}