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

        void AnnotationExtractor::extractAnnotationsFromString(
            const string& sourceText
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            auto sourceId = ywdb.insert(Source{ auto_id, null_id, null_string });
            SourceLoader{ ywdb }.insertSourceLinesFromString(sourceId, sourceText);
            extractAnnotationsFromString(extractionId, sourceId, sourceText);
        }

        void AnnotationExtractor::extractAnnotationsFromFile(
            const string& filePath
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            extractAnnotationsFromFile(extractionId, filePath);
        }

        void AnnotationExtractor::extractAnnotationsFromFiles(
            const std::vector<string>& filePaths
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            for (const auto& filePath : filePaths) {
                extractAnnotationsFromFile(extractionId, filePath);
            }
        }

        void AnnotationExtractor::extractAnnotationsFromString(
            const row_id& extractionId,
            const row_id& sourceId,
            const string& sourceText
        ) {
            YWParserBuilder parser(sourceText);
            AnnotationListener listener{ ywdb, extractionId, sourceId };
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser.parse()->script());
        }

        void AnnotationExtractor::extractAnnotationsFromFile(
            const row_id& extractionId,
            const string& filePath
        ) {
            auto fileId = ywdb.insert(File{ auto_id, filePath });
            auto sourceId = ywdb.insert(Source{ auto_id, fileId, null_string });
            string sourceText = SourceLoader{ ywdb }.insertSourceLinesFromFile(sourceId, filePath);
            extractAnnotationsFromString(extractionId, sourceId, sourceText);
        }
    }
}