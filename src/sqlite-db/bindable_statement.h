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

            void bindInt64(int column, long value);
            void bindText(int column, const std::string& text);
			void bindNullableText(int column, const NullableString& text);

		private:

			std::shared_ptr<std::string> cache(const std::string& original);
        };
    }
}