#include "misplaced_port_child_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        MisplacedPortChildException::MisplacedPortChildException(
            const std::string& token,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : UnexpectedAnnotationException(token, column, line, source, what)
        {
            updateMessage();
            setDetails("Each " + std::string(token) + " annotation must follow and qualify a port (@in, @out or @param) annotation.");
        }

        void MisplacedPortChildException::updateMessage() {
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

