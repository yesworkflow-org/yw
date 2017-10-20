#include "unexpected_token_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        UnexpectedTokenException::UnexpectedTokenException(
            const std::string& token,
            int line,
            int column,
            const nullable_string& source,
            const std::string& what
        ) : AnnotationSyntaxException(line, column, source, what), token(token)
        {
            //std::stringstream ss;
            //ss << "An unexpected token " << token
            //   << " was encountered on line " << line
            //   << " at column " << column << ".";
            //message = ss.str();
        }
    }
}

