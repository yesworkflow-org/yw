#include "statement.h"
#include "preparation_exception.h"

using std::string;

namespace yw {
    namespace sqlite {

        Statement::Statement(std::shared_ptr<SQLiteDB> db, const string& sql) 
			: db(db), sql(sql) 
		{
            int rc = sqlite3_prepare_v2(db->getConnection(), sql.c_str(), -1, &statement, 0);
            if (rc != SQLITE_OK) {
				string lastErrorMessage = db->getLastErrorMessage();
                throw(PreparationException(lastErrorMessage, sql));
            }
        }

        Statement::~Statement() {
            sqlite3_finalize(statement);
        }
    }
}