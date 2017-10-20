#include "unexpected_token_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        UnexpectedTokenException::UnexpectedTokenException(
            int line,
            int column,
            const std::string& token
        ) : AnnotationSyntaxException("Unexpected token found during parsing.", line, column), token(token)
        {
            std::stringstream ss;
            ss << "An unexpected token " << token
               << " was encountered on line " << line
               << " at column " << column << ".";
            message = ss.str();
        }
    }
}

