#include "annotation_syntax_exception.h"

using std::string;

namespace yw {
    namespace parse {

        AnnotationSyntaxException::AnnotationSyntaxException(
            int line,
            int column,
            const nullable_string& source,
            const std::string& what
        ) : ParsingException(source, what), line(line), column(column)
        {
        }
    }
}

