#include "yw_cli_parser_error_listener.h"

namespace yw {
    namespace cli {

        void YWCliParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
            const std::string &msg, std::exception_ptr e_ptr)
        {
        }
    }
}