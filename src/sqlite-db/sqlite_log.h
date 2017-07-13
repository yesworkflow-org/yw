#pragma once

#include "sqlite3.h"

#include <string>

namespace yw {
    namespace sqlite {

        class SQLiteLog {
        public:
            SQLiteLog();
            void clear();
        };

        void errorLogCallback(void *pArg, int iErrCode, const char *zMsg);
        std::string getLastLogMessage();
    }
}