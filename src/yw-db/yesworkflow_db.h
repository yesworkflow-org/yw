#pragma once

#include "sqlite_db.h"
#include "sqlite_statement.h"
#include "source_row.h"
#include "user_row.h"

namespace yw_db {

    class YesWorkflowDB {
    public:

        YesWorkflowDB();

        long insertUser(const std::string& name);
        //UserRow selectUserById(long id);

        long insertSource(const std::string& path);
        SourceRow selectSourceById(long id);

    private:

        static const std::string create_tables_sql;

        SQLiteDB db;

        void createTables();
    };
}