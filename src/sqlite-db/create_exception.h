#pragma once

#include "sqlite_db.h"
#include "statement_exception.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class CreateException : public StatementException {

        public:

            CreateException(
                const std::string& message,
                const std::string& sql
            ) : StatementException(message, sql)
            {}

            virtual std::string getMessage() const override;
        };
    }
}

