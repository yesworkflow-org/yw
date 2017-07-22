#pragma once

#include "yesworkflow_db.h"
#include "YWBaseListener.h"

namespace yw {
	namespace extract {

		class AnnotationListener : public YWBaseListener {

			const yw::sqlite::row_id sourceId;
			yw::db::YesWorkflowDB& ywdb;
			yw::sqlite::nullable_row_id lastBeginId = yw::sqlite::null_id;
			yw::sqlite::nullable_row_id lastPortId = yw::sqlite::null_id;

		public:

			AnnotationListener(yw::db::YesWorkflowDB& ywdb, yw::sqlite::row_id sourceId);

			void enterBegin(YWParser::BeginContext *context) override;
			void enterEnd(YWParser::EndContext *context) override;
			void enterDesc(YWParser::DescContext *context) override;
			void enterPort(YWParser::PortContext *context) override;
			void enterAlias(YWParser::AliasContext *context) override;
			void enterCall(YWParser::CallContext *context) override;
			void enterUri(YWParser::UriContext *context) override;
			void enterFile(YWParser::FileContext *context) override;
			void enterResource(YWParser::ResourceContext *context) override;

		private:

			yw::sqlite::row_id getLineId(antlr4::ParserRuleContext* context);
			yw::sqlite::nullable_string getNullableArgument(antlr4::ParserRuleContext* context);
		};
	}
}