#pragma once

#include "parsing_exception.h"

namespace yw {
    namespace parse {

        class AnnotationSyntaxException : public ParsingException {

        public:

            const int line;
            const int column;

            AnnotationSyntaxException(
                int line,
                int column,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::AnnotationSyntaxException>"
            );

        protected:

            virtual void updateMessage();
        };
    }
}
