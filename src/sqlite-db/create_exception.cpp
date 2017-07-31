#include "create_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        string CreateException::getMessage() const {
            return "Error creating table: " + string(what());
        }
    }
}

