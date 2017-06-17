#pragma once
#include <string>
#include "sqlite3.h"

namespace yw_db {

    class YesWorkflowDB {
    public:

        YesWorkflowDB();
        ~YesWorkflowDB();

    private:

        static const std::string create_tables_sql;
        sqlite3* db;

        void createInMemoryDatabase();
        void createTables();
    };
}