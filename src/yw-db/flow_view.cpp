#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        FlowView getFlowViewFromSelectStatementFields(SelectStatement& statement) {
            
            auto flowId = statement.getNullableIdField(0);
            auto workflowId = statement.getNullableIdField(1);
            auto programBlockId = statement.getIdField(2);
            auto programBlockName = statement.getTextField(3);
            auto portId = statement.getIdField(4);
            auto portName = statement.getTextField(5);
            auto dataBlockId = statement.getIdField(6);
            auto dataBlockName = statement.getTextField(7);
            auto direction = static_cast<Flow::Direction>(statement.getInt64Field(8));
            auto minRate = statement.getNullableInt64Field(9);
            auto maxRate = statement.getNullableInt64Field(10);

            return FlowView(flowId, workflowId, programBlockId, programBlockName,
                            portId, portName, dataBlockId, dataBlockName, 
                            direction, minRate, maxRate);
        }

        std::vector<FlowView> YesWorkflowDB::selectFlowViewsByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT flow.id, program_block.workflow, program_block.id, program_block.name, port.id, port.name, data_block.id, data_block.name, direction, min_rate, max_rate 
                FROM flow 
                JOIN port ON flow.port = port.id
                JOIN data_block ON flow.data_block = data_block.id 
                JOIN program_block ON port.program_block = program_block.id 
                WHERE data_block.workflow = ?
                ORDER BY flow.direction, data_block.name, flow.id
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto flowViews = std::vector<FlowView>{};
            while (statement.step() == SQLITE_ROW) {
                flowViews.push_back(getFlowViewFromSelectStatementFields(statement));
            }
            return flowViews;
        }
    }
}