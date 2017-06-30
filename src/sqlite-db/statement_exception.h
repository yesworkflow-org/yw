#pragma once

#include "sqlite_exception.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class StatementException : public SQLiteException {
        public:
            StatementException(const std::string& message, const std::string& sql);
            virtual std::string getSql() const;
            virtual std::string getMessage() const override;
        private:
            std::string sql;
        };
    }
}

