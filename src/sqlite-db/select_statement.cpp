#include "select_statement.h"

#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        SelectStatement::SelectStatement(std::shared_ptr<SQLiteDB> connection, const string& sql) :
            BindableStatement(connection, sql)
        {}

        int SelectStatement::step() {
            int rc = sqlite3_step(statement);
            return rc;
        }

        int SelectStatement::getSingleRow() {
            int rc = sqlite3_step(statement); 
            if (rc != SQLITE_ROW) throw std::runtime_error("No row with that id");
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

		NullableString SelectStatement::getNullableTextField(int column) {
			auto value = sqlite3_column_text(statement, column);
			return NullableString{ reinterpret_cast<const char *>(value) };
		}
	}
}