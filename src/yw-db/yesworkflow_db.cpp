#include "yesworkflow_db.h"

using std::string;

namespace yw_db {

    YesWorkflowDB::YesWorkflowDB() : db(SQLiteDB()) {
        createTables();
    }

    void YesWorkflowDB::createTables() {
        db.execute(create_tables_sql);
    }
}