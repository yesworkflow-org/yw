#include "insert_statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        InsertStatement::InsertStatement(SQLiteDB& connection, const std::string& sql) :
            BindableStatement(connection, sql)
        {}

        int InsertStatement::execute() {
            int rc = sqlite3_step(statement);
            return rc;
        }

        long InsertStatement::getGeneratedId() {
            return static_cast<long>(sqlite3_last_insert_rowid(db.getConnection()));
        }
    }
}