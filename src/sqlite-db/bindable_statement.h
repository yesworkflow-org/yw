#pragma once

#include "statement.h"

#include <memory>
#include <string>
#include <vector>

namespace yw {
    namespace sqlite {

        class BindableStatement : public Statement {

			std::vector<std::shared_ptr<std::string>> stringCache;
		
		public:

            BindableStatement(std::shared_ptr<SQLiteDB> connection, const std::string& sql);

			void bindId(int column, long id);
			void bindNullableId(int column, nullable_row_id id);
            void bindInt64(int column, long value);
			void bindNullableInt64(int column, nullable_long value);
			void bindText(int column, const std::string& text);
			void bindNullableText(int column, const nullable_string& text);

		private:

			std::shared_ptr<std::string> cache(const std::string& original);
        };
    }
}