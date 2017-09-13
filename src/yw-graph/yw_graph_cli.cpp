#include "yw_graph_cli.h"
#include "model_builder.h"
#include "workflow_grapher.h"
#include "ywdb.h"
#include "yw_config.h"

#include <iostream>

using namespace yw::cli;
using namespace yw::config;
using namespace yw::db;
using namespace yw::graph;
using namespace yw::model;

namespace yw {
    namespace graph {

        int cli(CommandLine& commandLine)
        {
            YesWorkflowDB ywdb;

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

            Configuration config;
            config.insertAll(commandLine.getSettings());

            yw::row_id modelId;
            try {
                modelId = ModelBuilder{ ywdb }.buildModelFromFiles(filesToExtract);
            }
            catch (std::exception e) {
                std::cerr << "Error extracting annotations. " << e.what() << std::endl;
                return 0;
            }

            WorkflowGrapher grapher{ ywdb, config };
            try {
                std::cout << grapher.graph(modelId);
            }
            catch (std::exception e) {
                std::cerr << "Error graphing model. " << e.what() << std::endl;
                return 0;
            }

            return 0;
        }

        void print_help() {
            std::cout << "Usage: yw graph <path-to-script>" << std::endl;
        }
    }
}

