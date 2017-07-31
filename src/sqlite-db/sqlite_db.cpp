#include "sqlite_db.h"
#include <stdexcept>
#include <string>
#include "create_statement.h"
#include "select_statement.h"

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

        void SQLiteDB::execute(const std::string& sql) {
            char* err_msg = 0;
            int rc = sqlite3_exec(connection, sql.c_str(), 0, 0, &err_msg);
        }

        void SQLiteDB::createTable(std::shared_ptr<SQLiteDB> connection, const string& sql) {
            CreateStatement statement(connection, sql);
            statement.execute();
        }

        size_t SQLiteDB::getRowCount(std::shared_ptr<SQLiteDB> connection, const std::string& tableName) {
            string sql = "SELECT COUNT(id) FROM " + tableName;
            SelectStatement statement(connection, sql);
            statement.step();
            return statement.getInt64Field(0);
        }
    }

}

