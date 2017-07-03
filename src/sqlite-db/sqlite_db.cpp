#include "sqlite_db.h"
#include <stdexcept>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        SQLiteDB::SQLiteDB() {
            int rc = sqlite3_open(":memory:", &connection);
            if (rc != SQLITE_OK) throw std::runtime_error("Error creating sqlite database");
            sqlite3_db_config(connection, SQLITE_DBCONFIG_ENABLE_FKEY, 1, NULL);
        }

        SQLiteDB::~SQLiteDB() {
            sqlite3_close(connection);
        }

        string SQLiteDB::getLastErrorMessage() {
            return string(sqlite3_errmsg(connection));
        }

        void SQLiteDB::execute(std::string sql) {
            char* err_msg = 0;
            int rc = sqlite3_exec(connection, sql.c_str(), 0, 0, &err_msg);
        }
    }
}

