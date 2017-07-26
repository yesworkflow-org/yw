#include "outline_exporter.h"
#include <sstream>
namespace yw {
	namespace extract {

		std::string OutlineExporter::getOutline(yw::sqlite::row_id rootAnnotation) {

			std::stringstream outline;
			auto annotations = ywdb.selectAnnotationTree(rootAnnotation);
			for (auto annotation : annotations) {
				outline << annotation.tag << " " << annotation.value.getValue() << std::endl;
			}
			return outline.str();
		}
	}
}