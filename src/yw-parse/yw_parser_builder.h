#pragma once

#include "antlr4-runtime.h"
#include "YWParser.h"
#include "YWLexer.h"
#include "yw_parser_error_listener.h"

namespace yw {
    namespace parse {

        class YWParserBuilder
        {
            std::unique_ptr<std::stringstream> text_stream;
            std::unique_ptr<antlr4::ANTLRInputStream> antlr_input_stream;
            std::unique_ptr<YWLexer> yw_lexer;
            std::unique_ptr<antlr4::CommonTokenStream> antlr_token_stream;
            std::shared_ptr<YWParser> yw_cli_parser;
            std::shared_ptr<YWParserErrorListener> errorListener;

        public:
            YWParserBuilder(const std::string& text, bool useCustomErrorListener = false);
            std::shared_ptr<YWParser> parse() { return yw_cli_parser; }
        };
    }
}