#include "annotation_syntax_exception.h"

using std::string;

namespace yw {
    namespace parse {

        AnnotationSyntaxException::AnnotationSyntaxException(
            const string& message, 
            int line, 
            int column
        ) : YWParsingException(message), line(line), column(column)
        {
        }
    }
}

