#pragma once

#include "annotation_syntax_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class UnexpectedTokenException : public AnnotationSyntaxException {

        public:
            
            const std::string token;

            UnexpectedTokenException::UnexpectedTokenException(
                int line,
                int column,
                const std::string& token
            );
        };
    }
}
