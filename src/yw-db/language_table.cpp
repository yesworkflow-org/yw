#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

		void YesWorkflowDB::createLanguageTable() {
			SQLiteDB::createTable(db, std::string(R"(

				CREATE TABLE language(
					id                  INTEGER         NOT NULL        PRIMARY KEY,
					name                TEXT            NOT NULL
				);

			)"));
		}

        long YesWorkflowDB::insert(const LanguageRow& language) {
            string sql = "INSERT INTO language(id, name) VALUES (?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, language.id);
			statement.bindText(2, language.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        LanguageRow YesWorkflowDB::selectLanguageById(long requested_id) {
            string sql = "SELECT id, name FROM language WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getNullableIdField(0);
            auto name = statement.getTextField(1);
            return LanguageRow(id, name);
        }
    }
}