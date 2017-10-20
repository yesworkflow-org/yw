#include "yw_graph_cli.h"
#include "yw_parsing_exception.h"
#include "model_builder.h"
#include "workflow_grapher.h"
#include "ywdb.h"
#include "configuration.h"
#include "graphviz_renderer.h"
#include "yw_io.h"

#include <iostream>

using namespace yw::cli;
using namespace yw::config;
using namespace yw::db;
using namespace yw::graph;

using namespace yw::model;

namespace yw {
    namespace graph {

        int cli(const CommandLine& commandLine)
        {
            YesWorkflowDB ywdb;
            Configuration configuration;

            configuration.insert(Setting{ "extract.sources", null_string, "List of source files to extract annotations from" });
            configuration.insert(Setting{ "yw.config", "yw.properties", "Name of local YW configuration file" });
            configuration.insert(Setting{ "graph.file", null_string, "Name of workflow graph image file to write" });
            configuration.insert(Setting{ "graph.format", "DOT", "Format of workflow graph image file to write", { "DOT", "SVG" } });

			if (commandLine.hasFlag("-h") || commandLine.hasFlag("--help")) {
				printUsage();
                configuration.insertAll(WorkflowGrapher{ ywdb }.getSettings());
                configuration.insertAll(DotBuilder{}.getSoftwareSettings());
                std::cerr << std::endl;
                std::cerr << trimmargins(R"(

                    Setting                    Values (* indicates default)
                    -------------              ----------------------------
                )");
        
                std::cerr << configuration.str(Setting::Visibility::BASIC);
				return 0;
			}

            configuration.insertAll(commandLine.getSettings());

            auto localConfigFile = configuration.getValueText("yw.config");
            configuration.insertSettingsFromFile(localConfigFile, Setting::SettingSource::LOCAL_FILE, false);
    
            if (!commandLine.getCommand().hasValue()) {
                std::cerr << std::endl;
                std::cerr << "ERROR: Command must be first non-option argument to YesWorkflow" << std::endl;
                printUsage();
                return 0;
            }

            auto command = commandLine.getCommand().getValue();
            if (command != "graph") {
                std::cerr << "ERROR: Only the graph command is supported." << std::endl;
                printUsage();
                return 0;
            }

            std::vector<std::string> filesToExtract;
            if (commandLine.getArguments().size() > 0) {
                filesToExtract = commandLine.getArguments();
            } else {
                filesToExtract = configuration.getValueVector("extract.sources");
            }

            if (filesToExtract.size() == 0) {
                std::cerr << std::endl;
                std::cerr << "ERROR: No source files given as arguments." << std::endl;
                printUsage();
                return 0;
            }
   
            yw::row_id modelId;
            try {
                modelId = ModelBuilder{ ywdb }.buildModelFromFiles(filesToExtract);
            }
            catch (yw::parse::YWParsingException& error) {
                std::cerr << "ERROR: There was a problem parsing the YW annotations in the source files." << std::endl;
                std::cerr << "CAUSE: " << error.getMessage() << std::endl;
                return 0;
            }
            catch (...) {

            }

            std::string dotText;
            WorkflowGrapher grapher{ ywdb, configuration };
            try {
                dotText = grapher.graph(modelId);
            }
            catch (std::exception e) {
                std::cerr << "Error graphing model. " << e.what() << std::endl;
                return 0;
            }

            std::string graphFormatSetting = configuration.getValueText("graph.format");
            std::string graphText;
            if (graphFormatSetting == "DOT") {
                graphText = dotText;
            } else if (graphFormatSetting == "SVG") {
                yw::graphviz::GraphvizRenderer renderer{ dotText, "dot", "svg" };
                graphText = renderer.str();
            }

            nullable_string graphFileSetting = configuration.getSetting("graph.file").valueText;
            if (graphFileSetting.hasValue()) {
                std::ofstream graphFile{ graphFileSetting.getValue() };
                graphFile << graphText;
                graphFile.close();
            }
            else {
                std::cout << graphText;
            }

            return 0;
        }

        std::string usage = trimmargins(R"(

            USAGE: yw <command> [source files] [options]
            
            Command                    Function
            -------                    --------
            graph                      Graphically renders workflow model of script.
            
            Option                     Description
            ------                     -----------
            -h, --help                 Displays detailed help including available 
                                         configuration options.
            <setting>=<value>          Assigns value to configuration setting.

        )");

        void printUsage() {
            std::cerr << std::endl;
            std::cerr << usage;
        }
    }
}

