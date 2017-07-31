#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SelectStatement : public BindableStatement {

        public:

            SelectStatement(
				std::shared_ptr<SQLiteDB> connection, 
				const std::string& sql
			) : BindableStatement(connection, sql)
			{}

            int step();
            int getSingleRow();

            long getInt64Field(int column) const;
			nullable_long getNullableInt64Field(int column) const;
			long getIdField(int column) const;
			nullable_row_id getNullableIdField(int column) const;
			std::string getTextField(int column) const;
			nullable_string getNullableTextField(int column) const;
		};
    }
}