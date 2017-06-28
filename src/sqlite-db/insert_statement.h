#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class InsertStatement : public BindableStatement {

        public:
            
            InsertStatement(SQLiteDB& connection, const std::string& sql);

            int execute();
            long getGeneratedId();
        };
    }
}