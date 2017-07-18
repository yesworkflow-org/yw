#pragma once

#include "YWBaseListener.h"

using namespace yw;

namespace yw {
	namespace extract {

		class AnnotationListener : public YWBaseListener {

			void enterBegin(YWParser::BeginContext *context) override;
			void enterEnd(YWParser::EndContext *context) override;
			void enterDesc(YWParser::DescContext *context) override;
			void enterPort(YWParser::PortContext *context) override;
			void enterAlias(YWParser::AliasContext *context) override;
			void enterCall(YWParser::CallContext *context) override;
			void enterUri(YWParser::UriContext *context) override;
			void enterFile(YWParser::FileContext *context) override;
			void enterResource(YWParser::ResourceContext *context) override;

		};
	}
}