#pragma once

#include "nullable.h"

#include <string>

namespace yw {
    namespace cli {

        class YW_CLI_ParsingException : public std::runtime_error {

        public:
            
            YW_CLI_ParsingException(
                const std::string& what
            ) : std::runtime_error(what)
            {}
        };
    }
}
