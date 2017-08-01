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

        void OutlineExporter::append(const AnnotationRow& annotation) {
            outline << annotation.keyword
                    << " "
                    << annotation.value.getValue();
        }

        void OutlineExporter::appendOnNewLine(const AnnotationRow& annotation) {
            outline << std::endl << spaces(nesting * blockIndentSize);
            append(annotation);
        }

        void OutlineExporter::appendOnSameLine(const AnnotationRow& annotation) {
            outline << " ";
            append(annotation);
        }

        std::string OutlineExporter::getOutline(const nullable_row_id& rootAnnotation) {

            using Tag = yw::db::AnnotationRow::Tag;

            outline.str("");
            nesting = 0;
            bool firstBlock = true;
            Tag lastAnnotationTag;

            auto annotations = ywdb.selectAnnotationTree(rootAnnotation);

            for (auto annotation : annotations) {

                switch (annotation.tag) {

                case Tag::BEGIN:
                    if (firstBlock) {
                        append(annotation);
                        firstBlock = false;
                    }
                    else {
                        if (annotation.qualifiesId.hasValue()) nesting++;
                        outline << std::endl;
                        appendOnNewLine(annotation);
                    }
                    break;

                case Tag::END:
                    if (lastAnnotationTag == Tag::END) outline << std::endl;
                    appendOnNewLine(annotation);
                    if (nesting > 0) nesting--;
                    break;

                default:
                    appendOnNewLine(annotation);
                }

                lastAnnotationTag = annotation.tag;
            }

            outline << std::endl;

            return outline.str();
        }
    }
}