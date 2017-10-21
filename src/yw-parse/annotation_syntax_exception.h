#pragma once

#include "parsing_exception.h"

namespace yw {
    namespace parse {

        class AnnotationSyntaxException : public ParsingException {

        public:

            const int column;
            const int line;

            AnnotationSyntaxException(
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::AnnotationSyntaxException>"
            );

        protected:

            virtual void updateMessage();
        };
    }
}
