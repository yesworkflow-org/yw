#include "misplaced_end_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        MisplacedEndException::MisplacedEndException(
            const std::string& token,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : UnexpectedAnnotationException(token, column, line, source, what)
        {
            updateMessage();
            setDetails("Each " + std::string(token) + " annotation is paired with the closest preceding @begin annotation to delimit a program block.");
        }

        void MisplacedEndException::updateMessage() {
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

