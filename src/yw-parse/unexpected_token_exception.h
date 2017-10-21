#pragma once

#include "annotation_syntax_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class UnexpectedTokenException : public AnnotationSyntaxException {

        public:
            
            const std::string token;

            UnexpectedTokenException(
                const std::string& token,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::UnexpectedTokenException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
