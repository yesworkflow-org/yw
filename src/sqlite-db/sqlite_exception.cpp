#pragma once

#include "sqlite_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        SQLiteException::SQLiteException(const string& message) : 
            std::runtime_error(message.c_str()),
            details(yw::sqlite::getLastLogMessage().c_str())
        {}

        string SQLiteException::getMessage() const { 
            return "SQLite error message: " + string(what());
        }

        string SQLiteException::getDetails() const {
            return details;
        }
    }
}

