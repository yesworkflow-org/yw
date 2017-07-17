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
			sqlite3_int64 value = sqlite3_column_int64(statement, column);
            return static_cast<long>(value);
        }

		nullable_long SelectStatement::getNullableInt64Field(int column) {
			if (sqlite3_column_type(statement, column) == SQLITE_NULL) return null_long;
			sqlite3_int64 value = sqlite3_column_int64(statement, column);
			return nullable_long(static_cast<long>(value));
		}

		long SelectStatement::getIdField(int column) {
			return getInt64Field(column);
		}

		nullable_row_id SelectStatement::getNullableIdField(int column) {
			if (sqlite3_column_type(statement, column) == SQLITE_NULL) return nullable_row_id{};
			sqlite3_int64 value = sqlite3_column_int64(statement, column);
			return nullable_row_id(static_cast<long>(value));
		}

		std::string SelectStatement::getTextField(int column) {
			const unsigned char* value = sqlite3_column_text(statement, column);
            return SQLiteDB::textToString(value);
        }

		nullable_string SelectStatement::getNullableTextField(int column) {
			if (sqlite3_column_type(statement, column) == SQLITE_NULL) return null_string;
			const unsigned char* value = sqlite3_column_text(statement, column);
			return nullable_string{ reinterpret_cast<const char *>(value) };
		}
	}
}