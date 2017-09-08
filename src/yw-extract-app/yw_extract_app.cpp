#include "ywdb.h"
#include "outline_exporter.h"
#include "annotation_extractor.h"
#include "yw_config.h"
#include "command_line.h"

#include <iostream>

using namespace yw::extract;
using namespace yw::config;

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
    if (command != "outline") {
        std::cerr << "Error: Only the 'outline' command is supported." << std::endl;
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
        AnnotationExtractor{ ywdb }.extractAnnotationsFromFiles(filesToExtract);
    }
    catch (std::exception e) {
        std::cerr << "Error extracting annotations. " << e.what() << std::endl;
        exit(-1);
    }

    try {
        std::cout << OutlineExporter{ ywdb, configuration }.getOutline();
    }
    catch (std::exception e) {
        std::cerr << "Error exporting outline. " << e.what() << std::endl;
        exit(-1);
    }
}

void print_help_and_exit() {
    std::cout << "Usage:  yw-extract-app outline <path-to-script>" << std::endl;
    exit(0);
}

