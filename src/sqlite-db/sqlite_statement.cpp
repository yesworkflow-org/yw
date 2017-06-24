#include "sqlite_statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        SQLiteStatement::SQLiteStatement(SQLiteDB& db, string sql) : db(db) {
            int rc = sqlite3_prepare_v2(db.connection, sql.c_str(), -1, &statement, 0);
            if (rc != SQLITE_OK) {
                string message(db.getLastErrorMessage());
                throw std::runtime_error("Error creating statement: " + message);
            }
        }

        SQLiteStatement::~SQLiteStatement() {
            sqlite3_finalize(statement);
        }

        void SQLiteStatement::bindInt64(int column, long value) {
            sqlite3_bind_int64(statement, column, (sqlite3_int64)value);
        }

        void SQLiteStatement::bindText(int column, const string& text) {
            sqlite3_bind_text(statement, column, text.c_str(), -1, 0);
        }

        int SQLiteStatement::step() {
            int rc = sqlite3_step(statement);
            return rc;
        }

        long SQLiteStatement::getInt64Field(int column) {
            auto value = sqlite3_column_int64(statement, column);
            return static_cast<long>(value);
        }

        std::string SQLiteStatement::getTextField(int column) {
            auto value = sqlite3_column_text(statement, column);
            return SQLiteDB::textToString(value);
        }

        long SQLiteStatement::getGeneratedId() {
            return static_cast<long>(sqlite3_last_insert_rowid(db.connection));
        }
    }
}