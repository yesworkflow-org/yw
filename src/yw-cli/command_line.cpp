#include "command_line.h"
#include "yw_cli_parsing_exception.h"

using namespace yw::config;
using SettingSource = yw::config::Setting::SettingSource;

namespace yw {
    namespace cli {

        nullable_string safelyGetProgramNameFromCommandLineContext(YW_CLI_Parser::CommandLineContext *commandLine) {
            YW_CLI_Parser::ProgramContext* program;
            nullable_string programText;
            if (commandLine == nullptr ||
                (program = commandLine->program()) == nullptr ||
                (programText = program->getText()) == null_string ||
                programText.getValue() == "<missing WORD>" ||
                programText.getValue().empty()
                ) {
                programText = null_string;
            }
            return programText;
        }

        std::string safelyGetConfigNameFromConfigContext(YW_CLI_Parser::ConfigContext *config) {
            YW_CLI_Parser::ConfigNameContext* configName;
            std::string configNameText;
            if ( config == nullptr ||
                 (configName = config->configName()) == nullptr ||
                 (configNameText = configName->getText()) == "<missing WORD>" ||
                 configNameText.empty()
                ) {
                throw YW_CLI_ParsingException{ "Configuration name missing following -c flag on command line." };
            }
            return configNameText;
        }

        nullable_string safelyGetConfigValueFromConfigContext(YW_CLI_Parser::ConfigContext *config) {
            YW_CLI_Parser::ConfigValueContext* configValue;
            YW_CLI_Parser::UnquotedValueContext* unquotedValue;
            nullable_string unquotedConfigValueText;
            if (config == nullptr ||
                (configValue = config->configValue()) == nullptr ||
                (unquotedValue = configValue->unquotedValue()) == nullptr ||
                (unquotedConfigValueText = unquotedValue->getText()) == null_string ||
                unquotedConfigValueText.getValue() == "<missing WORD>" ||
                unquotedConfigValueText.getValue().empty()
                ) {
                unquotedConfigValueText = null_string;
            }
            return unquotedConfigValueText;
        }

        CommandLine::CommandLine(int argc, char** argv) :
            CommandLine(concatenate(argc, argv)) {}

        CommandLine::CommandLine(std::string line) : line(line) {

            YW_CLI_ParserBuilder parser_builder(line, true);
            YW_CLI_Parser::CommandLineContext* context = parser_builder.parse()->commandLine();

            program = safelyGetProgramNameFromCommandLineContext(context);

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
                auto name = safelyGetConfigNameFromConfigContext(config);
                auto value = safelyGetConfigValueFromConfigContext(config);
                settings.insert(Setting{ name, value, SettingSource::COMMAND_LINE });
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