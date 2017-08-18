#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createDataBlockTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE data_block(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    structure       INTEGER         NULL            REFERENCES data_block(id),
                    name            TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(const DataBlock& dataBlock) {
            string sql = "INSERT INTO data_block(id, structure, name) VALUES (?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, dataBlock.id);
            statement.bindNullableId(2, dataBlock.structureId);
            statement.bindText(3, dataBlock.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        DataBlock YesWorkflowDB::selectDataBlockById(const row_id& requested_id) {
            string sql = "SELECT id, structure, name FROM data_block WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No data block with that id");
            auto id = statement.getNullableIdField(0);
            auto structureId = statement.getNullableIdField(1);
            auto name = statement.getTextField(2);
            return DataBlock(id, structureId, name);
        }
    }
}