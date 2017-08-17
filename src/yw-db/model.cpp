#include "yw_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createModelTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE model(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    user            INTEGER         NULL            REFERENCES user(id),
                    extraction      INTEGER         NULL            REFERENCES extraction(id),
                    created         TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const Model& model) {
            string sql = "INSERT INTO model(id, user, extraction, created) VALUES (?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, model.id);
            statement.bindNullableId(2, model.userId);
            statement.bindNullableId(3, model.extractionId);
            statement.bindText(4, model.created);
            statement.execute();
            return statement.getGeneratedId();
        }

        Model YesWorkflowDB::selectModelById(const row_id& requested_id) {
            string sql = "SELECT id, user, extraction, created FROM model WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No model row with that id");
            auto id = statement.getNullableIdField(0);
            auto userId = statement.getNullableIdField(1);
            auto extractionId = statement.getNullableIdField(2);
            auto created = statement.getTextField(3);
            return Model(id, userId, extractionId, created);
        }
    }
}