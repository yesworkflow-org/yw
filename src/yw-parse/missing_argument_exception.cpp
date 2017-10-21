#include "missing_argument_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        MissingArgumentException::MissingArgumentException(
            const std::string& keyword,
            const std::string& argument,
            int column,
            int line,
            const nullable_string& source,
            const std::string& what
        ) : AnnotationSyntaxException(column, line, source, what), keyword(keyword), argument(argument)
        {
            updateMessage();
        }

        void MissingArgumentException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "The annotation '" << keyword;
            ss << "' at column " << column;
            ss << " of line " << line;
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << " is missing the required " << argument << " argument.";

            messageBacking = ss.str();
        }
    }
}

