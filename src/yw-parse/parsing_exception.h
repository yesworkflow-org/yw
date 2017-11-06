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
            
            virtual const char* what() const noexcept override;
            virtual nullable_string getDetails() const;
            virtual const std::string& getMessage() const;
            virtual nullable_string getSource() const;
            virtual void setDetails(std::string details);
            virtual void setSource(std::string annotationSource);

        protected:

            virtual void updateMessage();

            std::string messageBacking;

        private:

            nullable_string details;
            nullable_string source;
        };
    }
}
