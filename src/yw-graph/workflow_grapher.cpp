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
            return graph(1);
        }

        string WorkflowGrapher::graph(const row_id& WorkflowId) {
            DotBuilder dot;
            dot.beginGraph();
            dot.endGraph();
            return dot.str();
        }
    }
}
