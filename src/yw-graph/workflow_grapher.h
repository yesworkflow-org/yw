#pragma once

#include "ywdb.h"
#include "yw_config.h"

namespace yw {
    namespace graph {

        class WorkflowGrapher {

            yw::db::YesWorkflowDB& ywdb;
            static yw::config::Configuration defaults;

            WorkflowGrapher(
                yw::db::YesWorkflowDB& ywdb,
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            static const yw::config::Configuration& getSoftwareSettings();

        };
    }
}

