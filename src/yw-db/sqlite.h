#pragma once

#include "sqlite3.h"

#include <string>

namespace yw_db {

    class sqlite {

    public:

        sqlite() = delete;
        
        static std::string textToString(const unsigned char* text) {
            return std::string((const char*)text);
        }
    };
}