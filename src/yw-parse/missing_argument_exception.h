#pragma once

#include "annotation_syntax_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class MissingArgumentException : public AnnotationSyntaxException {

        public:
            
            const std::string keyword;
            const std::string argument;

            MissingArgumentException(
                const std::string& keyword,
                const std::string& argument,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::MissingArgumentException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
