#include "misplaced_begin_child_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        MisplacedBeginChildException::MisplacedBeginChildException(
            const std::string& token,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : UnexpectedTokenException(token, column, line, source, what)
        {
            updateMessage();
        }

        void MisplacedBeginChildException::updateMessage() {
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

