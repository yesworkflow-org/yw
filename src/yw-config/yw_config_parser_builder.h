#pragma once

#include "antlr4-runtime.h"
#include "YW_CONFIG_Parser.h"
#include "YW_CONFIG_Lexer.h"

#include <memory>
#include <string>

namespace yw {
    namespace config {

        class YW_CONFIG_ParserBuilder {

        private:
            std::unique_ptr<std::stringstream> text_stream;
            std::unique_ptr<antlr4::ANTLRInputStream> antlr_input_stream;
            std::unique_ptr<YW_CONFIG_Lexer> yw_lexer;
            std::unique_ptr<antlr4::CommonTokenStream> antlr_token_stream;
            std::shared_ptr<YW_CONFIG_Parser> yw_config_parser;

        public:
            YW_CONFIG_ParserBuilder(const std::string& text);
            std::shared_ptr<YW_CONFIG_Parser> parse() { return yw_config_parser; }
        };
    }
}