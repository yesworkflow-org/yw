#include "yw_parser_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace parse {

        YWParserException::YWParserException(const string& message, const string& text) :
            std::runtime_error(message.c_str()), text(text)
        {}

        string YWParserException::getMessage() const {
            return "YW parser exception: " + string(what());
        }

        string YWParserException::getText() const {
            return text;
        }
    }
}

