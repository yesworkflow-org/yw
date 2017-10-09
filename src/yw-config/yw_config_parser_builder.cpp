#include "yw_config_parser_builder.h"

namespace yw {
    namespace config {

        using std::make_unique;
        using std::make_shared;
        using std::string;
        using std::stringstream;

        using antlr4::ANTLRInputStream;
        using antlr4::CommonTokenStream;

        YW_CONFIG_ParserBuilder::YW_CONFIG_ParserBuilder(const string& text) {
            text_stream = make_unique<stringstream>(text);
            antlr_input_stream = make_unique<ANTLRInputStream>(*text_stream);
            yw_lexer = make_unique<YW_CONFIG_Lexer>(antlr_input_stream.get());
            antlr_token_stream = make_unique<CommonTokenStream>(yw_lexer.get());
            yw_config_parser = make_shared<YW_CONFIG_Parser>(antlr_token_stream.get());
        }
    }
}