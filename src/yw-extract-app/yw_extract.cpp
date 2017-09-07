#include "ywdb.h"
#include "outline_exporter.h"
#include "annotation_extractor.h"
#include "yw_config.h"
#include "command_line.h"

#include <iostream>

using namespace yw::extract;
using namespace yw::config;

int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    //if (argc != 2) {
    //    std::cout << "Usage:  yw-extract outline <path-to-script>" << std::endl;
    //    exit(0);
    //}

    yw::cli::CommandLine commandLine{argc, argv};

    Configuration configuration;
    configuration.insertAll(commandLine.getSettings());

    try {
        AnnotationExtractor{ ywdb }.extractAnnotationsFromFile(argv[1]);
    }
    catch (std::runtime_error e) {
        std::cerr << "Error extracting annotations: " << e.what() << std::endl;
        exit(-1);
    }

    try {
        std::cout << OutlineExporter{ ywdb, configuration }.getOutline();
    }
    catch (std::runtime_error e) {
        std::cerr << "Error exporting outline: " << e.what() << std::endl;
        exit(-1);
    }
}

