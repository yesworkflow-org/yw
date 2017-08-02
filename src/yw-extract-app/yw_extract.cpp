#include "yw_db.h"
#include "outline_exporter.h"
#include "annotation_extractor.h"

#include <iostream>

using namespace yw::db;
using namespace yw::sqlite;
using namespace yw::extract;


int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    if (argc != 2) {
        std::cout << "Usage:  yw-extract <path-to-script>" << std::endl;
        exit(0);
    }

    AnnotationExtractor extractor{ ywdb };
    try {
        extractor.extractAnnotationsFromFile(argv[1]);
    }
    catch (std::runtime_error e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        exit(-1);
    }
    OutlineExporter exporter{ ywdb };
    std::cout << exporter.getOutline();
}

