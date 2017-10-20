#pragma once

#include "nullable.h"

#include <string>

namespace yw {
    namespace parse {

        class YWParsingException : public std::runtime_error {

        public:
            
            YWParsingException::YWParsingException(
                const std::string& message, 
                const nullable_string& source = null_string
            );
            
            virtual std::string getMessage() const;
            virtual nullable_string getSource() const;
            virtual void setSource(std::string annotationSource);

        protected:

            std::string message;
            nullable_string source;
        };
    }
}
