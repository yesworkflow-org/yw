#pragma once

#include "statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class BindableStatement : public Statement {

        public:

            BindableStatement(SQLiteDB& connection, std::string sql);

            void bindInt64(int column, long value);
            void bindText(int column, const std::string& text);
        };
    }
}