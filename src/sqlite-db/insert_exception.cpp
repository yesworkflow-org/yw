#include "insert_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        string InsertException::getMessage() const {
            return "Error inserting row into table: " + string(what());
        }
    }
}

