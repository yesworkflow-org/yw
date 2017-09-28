#include "yw_graph_cli.h"
#include "model_builder.h"
#include "workflow_grapher.h"
#include "ywdb.h"
#include "yw_config.h"

#ifdef USE_GRAPHVIZ_LIB
#include "graphviz_renderer.h"
#endif

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

            configuration.insert(SoftwareSetting{ "graph.file", null_string, "Name of workflow graph image file to write" });
            #ifdef USE_GRAPHVIZ_LIB
                configuration.insert(SoftwareSetting{ "graph.format", "DOT", "Format of workflow graph image file to write",{ "DOT", "SVG" } });
            #else
                configuration.insert(SoftwareSetting{ "graph.format", "DOT", "Format of workflow graph image file",{ "DOT" } });
            #endif

                configuration.insertAll(commandLine.getSettings());

            if (!commandLine.getCommand().hasValue()) {
                std::cerr << "Error: No command given." << std::endl;
                print_help();
                return 0;
            }

            auto command = commandLine.getCommand().getValue();
            if (command != "graph") {
                std::cerr << "Error: Only the 'graph' command is supported." << std::endl;
                print_help();
                return 0;
            }

            auto filesToExtract = commandLine.getArguments();
            if (filesToExtract.size() == 0) {
                std::cerr << "Error: No file names given as arguments." << std::endl;
                print_help();
                return 0;
            }


            yw::row_id modelId;
            try {
                modelId = ModelBuilder{ ywdb }.buildModelFromFiles(filesToExtract);
            }
            catch (std::exception e) {
                std::cerr << "Error extracting annotations. " << e.what() << std::endl;
                return 0;
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

            std::string graphFormatSetting = configuration.getStringValue("graph.format");
            std::string graphText;
            if (graphFormatSetting == "DOT") {
                graphText = dotText;
            } else if (graphFormatSetting == "SVG") {
                #ifdef USE_GRAPHVIZ_LIB
                yw::graphviz::GraphvizRenderer renderer{ dotText, "dot", "svg" };
                graphText = renderer.str();
                #endif
            }

            nullable_string graphFileSetting = configuration.getSetting("graph.file").value;
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

        void print_help() {
            std::cout << "Usage: yw graph <path-to-script>" << std::endl;
        }
    }
}

