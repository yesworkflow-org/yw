#pragma once

#include "sqlite_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        SQLiteException::SQLiteException(const string& message) : 
            message(message) {}
        
        SQLiteException::~SQLiteException() {}
        
        string SQLiteException::getMessage() { 
            return message; 
        }
        
        string SQLiteException::what() { 
            return "SQLite exception: " + getMessage(); 
        }
    }
}

