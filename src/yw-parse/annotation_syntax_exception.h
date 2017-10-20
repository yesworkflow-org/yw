#pragma once

#include "yw_parsing_exception.h"

namespace yw {
    namespace parse {

        class AnnotationSyntaxException : public YWParsingException {

        public:

            const int line;
            const int column;

            AnnotationSyntaxException(
                const std::string& message, 
                int line,
                int column
            );
        };
    }
}
