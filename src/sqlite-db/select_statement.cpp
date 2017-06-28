#include "select_statement.h"

#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        SelectStatement::SelectStatement(SQLiteDB& connection, const string& sql) :
            BindableStatement(connection, sql)
        {}

        int SelectStatement::step() {
            int rc = sqlite3_step(statement);
            return rc;
        }

        long SelectStatement::getInt64Field(int column) {
            auto value = sqlite3_column_int64(statement, column);
            return static_cast<long>(value);
        }

        std::string SelectStatement::getTextField(int column) {
            auto value = sqlite3_column_text(statement, column);
            return SQLiteDB::textToString(value);
        }
    }
}