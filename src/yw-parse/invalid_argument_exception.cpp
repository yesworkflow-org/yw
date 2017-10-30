#include "invalid_argument_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        InvalidArgumentException::InvalidArgumentException(
            const std::string& annotation,
            const std::string& argument,
            const std::string& value,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : AnnotationSyntaxException(column, line, source, what), 
            annotation(annotation), argument(argument), value(value)
        {
            updateMessage();
        }

        void InvalidArgumentException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "The " << annotation << " annotation";
            ss << " at column " << column;
            ss << " of line " << line;
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << " has an invalid " << argument << " argument ";
            ss << " with value '" << value << "'.";

            messageBacking = ss.str();
        }
    }
}

