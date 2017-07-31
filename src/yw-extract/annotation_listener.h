#pragma once

#include "yesworkflow_db.h"
#include "YWBaseListener.h"

namespace yw {
	namespace extract {

		class AnnotationListener : public YWBaseListener {

			yw::db::YesWorkflowDB& ywdb;
			const yw::sqlite::row_id extractionId;
			const yw::sqlite::row_id sourceId;
			yw::sqlite::nullable_row_id currentPrimaryAnnotationId;
			std::stack<yw::sqlite::nullable_row_id> primaryAnnotationId;
			long currentLineNumber = 0;
			long currentRankOnLine = 0;

		public:

			AnnotationListener(
				yw::db::YesWorkflowDB& ywdb,
				const yw::sqlite::row_id& extractionId,
				const yw::sqlite::row_id& sourceId
			) : ywdb(ywdb), extractionId(extractionId), sourceId(sourceId) 
			{}

			void enterBegin(YWParser::BeginContext *context) override;
			void enterEnd(YWParser::EndContext *context) override;
			void enterDesc(YWParser::DescContext *context) override;
			void enterPort(YWParser::PortContext *context) override;
			void enterAlias(YWParser::AliasContext *context) override;
			void enterCall(YWParser::CallContext *context) override;
			void enterUri(YWParser::UriContext *context) override;
			void enterFile(YWParser::FileContext *context) override;
			void enterResource(YWParser::ResourceContext *context) override;
			void exitIo(YWParser::IoContext *context) override;

		private:

			auto getLineId(antlr4::ParserRuleContext* context);
			auto getNullableArgument(antlr4::ParserRuleContext* context);
			auto getRangeInLine(antlr4::ParserRuleContext* context);
		};
	}
}

