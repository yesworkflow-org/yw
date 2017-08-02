#include "yw_db.h"
#include "source_loader.h"
#include "yw_parser_builder.h"
#include "outline_exporter.h"
#include "annotation_listener.h"

#include <iostream>

using namespace yw::db;
using namespace yw::sqlite;


int main(int argc, char** argv)
{
    yw::db::YesWorkflowDB ywdb;

    if (argc != 2) {
        std::cout << "Usage:  yw-extract <path-to-script>" << std::endl;
        exit(0);
    }

    yw::extract::SourceLoader loader{ ywdb };

    auto fileName = std::string{ argv[1] };
    std::cout << "Extracting annotations from: " << fileName << std::endl;

    auto sourceId = ywdb.insert(SourceRow{ auto_id, null_id, null_string });

    std::string sourceText;
    try {
        sourceText = loader.loadFromFile(sourceId, fileName);
    }
    catch (std::exception e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    yw::parse::YWParserBuilder parser_builder(sourceText);
    auto userId = ywdb.insert(UserRow{ auto_id, "user1" });
    auto extractionId = ywdb.insert(ExtractionRow{ auto_id, userId, "2017-06-22 10:52:00.000" });
    yw::extract::AnnotationListener listener{ ywdb, extractionId, sourceId };
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());

    yw::extract::OutlineExporter exporter{ ywdb };
    auto outline = exporter.getOutline();
    std::cout << outline;
}

