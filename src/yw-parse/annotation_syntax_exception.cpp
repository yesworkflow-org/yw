#include "annotation_syntax_exception.h"

using std::string;

namespace yw {
    namespace parse {

        AnnotationSyntaxException::AnnotationSyntaxException(
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : ParsingException(source, what), column(column), line(line)
        {
            updateMessage();
        }

        void AnnotationSyntaxException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "An annotation syntax error was encountered at column " << column;
            ss << " of line " << line;
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << ".";
            messageBacking = ss.str();
        }
    }
}

