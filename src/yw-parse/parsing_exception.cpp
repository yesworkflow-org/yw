#include "parsing_exception.h"
#include <sstream>

namespace yw {
    namespace parse {

        ParsingException::ParsingException(
            const nullable_string& source,
            const std::string& what
        ) : std::runtime_error(what), source(source)
        {
            updateMessage();
        }

        const char* ParsingException::what() const {
            return getMessage().c_str();
        };

        const std::string& ParsingException::getMessage() const {
            return messageBacking;
        }

        void ParsingException::setSource(std::string annotationSource) {
            source = annotationSource;
            updateMessage();
        }

        nullable_string ParsingException::getSource() const {
            return source;
        }

        void ParsingException::updateMessage() {
            std::stringstream ss;
            ss << "A problem occurred parsing YW annotations";
            if (source.hasValue()) {
                ss << " in source " << source.getValue();
            }
            ss << ".";
            messageBacking = ss.str();
        }
    }
}

