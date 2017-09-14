#pragma once

#include "ywdb.h"
#include "yw_config.h"
#include "dot_builder.h"

namespace yw {
    namespace graph {

        class WorkflowGrapher {

            yw::db::YesWorkflowDB& ywdb;
            yw::config::Configuration configuration;
            std::shared_ptr<DotBuilder> dot;

            static yw::config::Configuration defaults;

        public:

            WorkflowGrapher(
                yw::db::YesWorkflowDB& ywdb,
                const yw::config::Configuration& userConfiguration = yw::config::Configuration{}
            );

            static const yw::config::Configuration& getSoftwareSettings();

            std::string graph(const row_id& modelId);

        private:

            std::string config(const std::string& key);
            
            void beginWorkflowBox();
            void drawProgramBlocksAsNodes(const row_id& workflowId);
            void drawDataBlocksAsNodes(const row_id& workflowId);
            void drawFlowEdgesBetweenProgramsAndData(const row_id& workflowId);
            void endWorkflowBox();
        };
    }
}

