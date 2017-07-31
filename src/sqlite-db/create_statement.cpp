#include "create_statement.h"
#include "create_exception.h"

using std::string;

namespace yw {
    namespace sqlite {

        void CreateStatement::execute() {
            int rc = sqlite3_step(statement);
            if (rc != SQLITE_DONE) {
                throw CreateException(db->getLastErrorMessage(), sql);
            }
        }
    }
}