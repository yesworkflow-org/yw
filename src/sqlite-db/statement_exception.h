#pragma once

#include "sqlite_exception.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class StatementException : public SQLiteException {
        public:
            StatementException(const std::string& message, const std::string& sql);
            virtual std::string getSql();
            virtual std::string what();
        private:
            std::string sql;
        };
    }
}

