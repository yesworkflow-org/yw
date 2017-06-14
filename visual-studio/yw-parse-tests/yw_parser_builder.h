#pragma once

#include "YWParser.h"
#include "YWLexer.h"

namespace yw_parse_tests
{
    class YWParserBuilder
    {
        std::stringstream* text_stream;
        antlr4::ANTLRInputStream* antlr_input_stream;
        YWLexer* yw_lexer;
        antlr4::CommonTokenStream* antlr_token_stream;
        YWParser* yw_parser;

    public:
        YWParserBuilder(const char * text);
        ~YWParserBuilder();
        YWParser* parser() { return yw_parser; }
    };
}