#include "annotation_listener.h"
#include "annotation_row.h"

using namespace yw::sqlite;
using namespace yw::db;

namespace yw {
	namespace extract {

		AnnotationListener::AnnotationListener(YesWorkflowDB& ywdb, yw::sqlite::row_id sourceId) :
			ywdb(ywdb), sourceId(sourceId) {}

		void AnnotationListener::enterBegin(YWParser::BeginContext *context) 
		{
			auto lineNumber = context->getStart()->getLine();
			auto annotationText = context->getText();
			auto line_id = ywdb.insert(LineRow{ auto_id, sourceId, long(lineNumber), annotationText });
			auto tokens = context->getTokens(10);
			auto startIndex = context->getStart()->getStartIndex();
			auto endIndex = context->getStop()->getStopIndex();
			auto beginKeyword = context->BeginKeyword()->getText();
			auto blockName = nullable_string(context->blockName()->getText());
			ywdb.insert(AnnotationRow{ auto_id, null_id, line_id, long(startIndex), long(endIndex), beginKeyword, blockName });
		}

		void AnnotationListener::enterEnd(YWParser::EndContext *context) 
		{
			auto lineNumber = context->getStart()->getLine();
			auto annotationText = context->getText();
			auto line_id = ywdb.insert(LineRow{ auto_id, sourceId, long(lineNumber), annotationText });
			auto startIndex = context->getStart()->getStartIndex();
			auto endIndex = context->getStop()->getStopIndex();
			auto endKeyword = context->EndKeyword()->getText();
			nullable_string blockName = (context->blockName() == NULL) ? null_string : nullable_string(context->blockName()->getText());
			ywdb.insert(AnnotationRow{ auto_id, null_id, line_id, long(startIndex), long(endIndex), endKeyword, blockName });
		};

		void AnnotationListener::enterDesc(YWParser::DescContext *context) {};
		void AnnotationListener::enterPort(YWParser::PortContext *context) {};
		void AnnotationListener::enterAlias(YWParser::AliasContext *context) {};
		void AnnotationListener::enterCall(YWParser::CallContext *context) {};
		void AnnotationListener::enterUri(YWParser::UriContext *context) {};
		void AnnotationListener::enterFile(YWParser::FileContext *context) {};
		void AnnotationListener::enterResource(YWParser::ResourceContext *context) {};
	}
}