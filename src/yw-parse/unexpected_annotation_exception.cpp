#include "unexpected_annotation_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        UnexpectedAnnotationException::UnexpectedAnnotationException(
            const std::string& token,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : AnnotationSyntaxException(column, line, source, what), token(token)
        {
            updateMessage();
        }

        void UnexpectedAnnotationException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "The '" << token << "' annotation";
            ss << " was unexpected at column " << column;
            ss << " of line " << line;
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << ".";
            messageBacking = ss.str();
        }
    }
}

