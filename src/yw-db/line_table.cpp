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
					source              INTEGER         NOT NULL		REFERENCES source(id),
					number				INTEGER			NOT NULL,
					text				TEXT			NULL
				);

			)"));
		}

		long YesWorkflowDB::insert(const LineRow& line) {
            string sql = "INSERT INTO line(id, source, number, text) VALUES (?,?,?,?);";
            InsertStatement statement(db, sql);
			statement.bindNullableId(1, line.id);
			statement.bindId(2, line.sourceId);
			statement.bindInt64(3, line.number);
			statement.bindText(4, line.text);
			statement.execute();
            return statement.getGeneratedId();
        }

        LineRow YesWorkflowDB::selectLineById(long requested_id) {
            string sql = "SELECT id, source, number, text FROM line WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto sourceId = statement.getInt64Field(1);
			auto number = statement.getInt64Field(2);
			auto text = statement.getTextField(3);
			return LineRow(id, sourceId, number, text);
        }
    }
}