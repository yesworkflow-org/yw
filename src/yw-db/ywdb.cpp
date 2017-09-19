#include "ywdb.h"

using namespace yw::sqlite;

using std::string;

namespace yw {
    namespace db {

        YesWorkflowDB::YesWorkflowDB(bool createTables) {
            db = std::make_shared<SQLiteDB>();
            if (createTables) {
                createAllTables();
            }
        }

        void YesWorkflowDB::createAllTables() {
            createUserTable();
            createExtractionTable();
            createFileTable();
            createSourceTable();
            createLineTable();
            createAnnotationTable();
            createModelTable();
            createProgramBlockTable();
            createPortTable();
            createDataBlockTable();
            createFlowTable();
            createFlowTemplateTable();
            createWorkflowPortView();
        }

        size_t YesWorkflowDB::getRowCount(const std::string& tableName) {
            return SQLiteDB::getRowCount(db, tableName);
        }
    }
}