#include "model_builder.h"
#include "model_entity_listener.h"
#include "source_loader.h"
#include "yw_parser_builder.h"
#include "yw_io.h"

using namespace yw::db;
using namespace yw::extract;
using namespace yw::model;
using namespace yw::parse;
using namespace yw::sqlite;

using std::istringstream;
using std::string;

namespace yw {
    namespace model {

        void ModelBuilder::buildModelFromString(
            const string& sourceText
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            auto modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            auto sourceId = ywdb.insert(Source{ auto_id, null_id, null_string });
            SourceLoader{ ywdb }.insertSourceLinesFromString(sourceId, sourceText);
            buildModelFromString(modelId, extractionId, sourceId, sourceText);
        }

        void ModelBuilder::buildModelFromFile(
            const string& filePath
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            auto modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            buildModelFromFile(modelId, extractionId, filePath);
        }

        void ModelBuilder::buildModelFromFiles(
            const std::vector<string>& filePaths
        ) {
            auto extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            auto modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            for (const auto& filePath : filePaths) {
                buildModelFromFile(modelId, extractionId, filePath);
            }
        }

        void ModelBuilder::buildModelFromString(
            const row_id& modelId,
            const row_id& extractionId,
            const row_id& sourceId,
            const string& sourceText
        ) {
            YWParserBuilder parser(sourceText);
            ModelEntityListener listener{ ywdb, modelId, extractionId, sourceId };
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser.parse()->script());
        }

        void ModelBuilder::buildModelFromFile(
            const row_id& modelId,
            const row_id& extractionId,
            const string& filePath
        ) {
            auto fileName = getFileName(filePath);
            auto fileId = ywdb.insert(File{ auto_id, fileName });
            auto sourceId = ywdb.insert(Source{ auto_id, fileId, null_string });
            string sourceText = SourceLoader{ ywdb }.insertSourceLinesFromFile(sourceId, filePath);
            buildModelFromString(modelId, extractionId, sourceId, sourceText);
        }
    }
}