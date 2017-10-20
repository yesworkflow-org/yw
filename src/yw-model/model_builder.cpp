#include "model_builder.h"
#include "model_entity_listener.h"
#include "source_loader.h"
#include "yw_parser_builder.h"
#include "yw_parsing_exception.h"
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

        row_id ModelBuilder::buildModelFromString(
            const string& sourceText
        ) {
            auto sourceId = ywdb.insert(Source{ auto_id, null_id, null_string });
            extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            SourceLoader{ ywdb }.insertSourceLinesFromString(sourceId, sourceText);
            buildModelFromString(sourceId, sourceText);
            return modelId;
        }

        row_id ModelBuilder::buildModelFromFile(
            const string& filePath
        ) {
            currentFilePath = filePath;
            extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            auto fileName = getFileName(filePath);
            auto fileId = ywdb.insert(File{ auto_id, fileName });
            auto sourceId = ywdb.insert(Source{ auto_id, fileId, null_string });
            string sourceText = SourceLoader{ ywdb }.insertSourceLinesFromFile(sourceId, filePath);
            buildModelFromString(sourceId, sourceText);
            return modelId;
        }

        row_id ModelBuilder::buildModelFromFiles(
            const std::vector<string>& filePaths
        ) {
            extractionId = ywdb.insert(Extraction{ auto_id, null_id, "" });
            modelId = ywdb.insert(Model{ auto_id, null_id, extractionId, "" });
            for (const auto& filePath : filePaths) {
                buildModelFromFile(filePath);
            }
            return modelId;
        }

        void ModelBuilder::buildModelFromString(
            const row_id& sourceId,
            const string& sourceText
        ) {
            YWParserBuilder parser(sourceText);
            ModelEntityListener listener{ ywdb, modelId, extractionId, sourceId };
            try {
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser.parse()->script());
            }
            catch (YWParsingException& e) {
                if (currentFilePath.hasValue()) {
                    e.setSource(currentFilePath.getValue());
                }
                throw;
            }
        }
    }
}