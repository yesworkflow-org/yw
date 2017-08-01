#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createSourceTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE source(
                    id                  INTEGER         NOT NULL        PRIMARY KEY,
                    file                INTEGER         NULL            REFERENCES file(id),
                    language            TEXT            NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const SourceRow& source) {
            string sql = "INSERT INTO source(id, file, language) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, source.id);
            statement.bindNullableId(2, source.fileId);
            statement.bindNullableText(3, source.language);
            statement.execute();
            return statement.getGeneratedId();
        }

        SourceRow YesWorkflowDB::selectSourceById(const row_id& requested_id) {
            string sql = "SELECT id, file, language FROM source WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No source row with that id");
            auto id = statement.getNullableIdField(0);
            auto fileId = statement.getNullableIdField(1);
            auto language = statement.getNullableTextField(2);
            return SourceRow(id, fileId, language);
        }
    }
}