#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
	namespace db {

		void YesWorkflowDB::createUserTable() {
			SQLiteDB::createTable(db, std::string(R"(

				CREATE TABLE user(
					id                  INTEGER         NOT NULL        PRIMARY KEY,
					name                TEXT            NULL
				);

			)"));
		}

        long YesWorkflowDB::insert(const UserRow& user) {
            string sql = "INSERT INTO user(id, name) VALUES (?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, user.id);
			statement.bindNullableText(2, user.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        UserRow YesWorkflowDB::selectUserById(long requested_id) {
            string sql = "SELECT id, name FROM user WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto name = statement.getNullableTextField(1);
            return UserRow(id, name);
        }
    }
}