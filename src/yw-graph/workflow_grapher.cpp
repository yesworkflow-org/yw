#include "workflow_grapher.h"
#include "dot_builder.h"

using namespace yw::config;
using namespace yw::db;
using namespace yw::sqlite;

using std::string;
using Visibility = SoftwareSetting::Visibility;

namespace yw {
    namespace graph {

        yw::config::Configuration WorkflowGrapher::defaults;

        const Configuration& WorkflowGrapher::getSoftwareSettings() {
            if (defaults.size() == 0) {

                defaults.insert(SoftwareSetting{ "graph.view", "combined", "Workflow view to render", { "PROCESS", "DATA", "COMBINED" } });
                defaults.insert(SoftwareSetting{ "graph.workflowbox", "SHOW", "Box around nodes internal to workflow", { "SHOW", "HIDE" } });
                defaults.insert(SoftwareSetting{ "graph.workflow", null_string, "Name of workflow to graph" });

                defaults.insert(SoftwareSetting{ "graph.programshape", "box", "Shape of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.programstyle", "filled", "Styling of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.programfillcolor", "#CCFFCC", "Color of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.programfont", "Helvetica", "Font in program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.programperipheries", "1", "Number of peripheries for program block nodes", {}, Visibility::INTERMEDIATE });

                defaults.insert(SoftwareSetting{ "graph.datashape", "box", "Shape of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.datastyle", "rounded,filled", "Styling of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.datafillcolor", "#FFFFCC", "Color of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.datafont", "Helvetica", "Font in data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(SoftwareSetting{ "graph.dataperipheries", "1", "Number of peripheries for data block nodes",{}, Visibility::INTERMEDIATE });

                defaults.insert(SoftwareSetting{ "graph.styles", "ON", "Apply node and edge styles to graph elements",{ "ON", "OFF" }, Visibility::EXPERT });
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

        string WorkflowGrapher::config(const string& key) {
            return configuration.getStringValue(key);
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

                if (config("graph.styles") == "ON") {
                    dot->comment("Style for nodes representing program blocks in workflow");
                    dot->setNodeFont(config("graph.programfont"));
                    dot->setNodeShape(config("graph.programshape"));
                    dot->setNodeStyle(config("graph.programstyle"));
                    dot->setNodeFillcolor(config("graph.programfillcolor"));
                    dot->setNodePeripheries(configuration.getIntValue("graph.programperipheries"));
                    dot->flushNodeStyle();
                }

                dot->comment("Nodes representing program blocks in workflow");
                for (auto programBlock : programBlocks) {
                    dot->node(programBlock.name);
                }
            }
        }

        void WorkflowGrapher::drawDataBlocksAsNodes(const row_id& workflowId) {
            auto dataBlocks = ywdb.selectDataBlocksByWorkflowId(workflowId);
            if (dataBlocks.size() > 0) {

                if (config("graph.styles") == "ON") {
                    dot->comment("Style for nodes representing data blocks in workflow");
                    dot->setNodeFont(config("graph.datafont"));
                    dot->setNodeShape(config("graph.datashape"));
                    dot->setNodeStyle(config("graph.datastyle"));
                    dot->setNodeFillcolor(config("graph.datafillcolor"));
                    dot->setNodePeripheries(configuration.getIntValue("graph.dataperipheries"));
                    dot->flushNodeStyle();
                }

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
