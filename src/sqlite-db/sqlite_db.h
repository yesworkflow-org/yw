#pragma once

#include "sqlite3.h"

#include <string>

namespace yw_db {

    class SQLiteDB {

        friend class SQLiteStatement;

    public:

        SQLiteDB();
        ~SQLiteDB();

        void execute(std::string sql);
        std::string getLastErrorMessage();

        static std::string textToString(const unsigned char* text) {
            return std::string((const char*)text);
        }

    private:

        sqlite3* connection;
    };
}