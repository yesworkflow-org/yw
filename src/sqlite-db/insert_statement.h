#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class InsertStatement : public BindableStatement {

        public:

            InsertStatement(
                std::shared_ptr<SQLiteDB> connection,
                const std::string& sql
            ) : BindableStatement(connection, sql)
            {}

            void execute();
            row_id getGeneratedId();
        };
    }
}