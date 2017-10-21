#include "unexpected_token_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        UnexpectedTokenException::UnexpectedTokenException(
            const std::string& token,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : AnnotationSyntaxException(column, line, source, what), token(token)
        {
            updateMessage();
        }

        void UnexpectedTokenException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "An unexpected token '" << token;
            ss << "' was encountered at column " << column;
            ss << " of line " << line;
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << ".";
            messageBacking = ss.str();
        }
    }
}

