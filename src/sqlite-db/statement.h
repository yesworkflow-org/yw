#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class Statement {

        public:

            Statement(std::shared_ptr<SQLiteDB> connection, const std::string& sql);
            virtual ~Statement();

        protected:

            std::shared_ptr<SQLiteDB> db;
            std::string sql;
            sqlite3_stmt* statement;
        };
    }
}