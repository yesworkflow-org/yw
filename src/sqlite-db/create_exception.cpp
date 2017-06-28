#pragma once

#include "create_exception.h"

#include <memory>
#include <string>

using std::string;

namespace yw {
    namespace sqlite {

        CreateException::CreateException(string message, string sql) :
            StatementException(message, sql) {}

        string CreateException::what() { 
            return "Error creating table: " + getMessage(); 
        }
    }
}

