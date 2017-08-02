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
            YWParserBuilder parser_builder(sourceText);
            auto userId = ywdb.insert(UserRow{ auto_id, "user1" });
            auto extractionId = ywdb.insert(ExtractionRow{ auto_id, userId, "2017-06-22 10:52:00.000" });
            AnnotationListener listener{ ywdb, extractionId, sourceId };
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());
        }

        void AnnotationExtractor::extractAnnotationsFromFile(const string& filePath) {
            auto fileId = ywdb.insert(FileRow{ auto_id, filePath });
            auto sourceId = ywdb.insert(SourceRow{ auto_id, fileId, null_string });
            string sourceText = (SourceLoader{ ywdb }).insertSourceLinesFromFile(sourceId, filePath);
            extractAnnotationsFromString(sourceId, sourceText);
        }
    }
}