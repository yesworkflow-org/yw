#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SQLiteStatement {

        public:

            SQLiteStatement(SQLiteDB& connection, std::string sql);
            ~SQLiteStatement();

            void bindInt64(int column, long value);
            void bindText(int column, const std::string& text);

            long getInt64Field(int column);
            std::string getTextField(int column);

            long getGeneratedId();

            int step();

        private:

            SQLiteDB& db;
            sqlite3_stmt* statement;
        };
    }
}