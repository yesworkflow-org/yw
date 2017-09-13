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
            dot = std::make_shared<DotBuilder>();
            dot->beginGraph(workflow.name);
            drawProgramBlocksAsNodes(workflow.id.getValue());
            drawDataBlocksAsNodes(workflow.id.getValue());
            drawFlowEdgesBetweenProgramsAndData(workflow.id.getValue());
            dot->endGraph();
            return dot->str();
        }

        void WorkflowGrapher::drawProgramBlocksAsNodes(const row_id& workflowId) {
            for (auto programBlock : ywdb.selectProgramBlocksInWorkflow(workflowId)) {
                dot->node(programBlock.name);
            }
        }

        void WorkflowGrapher::drawDataBlocksAsNodes(const row_id& workflowId) {
            for (auto dataBlock : ywdb.selectDataBlocksByWorkflowId(workflowId)) {
                dot->node(dataBlock.name);
            }
        }

        void WorkflowGrapher::drawFlowEdgesBetweenProgramsAndData(const row_id& workflowId) {
            for (auto flowView : ywdb.selectFlowViewsByWorkflowId(workflowId)) {
                if (flowView.direction == Flow::Direction::OUT) {
                    dot->edge(flowView.programBlockName, flowView.dataBlockName);
                }
                else {
                    dot->edge(flowView.dataBlockName, flowView.programBlockName);
                }
            }
        }
    }
}
