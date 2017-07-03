#include "statement_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        StatementException::StatementException(const string& message, const string& sql) :
            SQLiteException(message), sql(sql) {}

        string StatementException::getMessage() const {
            return "SQLite statement exception: " + string(what());
        }
        
        string StatementException::getSql() const { 
            return sql; 
        }
    }
}

