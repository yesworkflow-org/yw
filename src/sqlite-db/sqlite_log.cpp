
#include "sqlite3.h"
#include "sqlite_log.h"

#include <string>

namespace yw {
    namespace sqlite {

        static std::string lastLogMessage;
        static bool isInitialized = false;

        SQLiteLog::SQLiteLog() {
            if (!isInitialized) {
                sqlite3_config(SQLITE_CONFIG_LOG, errorLogCallback, NULL);
                isInitialized = true;
            }
            clear();
        }

        void SQLiteLog::clear() {
            lastLogMessage = "";
        }

        std::string getLastLogMessage() {
            return lastLogMessage;
        }

        void errorLogCallback(void *pArg, int iErrCode, const char *zMsg) {
            lastLogMessage = std::string(zMsg);
        }
    }
}