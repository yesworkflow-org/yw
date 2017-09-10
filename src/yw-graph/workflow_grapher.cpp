#include "workflow_grapher.h"

using namespace yw::config;
using namespace yw::db;
using namespace yw::sqlite;

namespace yw {
    namespace graph {

        yw::config::Configuration WorkflowGrapher::defaultSettings;

        const Configuration& WorkflowGrapher::getSoftwareSettings() {
            if (defaultSettings.size() == 0) {
                defaultSettings.insert(SoftwareSetting{ "outline.indentblock", "0" });
                defaultSettings.insert(SoftwareSetting{ "outline.indentqualifiers", "-1" });
            }
            return defaultSettings;
        }

        WorkflowGrapher::WorkflowGrapher(
            yw::db::YesWorkflowDB& ywdb,
            const yw::config::Configuration& userConfiguration
        ) : ywdb(ywdb) {

            Configuration configuration;
            configuration.insertAll(getSoftwareSettings());
            configuration.insertAll(userConfiguration);
        }
    }
}
