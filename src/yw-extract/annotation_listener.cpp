#include "annotation_listener.h"

namespace yw {
	namespace extract {
		void AnnotationListener::enterBegin(YWParser::BeginContext *context) {};
		void AnnotationListener::enterEnd(YWParser::EndContext *context) {};
		void AnnotationListener::enterDesc(YWParser::DescContext *context) {};
		void AnnotationListener::enterPort(YWParser::PortContext *context) {};
		void AnnotationListener::enterAlias(YWParser::AliasContext *context) {};
		void AnnotationListener::enterCall(YWParser::CallContext *context) {};
		void AnnotationListener::enterUri(YWParser::UriContext *context) {};
		void AnnotationListener::enterFile(YWParser::FileContext *context) {};
		void AnnotationListener::enterResource(YWParser::ResourceContext *context) {};
	}
}