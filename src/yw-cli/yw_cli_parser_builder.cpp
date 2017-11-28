#include "yw_cli_parser_builder.h"

namespace yw {
    namespace cli {

        using std::make_unique;
        using std::make_shared;
        using std::string;
        using std::stringstream;

        using antlr4::ANTLRInputStream;
        using antlr4::CommonTokenStream;

        YW_CLI_ParserBuilder::YW_CLI_ParserBuilder(const string& text, bool useCustomErrorListener) {
            text_stream = make_unique<stringstream>(text);
            antlr_input_stream = make_unique<ANTLRInputStream>(*text_stream);
            yw_lexer = make_unique<YW_CLI_Lexer>(antlr_input_stream.get());
            antlr_token_stream = make_unique<CommonTokenStream>(yw_lexer.get());
            yw_cli_parser = make_shared<YW_CLI_Parser>(antlr_token_stream.get());
            if (useCustomErrorListener) {
                yw_cli_parser->removeErrorListeners();
                errorListener = make_shared<YWCliParserErrorListener>();
                yw_cli_parser->addErrorListener(errorListener.get());
            }
        }
    }
}