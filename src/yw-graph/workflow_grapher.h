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

            void applyWorkflowPortNodeStyle();
            void beginWorkflowBox();
            void drawCombinedGraph(const row_id& workflowId);
            void drawDataGraph(const row_id& workflowId);
            void drawProcessGraph(const row_id& workflowId);
            void drawProgramBlockAsNode(const yw::db::ProgramBlock& programBlock);
            void drawProgramBlocksAsNodes(const row_id& workflowId);
            void drawDataEdgesBetweenProgramNodes(const row_id& workflowId);
            void drawDataBlockAsNode(const yw::db::DataBlock& dataBlock);
            void drawDataBlocksAsNodes(const row_id& workflowId);
            void drawFlowEdgesBetweenProgramsAndData(const row_id& workflowId);
            void drawWorkflowInputsAsNodes(const row_id& workflowId);
            void drawWorkflowOutputsAsNodes(const row_id& workflowId);
            void drawProgramEdgesBetweenDataNodes(const row_id& workflowId);
            void drawEdgesFromWorkflowInputsToDataNodes(const row_id& workflowId);
            void drawEdgesFromDataNodesToWorkflowOutputs(const row_id& workflowId);
            void drawEdgesFromWorkflowInputsToProgramNodes(const row_id& workflowId);
            void drawEdgesFromProgramNodesToWorkflowOutputs(const row_id& workflowId);
            void endWorkflowBox();
        };
    }
}

