#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createWorkflowPortView() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE VIEW workflow_port_view AS
                SELECT workflow_block.id AS workflow_block_id, 
                       workflow_block.name, 
                       workflow_port.id, 
                       workflow_port.name,
                       workflow_data.id, 
                       workflow_data.name,
                       program_data.id, 
                       program_data.name AS program_data_block_name,
                       program_port.id, 
                       program_port.name, 
                       program.id, 
                       program.name, 
                       program_flow.direction AS direction

                FROM program_block AS workflow_block
                JOIN program_block AS program ON program.workflow = workflow_block.id
                JOIN port AS workflow_port ON workflow_port.program_block = workflow_block.id
                JOIN port AS program_port ON program_port.program_block = program.id       
                JOIN flow AS workflow_flow ON workflow_flow.port = workflow_port.id
                JOIN flow AS program_flow ON program_flow.port = program_port.id
                JOIN data_block AS workflow_data ON workflow_flow.data_block = workflow_data.id
                JOIN data_block AS program_data ON program_flow.data_block = program_data.id
                                                AND program_data.name = workflow_data.name
                ORDER BY program_flow.direction, program_data.name, program_data.id

            )"));
        }

        WorkflowPort getWorkflowPortFromSelectStatementFields(SelectStatement& statement) {
            
            auto workflowId = statement.getNullableIdField(0);
            auto workflowName = statement.getTextField(1);
            auto workflowPortId = statement.getIdField(2);
            auto workflowPortName = statement.getTextField(3);
            auto workflowDataBlockId = statement.getIdField(4);
            auto workflowDataBlockName = statement.getTextField(5);
            auto programDataBlockId = statement.getIdField(6);
            auto programDataBlockName = statement.getTextField(7);
            auto programPortId = statement.getIdField(8);
            auto programPortName = statement.getTextField(9);
            auto programBlockId = statement.getIdField(10);
            auto programBlockName = statement.getTextField(11);
            auto direction = static_cast<Flow::Direction>(statement.getInt64Field(12));

            return WorkflowPort(workflowId, workflowName, workflowPortId, workflowPortName,
                              workflowDataBlockId, workflowDataBlockName, programDataBlockId, programDataBlockName,
                              programPortId, programPortName, programBlockId, programBlockName, direction);
        }

        std::vector<WorkflowPort> YesWorkflowDB::selectWorkflowPortsByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT * FROM workflow_port_view
                WHERE workflow_block_id = ?
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto portals = std::vector<WorkflowPort>{};
            while (statement.step() == SQLITE_ROW) {
                portals.push_back(getWorkflowPortFromSelectStatementFields(statement));
            }
            return portals;
        }

        std::vector<std::string> YesWorkflowDB::selectWorkflowIODataNames(const row_id& workflowId, Flow::Direction direction) {
            auto sql = std::string(R"(
                SELECT DISTINCT program_data_block_name 
                FROM workflow_port_view
                WHERE workflow_block_id = ? AND direction = ?
            )");
            yw::sqlite::SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            statement.bindInt64(2, static_cast<long>(direction));
            auto dataNames = std::vector<std::string>{};
            while (statement.step() == SQLITE_ROW) {
                dataNames.push_back(statement.getTextField(0));
            }
            return dataNames;
        }
    }
}
