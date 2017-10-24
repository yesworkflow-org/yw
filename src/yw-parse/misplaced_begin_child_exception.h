#pragma once

#include "unexpected_token_exception.h"

#include <string>

namespace yw {
    namespace parse {

        class MisplacedBeginChildException : public UnexpectedTokenException {

        public:
            
            MisplacedBeginChildException(
                const std::string& token,
                int column,
                int line,
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::MisplacedBeginChildException>"
            );

        protected:

            virtual void updateMessage();

        };
    }
}
