#include "create_statement.h"

using std::string;

namespace yw {
    namespace sqlite {

        CreateStatement::CreateStatement(SQLiteDB& connection, std::string sql) :
            BindableStatement(connection, sql)
        {}

        int CreateStatement::execute() {
            int rc = sqlite3_step(statement);
            return rc;
        }
    }
}