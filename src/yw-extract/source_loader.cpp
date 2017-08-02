#include "annotation_listener.h"
#include "source_loader.h"

using namespace yw::sqlite;
using namespace yw::db;

using std::istringstream;
using std::string;

namespace yw {
    namespace extract {

         void SourceLoader::loadFromString(const string& sourceString) {
            auto sourceId = ywdb.insert(SourceRow{ auto_id, null_id, null_string });
            loadFromString(sourceId, sourceString);
        }

        void SourceLoader::loadFromString(const row_id& sourceId, const string& sourceString) {
            istringstream sourceStream{ sourceString };
            string lineText;
            long lineNumber = 0;
            while (std::getline(sourceStream, lineText)) {
                ywdb.insert(LineRow{ auto_id, sourceId, ++lineNumber, lineText });
            }
        }

        string SourceLoader::loadFromFile(const row_id& sourceId, const std::string& filePath) {
            std::stringstream sourceText;
            std::ifstream sourceFile;
            sourceFile.open(filePath);
            if (!sourceFile.is_open()) {
                throw std::runtime_error("Cannot open source file: " + filePath);
            }
            string lineText;
            long lineNumber = 0;
            while (std::getline(sourceFile, lineText)) {
                sourceText << lineText << std::endl;
                ywdb.insert(LineRow{ auto_id, sourceId, ++lineNumber, lineText });
            }
            return sourceText.str();
        }
    }
}