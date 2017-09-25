#include "ywdb.h"
#include "insert_statement.h"
#include "select_statement.h"

using std::string;
using namespace yw::sqlite;

namespace yw {
    namespace db {

        void YesWorkflowDB::createAdjacentProgramBlocksView() {
            SQLiteDB::createTable(db, std::string(R"(

                CREATE VIEW adjacent_program_blocks_view AS
                SELECT  workflow_block.id AS workflow_block_id,
                        upstream_program_block.id,
                        upstream_program_block.name AS upstream_program_block_name,
                        upstream_port.id,
                        upstream_port.name,
                        data_block.id,
                        data_block.name AS data_block_name,
                        downstream_port.id,
                        downstream_port.name,
                        downstream_program_block.id,
                        downstream_program_block.name AS downstream_program_block_name
                FROM program_block AS workflow_block
                JOIN program_block AS upstream_program_block ON upstream_program_block.workflow = workflow_block.id
                JOIN port AS upstream_port ON upstream_port.program_block = upstream_program_block.id
                JOIN flow AS upstream_flow ON upstream_flow.port = upstream_port.id
                JOIN data_block ON upstream_flow.data_block = data_block.id AND downstream_flow.data_block = data_block.id
                JOIN program_block AS downstream_program_block ON downstream_program_block.workflow = workflow_block.id
                JOIN port AS downstream_port ON downstream_port.program_block = downstream_program_block.id
                JOIN flow AS downstream_flow ON downstream_flow.port = downstream_port.id
                WHERE upstream_flow.direction=2 AND downstream_flow.direction=1

            )"));
        }

        AdjacentProgramBlocks getAdjacentProgramBlockPairFromSelectStatementFields(SelectStatement& statement) {
            
            auto workflowId = statement.getNullableIdField(0);
            auto upstreamProgramBlockId = statement.getIdField(1);
            auto upstreamProgramBlockName = statement.getTextField(2);
            auto upstreamPortId = statement.getIdField(3);
            auto upstreamPortName = statement.getTextField(4);
            auto dataBlockId = statement.getIdField(5);
            auto dataBlockName = statement.getTextField(6);
            auto downstreamPortId = statement.getIdField(7);
            auto downstreamPortName = statement.getTextField(8);
            auto downstreamProgramBlockId = statement.getIdField(9);
            auto downstreamProgramBlockName = statement.getTextField(10);

            return AdjacentProgramBlocks{ workflowId, upstreamProgramBlockId, upstreamProgramBlockName, upstreamPortId, upstreamPortName,
                                            dataBlockId, dataBlockName, downstreamPortId, downstreamPortName,
                                            downstreamProgramBlockId, downstreamProgramBlockName };
        }

        std::vector<AdjacentProgramBlocks> YesWorkflowDB::selectAdjacentProgramBlocksByWorkflowId(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT * FROM adjacent_program_blocks_view
                WHERE workflow_block_id = ?
                ORDER BY upstream_program_block_name, data_block_name, downstream_program_block_name
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto adjacentProgramBlockPairs = std::vector<AdjacentProgramBlocks>{};
            while (statement.step() == SQLITE_ROW) {
                adjacentProgramBlockPairs.push_back(getAdjacentProgramBlockPairFromSelectStatementFields(statement));
            }
            return adjacentProgramBlockPairs;
        }

        std::vector<ProgramProgramEdge> YesWorkflowDB::selectProgramProgramEdges(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT DISTINCT upstream_program_block_name, downstream_program_block_name 
                FROM adjacent_program_blocks_view
                WHERE workflow_block_id = ?
                ORDER BY upstream_program_block_name, downstream_program_block_name
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto programProgramEdges = std::vector<ProgramProgramEdge>{};
            while (statement.step() == SQLITE_ROW) {
                programProgramEdges.push_back(ProgramProgramEdge{
                    statement.getTextField(0),
                    statement.getTextField(1)
                });
            }
            return programProgramEdges;
        }

        std::vector<ProgramDataProgramEdge> YesWorkflowDB::selectProgramDataProgramEdges(const row_id& workflowId) {
            auto sql = std::string(R"(
                SELECT DISTINCT upstream_program_block_name, data_block_name, downstream_program_block_name 
                FROM adjacent_program_blocks_view
                WHERE workflow_block_id = ?
                ORDER BY  upstream_program_block_name, downstream_program_block_name, data_block_name
            )");
            SelectStatement statement(db, sql);
            statement.bindNullableId(1, workflowId);
            auto programDataProgramEdges = std::vector<ProgramDataProgramEdge>{};
            while (statement.step() == SQLITE_ROW) {
                programDataProgramEdges.push_back(ProgramDataProgramEdge{
                    statement.getTextField(0),
                    statement.getTextField(1),
                    statement.getTextField(2)
                });
            }
            return programDataProgramEdges;
        }
    }
}