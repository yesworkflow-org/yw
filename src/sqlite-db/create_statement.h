#pragma once

#include "bindable_statement.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class CreateStatement : public BindableStatement {

        public:
            
            CreateStatement(std::shared_ptr<SQLiteDB> connection, const std::string& sql);

            void execute();
        };
    }
}