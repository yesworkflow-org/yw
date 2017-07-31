#include "outline_exporter.h"
#include <sstream>

using namespace yw::db;

namespace yw {
    namespace extract {

        std::string OutlineExporter::getOutline() {

            std::stringstream outline;
            auto rootAnnotations = ywdb.selectTopLevelAnnotations();
            bool first = true;
            for (auto root : rootAnnotations) {
                if (!first) {
                    outline << std::endl;
                }
                else {
                    first = false;
                }
                outline << getOutline(root.id);
            }

            return outline.str();
        }

        std::string OutlineExporter::getOutline(yw::sqlite::nullable_row_id rootAnnotation) {

            using Tag = yw::db::AnnotationRow::Tag;

            std::string indent{ "" };
            std::stringstream outline;
            AnnotationRow* parentBegin = nullptr;
            bool lastLineWasBlank = false;

            auto annotations = ywdb.selectAnnotationTree(rootAnnotation);

            for (auto annotation : annotations) {

                if (annotation.tag == Tag::BEGIN) {
                    if (parentBegin != nullptr) {
                        indent += "    ";
                        if (!lastLineWasBlank) {
                            outline << std::endl;
                            lastLineWasBlank = true;
                        }
                    }
                    parentBegin = &annotation;
                }

                outline << indent << annotation.keyword << " " << annotation.value.getValue() << std::endl;
                lastLineWasBlank = false;

                if (annotation.tag == Tag::END) {

                    if (indent.length() >= 4) {
                        outline << std::endl;
                        indent = indent.substr(0, indent.length() - 4);
                        lastLineWasBlank = true;
                    }
                }
            }

            return outline.str();
        }
    }
}