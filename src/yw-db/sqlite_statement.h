#pragma once

#include "sqlite.h"

#include <memory>
#include <string>

namespace yw_db {

    class SQLiteStatement {
    
    public:

        SQLiteStatement(sqlite3* db, std::string sql);
        ~SQLiteStatement();

        void bindInt64(int column, long value);
        void bindText(int column, const std::string& text);

        long getInt64Field(int column);
        std::string getTextField(int column);

        int step();

    private:
        
        sqlite3_stmt* sqlite3_statement;

    };

}