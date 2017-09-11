#pragma once

#include "ywdb.h"
#include "yw_config.h"

namespace yw {
    namespace graph {

        class WorkflowGrapher {

            yw::db::YesWorkflowDB& ywdb;
            yw::config::Configuration configuration;

            static yw::config::Configuration defaults;


        public:

            WorkflowGrapher(
                yw::db::YesWorkflowDB& ywdb,
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            static const yw::config::Configuration& getSoftwareSettings();

            std::string graph(const row_id& modelId, const std::string& workflowName);
            std::string graph(const row_id& workflowId);

        };
    }
}

