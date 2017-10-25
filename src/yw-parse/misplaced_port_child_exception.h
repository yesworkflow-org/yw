#pragma once

#include "unexpected_annotation_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class MisplacedPortChildException : public UnexpectedAnnotationException {

        public:
            
            MisplacedPortChildException(
                const std::string& token,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::MisplacedPortChildException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
