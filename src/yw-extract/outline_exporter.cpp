#include "outline_exporter.h"
#include <sstream>

using namespace yw::db;
using namespace yw::sqlite;

namespace yw {
    namespace extract {

        std::string spaces(size_t n) {
            static std::string spaces{ " " };
            while (spaces.length() < n) spaces += spaces;
            return spaces.substr(0, n);
        }

        std::string OutlineExporter::getOutline() {

            std::stringstream multiRootOutline;
            auto rootAnnotations = ywdb.selectTopLevelAnnotations();
            bool first = true;
            for (auto root : rootAnnotations) {
                if (!first) {
                    multiRootOutline << std::endl;
                }
                else {
                    first = false;
                }
                multiRootOutline << getOutline(root.id);
            }

            return multiRootOutline.str();
        }

        void OutlineExporter::printAnnotation(const AnnotationRow& annotation) {
            outline << spaces(currentIndent) << annotation.keyword << " " << annotation.value.getValue() << std::endl;
        }

        std::string OutlineExporter::getOutline(const nullable_row_id& rootAnnotation) {

            using Tag = yw::db::AnnotationRow::Tag;

            outline.str("");
            currentIndent = 0;
            bool firstBlock = true;
            Tag lastAnnotationTag;

            auto annotations = ywdb.selectAnnotationTree(rootAnnotation);

            for (auto annotation : annotations) {

                switch (annotation.tag) {

                case Tag::BEGIN:
                    if (firstBlock) firstBlock = false; else outline << std::endl;
                    if (annotation.qualifiesId.hasValue()) {
                        currentIndent += blockIndentSize;
                    }
                    printAnnotation(annotation);
                    break;

                case Tag::END:
                    if (lastAnnotationTag == Tag::END) outline << std::endl;
                    printAnnotation(annotation);
                    if (blockIndentSize > 0 && currentIndent >= blockIndentSize) {
                        currentIndent -= blockIndentSize;
                    }
                    break;

                default:
                    printAnnotation(annotation);
                }

                lastAnnotationTag = annotation.tag;
            }

            return outline.str();
        }
    }
}