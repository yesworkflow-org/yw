#pragma once

#include "statement_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        StatementException::StatementException(const string& message, const string& sql) :
            SQLiteException(message), sql(sql) {}

        string StatementException::what() { 
            return "SQLite statement exception: " + getMessage(); 
        }
        
        string StatementException::getSql() { 
            return sql; 
        }
    }
}

