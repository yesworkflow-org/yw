#include "yesworkflow_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using namespace yw::sqlite;
using std::string;

namespace yw {
    namespace db {

		void YesWorkflowDB::createLineTable() {
			SQLiteDB::createTable(db, std::string(R"(

				CREATE TABLE line(
					id                  INTEGER         NOT NULL        PRIMARY KEY,
					file                FILE            NOT NULL		REFERENCES file(id),
					number				INTEGER			NOT NULL,
					text				TEXT			NULL
				);

			)"));
		}

		long YesWorkflowDB::insert(const LineRow& line) {
            string sql = "INSERT INTO line(file, number, text) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
			statement.bindInt64(1, line.file);
			statement.bindInt64(2, line.number);
			statement.bindText(3, line.text);
			statement.execute();
            return statement.getGeneratedId();
        }

        LineRow YesWorkflowDB::selectLineById(long requested_id) {
            string sql = "SELECT id, file, number, text FROM line WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto file = statement.getInt64Field(1);
			auto number = statement.getInt64Field(2);
			auto text = statement.getTextField(3);
			return LineRow(id, file, number, text);
        }
    }
}