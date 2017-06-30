#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SelectStatement : public BindableStatement {

        public:

            SelectStatement(SQLiteDB& connection, const std::string& sql);

            int step();
            int getSingleRow();

            long getInt64Field(int column);
            std::string getTextField(int column);
        };
    }
}