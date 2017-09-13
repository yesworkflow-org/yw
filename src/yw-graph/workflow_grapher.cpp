#include "workflow_grapher.h"
#include "dot_builder.h"

using namespace yw::config;
using namespace yw::db;
using namespace yw::sqlite;

using std::string;

namespace yw {
    namespace graph {

        yw::config::Configuration WorkflowGrapher::defaults;

        const Configuration& WorkflowGrapher::getSoftwareSettings() {
            if (defaults.size() == 0) {
                defaults.insert(SoftwareSetting{ "graph.view", "combined", "Workflow view to render", { "PROCESS", "DATA", "COMBINED" } });
                defaults.insert(SoftwareSetting{ "graph.workflowbox", "SHOW", "Box around nodes internal to workflow", { "SHOW", "HIDE" } });
                defaults.insert(SoftwareSetting{ "graph.workflow", null_string, "Name of workflow to graph" });
            }
            return defaults;
        }

        WorkflowGrapher::WorkflowGrapher(
            yw::db::YesWorkflowDB& ywdb,
            const yw::config::Configuration& userConfiguration
        ) : ywdb(ywdb) {
            configuration.insertAll(getSoftwareSettings());
            configuration.insertAll(userConfiguration);
        }

        string WorkflowGrapher::graph(const row_id& modelId) {
            auto workflowNameSetting = configuration.getSetting("graph.workflow");
            string workflowName;
            if (workflowNameSetting.value.hasValue()) {
                workflowName = workflowNameSetting.value.getValue();
            }
            else {
                auto topLevelProgramBlocks = ywdb.selectTopLevelProgramBlocksInModel(modelId);
                if (topLevelProgramBlocks.size() > 0) {
                    workflowName = topLevelProgramBlocks[0].name;
                }
                else {
                    throw std::runtime_error("No top-level workflow found in model.");
                }
            }
            auto workflow = ywdb.selectProgramBlockByModelIdAndBlockName(modelId, workflowName);
            dot = std::make_shared<DotBuilder>(configuration);
            dot->beginGraph(workflow.name);
            drawProgramBlocksAsNodes(workflow.id.getValue());
            drawDataBlocksAsNodes(workflow.id.getValue());
            drawFlowEdgesBetweenProgramsAndData(workflow.id.getValue());
            dot->endGraph();
            return dot->str();
        }

        void WorkflowGrapher::drawProgramBlocksAsNodes(const row_id& workflowId) {
            auto programBlocks = ywdb.selectProgramBlocksInWorkflow(workflowId);
            if (programBlocks.size() > 0) {
                dot->comment("Nodes representing program blocks in workflow");
                for (auto programBlock : programBlocks) {
                    dot->node(programBlock.name);
                }
            }
        }

        void WorkflowGrapher::drawDataBlocksAsNodes(const row_id& workflowId) {
            auto dataBlocks = ywdb.selectDataBlocksByWorkflowId(workflowId);
            if (dataBlocks.size() > 0) {
                dot->comment("Nodes representing data blocks in workflow");
                for (auto dataBlock : dataBlocks) {
                    dot->node(dataBlock.name);
                }
            }
        }

        void WorkflowGrapher::drawFlowEdgesBetweenProgramsAndData(const row_id& workflowId) {
            auto flows = ywdb.selectFlowViewsByWorkflowId(workflowId);
            if (flows.size() > 0) {
                dot->comment("Edges representing flow of data into and out of code blocks");
                for (auto flow : flows) {
                    if (flow.direction == Flow::Direction::OUT) {
                        dot->edge(flow.programBlockName, flow.dataBlockName);
                    }
                    else {
                        dot->edge(flow.dataBlockName, flow.programBlockName);
                    }
                }
            }
        }
    }
}
