#include "yesworkflow_db.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

		YesWorkflowDB::YesWorkflowDB(bool createTables) {
			db = std::make_shared<SQLiteDB>();
			if (createTables) {
				createAllTables();
			}
        }

        void YesWorkflowDB::createAllTables() {
			createUserTable();
			createModelTable();
			createFileTable();
			createLanguageTable();
			createSourceTable();
			createLineTable();
			createAnnotationTable();
        }
    }
}