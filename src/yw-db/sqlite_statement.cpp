#include "sqlite_statement.h"

using std::string;

namespace yw_db {

    SQLiteStatement::SQLiteStatement(sqlite3* db, string sql) {
        sqlite3_prepare_v2(db, sql.c_str(), -1, &sqlite3_statement, 0);
    }

    SQLiteStatement::~SQLiteStatement() {
        sqlite3_finalize(sqlite3_statement);
    }

    void SQLiteStatement::bindInt64(int column, long value) {
        sqlite3_bind_int64(sqlite3_statement, column, (sqlite3_int64)value);
    }

    void SQLiteStatement::bindText(int column, const string& text) {
        sqlite3_bind_text(sqlite3_statement, column, text.c_str(), -1, 0);
    }

    int SQLiteStatement::step() {
        return sqlite3_step(sqlite3_statement);
    }

    long SQLiteStatement::getInt64Field(int column) {
        auto value = sqlite3_column_int64(sqlite3_statement, 0);
        return static_cast<long>(value);
    }

    std::string SQLiteStatement::getTextField(int column) {
        auto value = sqlite3_column_text(sqlite3_statement, 1);
        return sqlite::textToString(value);
    }
}