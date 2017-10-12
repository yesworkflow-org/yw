#include "command_line.h"

using namespace yw::config;
using SettingSource = yw::config::Setting::SettingSource;

namespace yw {
    namespace cli {

        CommandLine::CommandLine(int argc, char** argv) :
            CommandLine(concatenate(argc, argv)) {}

        CommandLine::CommandLine(std::string line) : line(line) {

            YW_CLI_ParserBuilder parser_builder(line);
            YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();

            program = context->program()->getText();

            for (auto flag : context->pflag()) {
                flags.insert(flag->getText());
            }

            if (context->command() != nullptr) {
                command = context->command()->getText();
            }

            for (auto argument : context->argument()) {
                arguments.push_back(argument->getText());
            }

            for (auto config : context->config()) {
                auto key = config->configName()->getText();
                nullable_string valueText = (config->configValue() == nullptr) ?
                    null_string : config->configValue()->unquotedValue()->getText();
                settings.insert(Setting{ key, valueText, SettingSource::COMMAND_LINE });
            }
        }

		bool CommandLine::hasFlag(std::string flag) const {
			return flags.find(flag) != flags.end();
		}

        std::string CommandLine::concatenate(int argc, char** argv) {
            std::stringstream ss;
            for (int i = 0; i < argc; ++i) {
                if (i > 0) ss << " ";
                ss << argv[i];
            }
            return ss.str();
        }
    }
}