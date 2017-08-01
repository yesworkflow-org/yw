#include "annotation_listener.h"
#include "source_loader.h"

using namespace yw::sqlite;
using namespace yw::db;

using std::istringstream;
using std::string;

namespace yw {
    namespace extract {

        void SourceLoader::loadFromString(const string& sourceString) {
            istringstream sourceStream{ sourceString };
            string lineText;
            long lineNumber = 0;
            while (std::getline(sourceStream, lineText)) {
                ywdb.insert(LineRow{ auto_id, sourceId, ++lineNumber, lineText });
            }
        }
    }
}