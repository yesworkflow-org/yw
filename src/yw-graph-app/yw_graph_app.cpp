#include "command_line.h"
#include "model_builder.h"
#include "workflow_grapher.h"
#include "ywdb.h"
#include "yw_config.h"

#include <iostream>

using namespace yw::config;
using namespace yw::graph;
using namespace yw::model;

void print_help_and_exit();

int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    yw::cli::CommandLine commandLine{argc, argv};

    if (!commandLine.getCommand().hasValue()) {
        std::cerr << "Error:  No command given." << std::endl;
        print_help_and_exit();
    }

    auto command = commandLine.getCommand().getValue();
    if (command != "graph") {
        std::cerr << "Error: Only the 'graph' command is supported." << std::endl;
        print_help_and_exit();
    }

    auto filesToExtract = commandLine.getArguments();
    if (filesToExtract.size() == 0) {
        std::cerr << "Error: No file names given as arguments." << std::endl;
        print_help_and_exit();
    }

    Configuration configuration;
    configuration.insertAll(commandLine.getSettings());

    try {
        ModelBuilder{ ywdb }.buildModelFromFiles(filesToExtract);
    }
    catch (std::exception e) {
        std::cerr << "Error extracting annotations. " << e.what() << std::endl;
        exit(-1);
    }

    WorkflowGrapher grapher{ ywdb };
    try {
        std::cout << grapher.graph(1,"Workflow");
    }
    catch (std::exception e) {
        std::cerr << "Error exporting outline. " << e.what() << std::endl;
        exit(-1);
    }
}

void print_help_and_exit() {
    std::cout << "Usage:  yw-graph-app graph <path-to-script>" << std::endl;
    exit(0);
}

