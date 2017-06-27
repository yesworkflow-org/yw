#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SQLiteException {
        public:
            SQLiteException(const std::string& message);
            virtual ~SQLiteException();
            virtual std::string getMessage();
            virtual std::string what();
        private:
            std::string message;
        };
    }
}

