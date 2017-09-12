#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createFlowTable() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE TABLE flow(
                    id              INTEGER         NOT NULL        PRIMARY KEY,
                    port            INTEGER         NOT NULL        REFERENCES port(id),
                    data_block      INTEGER         NOT NULL        REFERENCES data_block(id),
                    direction       INTEGER         NOT NULL,
                    min_rate        INTEGER         NULL,
                    max_rate        INTEGER         NULL
                );

            )"));
        }

        Flow getFlowFromSelectStatementFields(SelectStatement& statement) {
            auto id = statement.getNullableIdField(0);
            auto portId = statement.getIdField(1);
            auto dataBlockId = statement.getIdField(2);
            auto direction = static_cast<Flow::Direction>(statement.getInt64Field(3));
            auto minRate = statement.getNullableInt64Field(4);
            auto maxRate = statement.getNullableInt64Field(5);
            return Flow(id, portId, dataBlockId, direction, minRate, maxRate);
        }

        row_id YesWorkflowDB::insert(const Flow& flow) {
            string sql = "INSERT INTO flow(id, port, data_block, direction, min_rate, max_rate) VALUES (?,?,?,?,?,?);";
            InsertStatement statement(db, sql);
            statement.bindNullableId(1, flow.id);
            statement.bindId(2, flow.portId);
            statement.bindId(3, flow.dataBlockId);
            statement.bindInt64(4, static_cast<long>(flow.direction));
            statement.bindNullableInt64(5, flow.minRate);
            statement.bindNullableInt64(6, flow.maxRate);
            statement.execute();
            return statement.getGeneratedId();
        }

        Flow YesWorkflowDB::selectFlowById(const row_id& requested_id) {
            string sql = "SELECT id, port, data_block, direction, min_rate, max_rate FROM flow WHERE id = ?";
            SelectStatement statement(db, sql);
            statement.bindId(1, requested_id);
            if (statement.step() != SQLITE_ROW) throw std::runtime_error("No flow with that id");
            return getFlowFromSelectStatementFields(statement);
        }

        std::vector<Flow> YesWorkflowDB::selectFlowsByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT flow.id, port, data_block, direction, min_rate, max_rate 
                FROM flow JOIN data_block ON flow.data_block = data_block.id 
                WHERE data_block.workflow = ?
                ORDER BY flow.direction, data_block.name, flow.id
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto flows = std::vector<Flow>{};
            while (statement.step() == SQLITE_ROW) {
                flows.push_back(getFlowFromSelectStatementFields(statement));
            }
            return flows;
        }

    }
}