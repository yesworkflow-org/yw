#pragma once

#include "sqlite.h"
#include "sqlite_statement.h"
#include "source_table.h"

namespace yw_db {

    class YesWorkflowDB {
    public:

        YesWorkflowDB();
        ~YesWorkflowDB();

        sqlite3_int64 insertSource(const std::string& path);
        SourceRow selectSourceById(long id);

    private:

        static const std::string create_tables_sql;
        sqlite3* db;

        void createInMemoryDatabase();
        void createTables();
    };
}