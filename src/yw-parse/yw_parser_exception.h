#pragma once

#include <memory>
#include <string>

namespace yw {
    namespace parse {

        class YWParserException : public std::runtime_error {

        public:
            
            YWParserException::YWParserException(
                const std::string& message, 
                const std::string& text
            );
            
            virtual std::string getMessage() const;
            virtual std::string getText() const;

        private:
            std::string text;
        };
    }
}
