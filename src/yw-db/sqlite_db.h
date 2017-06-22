#pragma once

#include "sqlite3.h"

#include <string>

namespace yw_db {

    class SQLiteDB {

        friend class SQLiteStatement;

    public:

        SQLiteDB();
        ~SQLiteDB();

        void SQLiteDB::execute(std::string sql);

        static std::string textToString(const unsigned char* text) {
            return std::string((const char*)text);
        }

    private:

        sqlite3* db;
    };
}