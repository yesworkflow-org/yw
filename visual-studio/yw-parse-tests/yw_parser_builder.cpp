#include "stdafx.h"
#include <sstream>

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"

#include "yw_parser_builder.h"

namespace yw_parse_tests
{
    YWParserBuilder::YWParserBuilder(const char * text) {
        text_stream = new std::stringstream(text);
        antlr_input_stream = new antlr4::ANTLRInputStream(*text_stream);
        yw_lexer = new YWLexer(antlr_input_stream);
        antlr_token_stream = new antlr4::CommonTokenStream(yw_lexer);
        yw_parser = new YWParser(antlr_token_stream);
    }

    YWParserBuilder::~YWParserBuilder() {
        delete yw_parser;
        delete antlr_token_stream;
        delete yw_lexer;
        delete antlr_input_stream;
        delete text_stream;
    }
}