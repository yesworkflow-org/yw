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
					model               INTEGER         NOT NULL        REFERENCES model(id),
					language            INTEGER         NOT NULL        REFERENCES language(id),
					file                INTEGER         NULL            REFERENCES file(id)
				);

			)"));
		}

        long YesWorkflowDB::insert(const SourceRow& source) {
            string sql = "INSERT INTO source(model, language, file) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindInt64(1, source.modelId);
            statement.bindInt64(2, source.languageId);
            statement.bindInt64(3, source.fileId);
            statement.execute();
            return statement.getGeneratedId();
        }

        SourceRow YesWorkflowDB::selectSourceById(long requested_id) {
            string sql = "SELECT id, model, language, file FROM source WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindInt64(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No row with that id");
            auto id = statement.getInt64Field(0);
            auto modelId = statement.getInt64Field(1);
            auto fileId = statement.getInt64Field(2);
            auto languageId = statement.getInt64Field(3);
            return SourceRow(id, modelId, languageId, fileId);
        }
    }
}