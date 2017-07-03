#include "insert_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        InsertException::InsertException(string message, string sql) :
            StatementException(message, sql) {}

        string InsertException::getMessage() const {
            return "Error inserting row into table: " + string(what());
        }
    }
}

