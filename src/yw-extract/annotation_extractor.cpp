#include "annotation_extractor.h"
#include "annotation_listener.h"
#include "source_loader.h"
#include "yw_parser_builder.h"

using namespace yw::db;
using namespace yw::extract;
using namespace yw::sqlite;
using namespace yw::parse;

using std::istringstream;
using std::string;

namespace yw {
    namespace extract {

        void AnnotationExtractor::extractAnnotationsFromString(const row_id& sourceId, const string& sourceText) {
            YWParserBuilder parser(sourceText);
            auto extractionId = ywdb.insert(ExtractionRow{ auto_id, null_id, "" });
            AnnotationListener listener{ ywdb, extractionId, sourceId };
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser.parse()->script());
        }

        void AnnotationExtractor::extractAnnotationsFromFile(const string& filePath) {
            auto fileId = ywdb.insert(FileRow{ auto_id, filePath });
            auto sourceId = ywdb.insert(SourceRow{ auto_id, fileId, null_string });
            string sourceText = SourceLoader{ ywdb }.insertSourceLinesFromFile(sourceId, filePath);
            extractAnnotationsFromString(sourceId, sourceText);
        }
    }
}