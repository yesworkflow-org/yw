#pragma once

#include "create_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        CreateException::CreateException(string message, string sql) :
            StatementException(message, sql) {}

        string CreateException::getMessage() const {
            return "Error creating table: " + string(what());
        }
    }
}

