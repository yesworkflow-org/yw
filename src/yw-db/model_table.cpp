#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

		void YesWorkflowDB::createModelTable() {
			SQLiteDB::createTable(db, std::string(R"(

				CREATE TABLE model(
					id                  INTEGER         NOT NULL        PRIMARY KEY,
					user				INTEGER         NOT NULL        REFERENCES user(id),
					create_date         TEXT            NOT NULL
				);

			)"));
		}

        long YesWorkflowDB::insert(const ModelRow& model) {
            string sql = "INSERT INTO model(id, user, create_date) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, model.id);
			statement.bindId(2, model.userId);
            statement.bindText(3, model.creationDate);
            statement.execute();
            return statement.getGeneratedId();
        }

        ModelRow YesWorkflowDB::selectModelById(long requested_id) {
            string sql = "SELECT id, user, create_date FROM model WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getNullableIdField(0);
            auto userId = statement.getInt64Field(1);
            auto creationDate = statement.getTextField(2);
            return ModelRow(id, userId, creationDate);
        }
    }
}