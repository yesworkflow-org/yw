#include "unexpected_eof_exception.h"

using std::string;

namespace yw {
    namespace parse {

        UnexpectedEndOfFileException::UnexpectedEndOfFileException(
            const nullable_string& source,
            const std::string& what
        ) : ParsingException(source, what)
        {
            updateMessage();
        }

        void UnexpectedEndOfFileException::updateMessage() {
            auto source = getSource();
            std::stringstream ss;
            ss << "The end of the file was reached unexpectedly while parsing annotations";
            if (source.hasValue()) {
                ss << " in source file '" << source.getValue() << "'";
            }
            ss << ".";
            messageBacking = ss.str();
        }
    }
}

