#include "yw_db.h"

namespace yw_db {

    YesWorkflowDB::YesWorkflowDB() {
        createInMemoryDatabase();
        createTables();
    }

    YesWorkflowDB::~YesWorkflowDB() {
        sqlite3_close(db);
    }

    void YesWorkflowDB::createInMemoryDatabase() {
        int rc = sqlite3_open(":memory:", &db);
    }


    void YesWorkflowDB::createTables() {
        char* err_msg = 0;
        int rc = sqlite3_exec(db, create_tables_sql.c_str(), 0, 0, &err_msg);
    }
}