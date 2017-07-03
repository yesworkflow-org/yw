#include "preparation_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        PreparationException::PreparationException(string message, string sql) :
            StatementException(message, sql) {}

        string PreparationException::getMessage() const {
            return "Error preparing statement: " + string(what());
        }
    }
}

