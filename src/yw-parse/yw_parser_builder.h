#pragma once

#include "antlr4-runtime.h"
#include "YWParser.h"
#include "YWLexer.h"

namespace yw {
    namespace parse {

        class YWParserBuilder
        {
            std::unique_ptr<std::stringstream> text_stream;
            std::unique_ptr<antlr4::ANTLRInputStream> antlr_input_stream;
            std::unique_ptr<YWLexer> yw_lexer;
            std::unique_ptr<antlr4::CommonTokenStream> antlr_token_stream;
            std::shared_ptr<YWParser> yw_cli_parser;
        public:
            YWParserBuilder(const std::string& text);
            std::shared_ptr<YWParser> parse() { return yw_cli_parser; }
        };
    }
}