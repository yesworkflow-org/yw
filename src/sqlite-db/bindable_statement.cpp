#include "select_statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        BindableStatement::BindableStatement(SQLiteDB& connection, std::string sql) :
            Statement(connection, sql)
        {}

        void BindableStatement::bindInt64(int column, long value) {
            sqlite3_bind_int64(statement, column, (sqlite3_int64)value);
        }

        void BindableStatement::bindText(int column, const string& text) {
            sqlite3_bind_text(statement, column, text.c_str(), -1, 0);
        }
    }
}