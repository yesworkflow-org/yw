#pragma once

#include "yw_cli_parser_builder.h"
#include "yw_config.h"

namespace yw {
    namespace cli {

        class CommandLine
        {
            std::string line;
            std::string program;
            std::vector<std::string> flags;
            nullable_string command;
            std::vector<std::string> arguments;
            yw::config::Configuration settings;
            
        public:
            CommandLine(std::string line);
            CommandLine(int argc, char** argv);

            std::string getLine() { return line; }
            std::string getProgram() { return program; }
            std::vector<std::string> getFlags() { return flags; }
            nullable_string getCommand() { return command; }
            std::vector<std::string> getArguments() { return arguments; }
            yw::config::Configuration getSettings() { return settings; }

            static std::string concatenate(int argc, char** argv);
        };
    }
}