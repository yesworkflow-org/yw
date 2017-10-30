#pragma once

#include "annotation_syntax_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class InvalidArgumentException : public AnnotationSyntaxException {

        public:
            
            const std::string annotation;
            const std::string argument;
            const std::string value;

            InvalidArgumentException(
                const std::string& annotation,
                const std::string& argument,
                const std::string& value,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::InvalidArgumentException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
