#include "yesworkflow_db.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        YesWorkflowDB::YesWorkflowDB() {
            db = std::make_shared<SQLiteDB>();
            createTables();
        }

        void YesWorkflowDB::createTables() {
            db->execute(create_tables_sql);
        }
    }
}