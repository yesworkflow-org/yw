#include "ywdb.h"
#include "outline_exporter.h"
#include "annotation_extractor.h"

#include <iostream>

using namespace yw::extract;

int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    if (argc != 2) {
        std::cout << "Usage:  yw-extract <path-to-script>" << std::endl;
        exit(0);
    }

    try {
        AnnotationExtractor{ ywdb }.extractAnnotationsFromFile(argv[1]);
        std::cout << OutlineExporter{ ywdb }.getOutline();
    }
    catch (std::runtime_error e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(-1);
    }
}

