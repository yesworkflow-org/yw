#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SelectStatement : public BindableStatement {

        public:

            SelectStatement(std::shared_ptr<SQLiteDB> connection, const std::string& sql);

            int step();
            int getSingleRow();

            long getInt64Field(int column);
			nullable_long getNullableInt64Field(int column);
			long getIdField(int column);
			nullable_id getNullableIdField(int column);
			std::string getTextField(int column);
			nullable_string getNullableTextField(int column);
		};
    }
}