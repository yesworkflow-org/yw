#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createExtractionTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE extraction(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    user            INTEGER         NOT NULL        REFERENCES user(id),
                    created         TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const ExtractionRow& extraction) {
            string sql = "INSERT INTO extraction(id, user, created) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, extraction.id);
            statement.bindId(2, extraction.userId);
            statement.bindText(3, extraction.created);
            statement.execute();
            return statement.getGeneratedId();
        }

        ExtractionRow YesWorkflowDB::selectExtractionById(const row_id& requested_id) {
            string sql = "SELECT id, user, created FROM extraction WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No extraction row with that id");
            auto id = statement.getNullableIdField(0);
            auto userId = statement.getInt64Field(1);
            auto created = statement.getTextField(2);
            return ExtractionRow(id, userId, created);
        }
    }
}