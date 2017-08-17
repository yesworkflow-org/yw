#include "annotation_listener.h"
#include "source_loader.h"

using namespace yw::sqlite;
using namespace yw::db;

using std::istringstream;
using std::string;

namespace yw {
    namespace extract {

        void SourceLoader::insertSourceLinesFromString(const row_id& sourceId, const string& sourceString) {
            istringstream sourceStream{ sourceString };
            string lineText;
            long lineNumber = 0;
            while (std::getline(sourceStream, lineText)) {
                ywdb.insert(Line{ auto_id, sourceId, ++lineNumber, lineText });
            }
        }

        string SourceLoader::insertSourceLinesFromFile(const row_id& sourceId, const std::string& filePath) {
            std::ostringstream sourceText;
            std::ifstream sourceFile;
            sourceFile.open(filePath);
            if (!sourceFile.is_open()) {
                throw std::runtime_error("Source loader cannot open source file " + filePath);
            }
            string lineText;
            long lineNumber = 0;
            while (std::getline(sourceFile, lineText)) {
                sourceText << lineText << std::endl;
                ywdb.insert(Line{ auto_id, sourceId, ++lineNumber, lineText });
            }
            return sourceText.str();
        }
    }
}