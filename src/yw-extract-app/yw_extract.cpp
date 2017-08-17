#include "ywdb.h"
#include "outline_exporter.h"
#include "annotation_extractor.h"

#include <iostream>

using namespace yw::db;
using namespace yw::sqlite;
using namespace yw::extract;
using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    if (argc != 2) {
        cout << "Usage:  yw-extract <path-to-script>" << endl;
        exit(0);
    }

    try {
        AnnotationExtractor{ ywdb }.extractAnnotationsFromFile(argv[1]);
        cout << OutlineExporter{ ywdb }.getOutline();
    }
    catch (std::runtime_error e) {
        cerr << "ERROR: " << e.what() << endl;
        exit(-1);
    }
}

