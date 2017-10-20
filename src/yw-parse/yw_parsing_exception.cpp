#include "yw_parsing_exception.h"

namespace yw {
    namespace parse {

        YWParsingException::YWParsingException(
            const std::string& message, 
            const nullable_string& source
        ) : std::runtime_error(message.c_str()), message(message), source(source)
        {
        }

        std::string YWParsingException::getMessage() const {
            return message;
        }

        nullable_string YWParsingException::getSource() const {
            return source;
        }

        void YWParsingException::setSource(std::string annotationSource) {
            source = annotationSource;
        }
    }
}

