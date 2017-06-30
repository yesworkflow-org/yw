#pragma once

#include "sqlite_db.h"
#include "statement_exception.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class InsertException : public StatementException {
        public:
            InsertException(std::string message, std::string sql);
            virtual std::string getMessage() const override;
        };
    }
}

