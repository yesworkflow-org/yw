#pragma once
#include <memory>
#include <string>
#include "sqlite3.h"

namespace yw_db {

    class YesWorkflowDB {
    public:

        YesWorkflowDB();
        ~YesWorkflowDB();

        sqlite3_int64 insertSource(const std::string& path);
        std::string selectSourceById(long id);

    private:

        static const std::string create_tables_sql;
        sqlite3* db;

        void createInMemoryDatabase();
        void createTables();
    };
}