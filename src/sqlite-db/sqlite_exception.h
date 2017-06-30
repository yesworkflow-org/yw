#pragma once

#include "sqlite_db.h"

#include <memory>
#include <string>

namespace yw {
    namespace sqlite {

        class SQLiteException : public std::runtime_error {

        public:
            SQLiteException(const std::string& message);
            virtual std::string getMessage() const;
            virtual std::string getDetails() const;

        private:
            std::string details;
        };
    }
}
