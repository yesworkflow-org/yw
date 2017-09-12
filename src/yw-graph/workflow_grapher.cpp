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

        string WorkflowGrapher::graph(const row_id& modelId, const string& workflowName) {
            auto workflow = ywdb.selectProgramBlockByModelIdAndBlockName(modelId, workflowName);
            dot = std::make_shared<DotBuilder>();
            dot->beginGraph(workflow.name);
            drawProgramBlocksAsNodes(workflow.id.getValue());
            drawDataBlocksAsNodes(workflow.id.getValue());
            dot->endGraph();
            return dot->str();
        }

        void WorkflowGrapher::drawProgramBlocksAsNodes(const row_id& workflowId) {
            for (auto programBlock : ywdb.selectProgramBlocksByWorkflowId(workflowId)) {
                dot->node(programBlock.name);
            }
        }

        void WorkflowGrapher::drawDataBlocksAsNodes(const row_id& workflowId) {
            for (auto dataBlock : ywdb.selectDataBlocksByWorkflowId(workflowId)) {
                dot->node(dataBlock.name);
            }
        }
    }
}
