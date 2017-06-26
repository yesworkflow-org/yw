#include "statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        Statement::Statement(SQLiteDB& db, string sql) : db(db) {
            int rc = sqlite3_prepare_v2(db.getConnection(), sql.c_str(), -1, &statement, 0);
            if (rc != SQLITE_OK) {
                string message(db.getLastErrorMessage());
                throw std::runtime_error("Error creating statement: " + message);
            }
        }

        Statement::~Statement() {
            sqlite3_finalize(statement);
        }
    }
}