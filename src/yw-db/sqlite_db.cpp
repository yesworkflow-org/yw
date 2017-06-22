#pragma once

#include "sqlite_db.h"

#include <string>

namespace yw_db {

    SQLiteDB::SQLiteDB() {
        sqlite3_open(":memory:", &db);
    }

    SQLiteDB::~SQLiteDB() {
        sqlite3_close(db);
    }

    void SQLiteDB::execute(std::string sql) {
        char* err_msg = 0;
        int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
    }
}