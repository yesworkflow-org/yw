#pragma once

#include "sqlite3.h"
#include "sqlite_log.h"

#include <string>

namespace yw {
    namespace sqlite {

        class SQLiteDB {

        public:

            SQLiteDB();
            ~SQLiteDB();

            void execute(std::string sql);
            std::string getLastErrorMessage();

            static std::string textToString(const unsigned char* text) {
                return std::string((const char*)text);
            }

            sqlite3* getConnection() { return connection; }

        private:

            SQLiteLog log;
            sqlite3* connection;
        };
    }
}
