#pragma once

#include "YWParser.h"
#include "YWLexer.h"

namespace yw_parse_tests
{
    class ParserBuilder
    {
        std::stringstream* text_stream;
        antlr4::ANTLRInputStream* antlr_input_stream;
        YWLexer* yw_lexer;
        antlr4::CommonTokenStream* antlr_token_stream;
        YWParser* yw_parser;

    public:
        ParserBuilder(const char * text);
        ~ParserBuilder();
        YWParser* parser() { return yw_parser; }
    };
}