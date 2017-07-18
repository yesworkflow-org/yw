#include "yw_parser_builder.h"

namespace yw {
    namespace parse {

        using std::make_unique;
        using std::make_shared;
        using std::string;
        using std::stringstream;

        using antlr4::ANTLRInputStream;
        using antlr4::CommonTokenStream;

        YWParserBuilder::YWParserBuilder(const string& text) {
            text_stream = make_unique<stringstream>(text);
            antlr_input_stream = make_unique<ANTLRInputStream>(*text_stream);
            yw_lexer = make_unique<YWLexer>(antlr_input_stream.get());
            antlr_token_stream = make_unique<CommonTokenStream>(yw_lexer.get());
            yw_parser = make_shared<YWParser>(antlr_token_stream.get());
        }
    }
}