#pragma once

#include "yw_cli_parser_builder.h"
#include "configuration.h"

namespace yw {
    namespace cli {

        class CommandLine
        {
            std::string line;
            nullable_string program;
            std::set<std::string> flags;
            nullable_string command;
            std::vector<std::string> arguments;
            yw::config::Configuration settings;
            
        public:
            CommandLine(std::string line);
            CommandLine(int argc, char** argv);

            std::string getLine() const { return line; }
            nullable_string getProgram() const { return program; }
            std::set<std::string> getFlags() const { return flags; }
			bool hasFlag(std::string flag) const;
            nullable_string getCommand() const { return command; };
            std::vector<std::string> getArguments() const { return arguments; }
            yw::config::Configuration getSettings() const { return settings; }

            static std::string concatenate(int argc, char** argv);
        };
    }
}