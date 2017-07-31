#pragma once

#include "sqlite_db.h"
#include "statement_exception.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class PreparationException : public StatementException {
        public:
            PreparationException(
				std::string message, 
				std::string sql
			) : StatementException(message, sql) {}

            virtual std::string getMessage() const override;
        };
    }
}

