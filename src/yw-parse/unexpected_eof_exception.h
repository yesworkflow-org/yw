#pragma once

#include "parsing_exception.h"

namespace yw {
    namespace parse {

        class UnexpectedEndOfFileException : public ParsingException {

        public:

            UnexpectedEndOfFileException(
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::UnexpectedEndOfFileException>"
            );

        protected:

            virtual void updateMessage();
        };
    }
}
