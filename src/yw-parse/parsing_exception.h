#pragma once

#include "nullable.h"

#include <string>

namespace yw {
    namespace parse {

        class ParsingException : public std::runtime_error {

        public:
            
            ParsingException(
                const nullable_string& source = null_string,
                const std::string& what = "<sliced instance of yw::parse::ParsingException>"
            );
            
            virtual const char* what() const override;
            virtual const std::string& getMessage() const;
            virtual nullable_string getSource() const;
            virtual void setSource(std::string annotationSource);

        protected:

            virtual void updateMessage();

        private:

            nullable_string source;
            std::string messageBacking;

        };
    }
}
