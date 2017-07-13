#include "select_statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        BindableStatement::BindableStatement(std::shared_ptr<SQLiteDB> connection, const string& sql) :
            Statement(connection, sql)
        {}

        void BindableStatement::bindInt64(int column, long value) {
            sqlite3_bind_int64(statement, column, (sqlite3_int64)value);
        }

        void BindableStatement::bindText(int column, const string& text) {
            sqlite3_bind_text(statement, column, cache(text)->c_str(), -1, 0);
        }

		void BindableStatement::bindNullableText(int column, const NullableString& text) {
			if (!text.null()) {
				bindText(column, text.value());
			}
		}

		std::shared_ptr<std::string> BindableStatement::cache(const string& original) {
			auto copy = std::make_shared<string>(original);
			stringCache.push_back(copy);
			return copy;
		}
	}
}