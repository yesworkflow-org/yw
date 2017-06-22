#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw_db {

    class SQLiteStatement {
    
    public:

        SQLiteStatement(SQLiteDB& db, std::string sql);
        ~SQLiteStatement();

        void bindInt64(int column, long value);
        void bindText(int column, const std::string& text);

        long getInt64Field(int column);
        std::string getTextField(int column);

        long getGeneratedId();

        int step();

    private:
        
        SQLiteDB& db;
        sqlite3_stmt* sqlite3_statement;
    };

}