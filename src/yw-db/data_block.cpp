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
                    model           INTEGER         NOT NULL        REFERENCES model(id),
                    workflow        INTEGER         NULL            REFERENCES program_block(id),
                    structure       INTEGER         NULL            REFERENCES data_block(id),
                    name            TEXT            NOT NULL
                );

            )"));
        }

        row_id YesWorkflowDB::insert(DataBlock& dataBlock) {
            dataBlock.id = insert(static_cast<const DataBlock&>(dataBlock));
            return dataBlock.id.getValue();
        }

        row_id YesWorkflowDB::insert(const DataBlock& dataBlock) {
            string sql = "INSERT INTO data_block(id, model, workflow, structure, name) VALUES (?,?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, dataBlock.id);
            statement.bindId(2, dataBlock.modelId);
            statement.bindNullableId(3, dataBlock.workflowId);
            statement.bindNullableId(4, dataBlock.structureId);
            statement.bindText(5, dataBlock.name);
            statement.execute();
            return statement.getGeneratedId();
        }

        DataBlock getDataBlockFromSelectStatementFields(SelectStatement& statement) {
            auto id = statement.getNullableIdField(0);
            auto modelId = statement.getIdField(1);
            auto workflowId = statement.getNullableIdField(2);
            auto structureId = statement.getNullableIdField(3);
            auto name = statement.getTextField(4);
            return DataBlock(id, modelId, workflowId, structureId, name);
        }

        DataBlock YesWorkflowDB::selectDataBlockById(const row_id& requested_id) {
            string sql = "SELECT id, model, workflow, structure, name FROM data_block WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No data block with that id");
            return getDataBlockFromSelectStatementFields(statement);
        }

        std::vector<DataBlock> YesWorkflowDB::selectDataBlocksByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT id, model, workflow, structure, name 
                FROM data_block 
                WHERE workflow = ?
                ORDER BY name, id
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto dataBlocks = std::vector<DataBlock>{};
            while (statement.step() == SQLITE_ROW) {
                dataBlocks.push_back(getDataBlockFromSelectStatementFields(statement));
            }
            return dataBlocks;
        }

        bool YesWorkflowDB::isInput(const row_id& dataId) {
            auto sql = std::string(R"(
                SELECT flow.id from flow
                JOIN port ON port.id = flow.port
                JOIN data_block ON data_block.id = flow.data_block 
                WHERE data_block.id = ? AND flow.direction = 1
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, dataId);
            return (statement.step() == SQLITE_ROW);
        }


        bool YesWorkflowDB::isParamOnly(const row_id& dataId) {
            auto sql = std::string(R"(
                SELECT annotation.id 
                FROM annotation
                JOIN port ON annotation.id = port.annotation
                JOIN flow ON port.id = flow.port
                JOIN data_block ON data_block.id = flow.data_block 
                WHERE data_block.id = ? AND annotation.tag = 4
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, dataId);
            return (statement.step() != SQLITE_ROW);
        }
    }
}