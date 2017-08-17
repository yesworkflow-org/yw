#include "yw_db.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createDataTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE data(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    part_of         INTEGER         NULL            REFERENCES data(id),
                    name            TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const DataRow& data) {
            string sql = "INSERT INTO data(id, part_of, name) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, data.id);
            statement.bindNullableId(2, data.partOfId);
            statement.bindText(3, data.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        DataRow YesWorkflowDB::selectDataById(const row_id& requested_id) {
            string sql = "SELECT id, part_of, name FROM data WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No data row with that id");
            auto id = statement.getNullableIdField(0);
            auto partOfId = statement.getNullableIdField(1);
            auto name = statement.getTextField(2);
            return DataRow(id, partOfId, name);
        }
    }
}