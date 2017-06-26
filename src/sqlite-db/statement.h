#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class Statement {

        public:

            Statement(SQLiteDB& connection, std::string sql);
            virtual ~Statement();

        protected:

            SQLiteDB& db;
            sqlite3_stmt* statement;
        };
    }
}