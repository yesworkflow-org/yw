#include "outline_exporter.h"
#include <sstream>

using namespace yw::db;
using namespace yw::sqlite;

using std::string;

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

        void OutlineExporter::append(const string& keyword, const string& value) {
            outline << keyword << " " << value;
        }

        void OutlineExporter::appendOnNewLine(const string& keyword, const string& value, const size_t extraIndent) {
            outline << std::endl 
                    << spaces((blockStack.size() - 1) * blockIndentSize + extraIndent);
            append(keyword, value);
        }

        void OutlineExporter::appendOnSameLine(const string& keyword, const string& value) {
            outline << " ";
            append(keyword, value);
        }

        std::string OutlineExporter::getOutline(const nullable_row_id& rootAnnotation) {

            using Tag = yw::db::AnnotationRow::Tag;

            outline.str("");
            while (!blockStack.empty()) blockStack.pop();
            bool firstBlock = true;
            Tag lastAnnotationTag;

            auto annotations = ywdb.selectAnnotationTree(rootAnnotation);

            for (auto annotation : annotations) {

                switch (annotation.tag) {

                case Tag::BEGIN:
                    blockStack.push(annotation);
                    if (firstBlock) {
                        append(annotation.keyword, annotation.value.getValue());
                        firstBlock = false;
                    } else {
                        outline << std::endl;
                        appendOnNewLine(annotation.keyword, annotation.value.getValue());
                    }
                    break;

                case Tag::IN:
                case Tag::PARAM:
                case Tag::OUT:
                case Tag::RETURN:
                    appendOnNewLine(annotation.keyword, annotation.value.getValue());
                    break;

                case Tag::AS:
                case Tag::DESC:
                    if (qualifiersOnSameLine) {
                        appendOnSameLine(annotation.keyword, annotation.value.getValue());
                    } else {
                        appendOnNewLine(annotation.keyword, annotation.value.getValue(), qualifierIndentSize);
                    }
                    break;

                case Tag::END:
                    if (lastAnnotationTag == Tag::END) outline << std::endl;
                    appendOnNewLine(
                        annotation.keyword, 
                        annotation.value.hasValue() ? annotation.value.getValue() : blockStack.top().value.getValue()
                    );
                    blockStack.pop();
                    break;

                default:
                    throw std::runtime_error("unrecognized tag");
                }

                lastAnnotationTag = annotation.tag;
            }

            outline << std::endl;

            return outline.str();
        }
    }
}