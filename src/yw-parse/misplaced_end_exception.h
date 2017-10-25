#pragma once

#include "unexpected_annotation_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class MisplacedEndException : public UnexpectedAnnotationException {

        public:
            
            MisplacedEndException(
                const std::string& token,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::MisplacedEndException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
