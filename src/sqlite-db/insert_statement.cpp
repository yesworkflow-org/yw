#include "insert_statement.h"
#include "insert_exception.h"

using std::string;

namespace yw {
    namespace sqlite {

        InsertStatement::InsertStatement(SQLiteDB& connection, const std::string& sql) :
            BindableStatement(connection, sql)
        {}

        void InsertStatement::execute() {
            int rc = sqlite3_step(statement);
            if (rc != SQLITE_DONE) {
                throw InsertException(db.getLastErrorMessage(), sql);
            }
        }

        long InsertStatement::getGeneratedId() {
            return static_cast<long>(sqlite3_last_insert_rowid(db.getConnection()));
        }
    }
}