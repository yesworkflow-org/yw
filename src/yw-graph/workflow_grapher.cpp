#include "workflow_grapher.h"
#include "dot_builder.h"

using namespace yw::config;
using namespace yw::db;
using namespace yw::sqlite;

using std::string;
using Visibility = Setting::Visibility;

namespace yw {
    namespace graph {

        yw::config::Configuration WorkflowGrapher::defaults;

        const Configuration& WorkflowGrapher::getSettings() {
            if (defaults.size() == 0) {

                defaults.insert(Setting{ "graph.datalabel", "NAME", "Info to display in data nodes",{ "NAME", "URI", "BOTH" } });
                defaults.insert(Setting{ "graph.edgelabels", "HIDE", "Labels on edges in process view",{ "SHOW", "HIDE" } });
                defaults.insert(Setting{ "graph.params", "REDUCE", "Visibility of parameters",{ "SHOW", "REDUCE" } });
                defaults.insert(Setting{ "graph.portlayout", "GROUP", "Layout mode for workflow ports",{ "GROUP", "RELAX", "HIDE" } });
                defaults.insert(Setting{ "graph.programlabel", "NAME", "Info to display in program nodes", {"NAME", "DESCRIPTION", "BOTH" } });
                defaults.insert(Setting{ "graph.view", "COMBINED", "Workflow view to render",{ "PROCESS", "DATA", "COMBINED" } });
                defaults.insert(Setting{ "graph.workflowbox", "SHOW", "Box around nodes internal to workflow", { "SHOW", "HIDE" } });
                defaults.insert(Setting{ "graph.workflow", null_string, "Name of workflow to graph" });

                defaults.insert(Setting{ "graph.programshape", "box", "Shape of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.programstyle", "filled", "Styling of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.programfillcolor", "#CCFFCC", "Color of program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.programfont", "Helvetica", "Font in program block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.programperipheries", "1", "Number of peripheries for program block nodes", {}, Visibility::INTERMEDIATE });

                defaults.insert(Setting{ "graph.datashape", "box", "Shape of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.datastyle", "rounded,filled", "Styling of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.datafillcolor", "#FFFFCC", "Color of data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.datafont", "Helvetica", "Font in data block nodes", {}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.dataperipheries", "1", "Number of peripheries for data block nodes",{}, Visibility::INTERMEDIATE });

                defaults.insert(Setting{ "graph.portshape", "circle", "Shape of workflow port nodes",{}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.portfillcolor", "#FFFFFF", "Color of workflow portnodes",{}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.portperipheries", "1", "Number of peripheries for workflow port nodes",{}, Visibility::INTERMEDIATE });
                defaults.insert(Setting{ "graph.portsize", "0.2", "Diameter of workflow port nodes",{}, Visibility::INTERMEDIATE });

                defaults.insert(Setting{ "graph.styles", "ON", "Apply node and edge styles to graph elements",{ "ON", "OFF" }, Visibility::EXPERT });
                defaults.insert(Setting{ "graph.layoutstyles", "ON", "Use clusters to group group elements",{ "ON", "OFF" }, Visibility::EXPERT });
            }
            return defaults;
        }

        WorkflowGrapher::WorkflowGrapher(
            yw::db::YesWorkflowDB& ywdb,
            const yw::config::Configuration& userConfiguration
        ) : ywdb(ywdb) {
            configuration.insertAll(getSettings());
            configuration.insertAll(userConfiguration);
        }

        string WorkflowGrapher::config(const string& key) {
            return configuration.getValueText(key);
        }

        string WorkflowGrapher::graph(const row_id& modelId) {
            auto workflowNameSetting = configuration.getSetting("graph.workflow");
            string workflowName;
            if (workflowNameSetting.valueText.hasValue()) {
                workflowName = workflowNameSetting.valueText.getValue();
            }
            else {
                auto topLevelProgramBlocks = ywdb.selectTopLevelProgramBlocksInModel(modelId);
                if (topLevelProgramBlocks.size() > 0) {
                    workflowName = topLevelProgramBlocks[0].name;
                }
                else {
                    throw std::runtime_error("No program blocks found to graph.");
                }
            }
            auto workflow = ywdb.selectProgramBlockByModelIdAndBlockName(modelId, workflowName);
            dot = std::make_shared<DotBuilder>(configuration);
            dot->beginGraph(workflow.name);
            auto view = config("graph.view");
            if (view == "COMBINED") {
                drawCombinedGraph(workflow.id.getValue());
            }
            else if (view == "DATA") {
                drawDataGraph(workflow.id.getValue());
            }
            else if (view == "PROCESS") {
                drawProcessGraph(workflow.id.getValue());
            }

            dot->endGraph();
            return dot->str();
        }

        void WorkflowGrapher::drawCombinedGraph(const row_id& workflowId) {
            beginWorkflowBox();
            drawProgramBlocksAsNodes(workflowId);
            drawDataBlocksAsNodes(workflowId);
            drawFlowEdgesBetweenProgramsAndData(workflowId);
            endWorkflowBox();
            if (config("graph.portlayout") != "HIDE") {
                drawWorkflowInputsAsNodes(workflowId);
                drawWorkflowOutputsAsNodes(workflowId);
                drawEdgesFromWorkflowInputsToDataNodes(workflowId);
                drawEdgesFromDataNodesToWorkflowOutputs(workflowId);
            }
        }

        void WorkflowGrapher::drawDataGraph(const row_id& workflowId) {
            beginWorkflowBox();
            drawDataBlocksAsNodes(workflowId);
            drawProgramEdgesBetweenDataNodes(workflowId);
            endWorkflowBox();
            if (config("graph.portlayout") != "HIDE") {
                drawWorkflowInputsAsNodes(workflowId);
                drawWorkflowOutputsAsNodes(workflowId);
                drawEdgesFromWorkflowInputsToDataNodes(workflowId);
                drawEdgesFromDataNodesToWorkflowOutputs(workflowId);
            }
        }

        void WorkflowGrapher::drawProcessGraph(const row_id& workflowId) {
            beginWorkflowBox();
            drawProgramBlocksAsNodes(workflowId);
            drawDataEdgesBetweenProgramNodes(workflowId);
            endWorkflowBox();
            if (config("graph.portlayout") != "HIDE") {
                drawWorkflowInputsAsNodes(workflowId);
                drawWorkflowOutputsAsNodes(workflowId);
                drawEdgesFromWorkflowInputsToProgramNodes(workflowId);
                drawEdgesFromProgramNodesToWorkflowOutputs(workflowId);
            }
        }

        void WorkflowGrapher::beginWorkflowBox() {
            if (config("graph.layoutstyles") == "ON") {
                dot->comment("Start of box around nodes in workflow");
                dot->beginSubgraph("workflow_box", config("graph.workflowbox") == "SHOW");
            }
        }

        void WorkflowGrapher::endWorkflowBox() {
            if (config("graph.layoutstyles") == "ON") {
                dot->comment("End of box around nodes in workflow");
                dot->endSubgraph();
            }
        }

        void WorkflowGrapher::drawProgramBlockAsNode(const ProgramBlock& programBlock) {

            auto programLabelMode = config("graph.programlabel");
            auto description = programBlock.description;
   
            if (programLabelMode == "NAME" || !description.hasValue()) { 
                dot->node(programBlock.name);
            } else if (programLabelMode == "DESCRIPTION") { 
                dot->node(programBlock.name, description.str()); 
                return;
            } else {
                dot->recordNode(programBlock.name, programBlock.name, description.str());
            }
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
                    drawProgramBlockAsNode(programBlock);
                }
            }
        }
        
        void WorkflowGrapher::drawDataBlockAsNode(const DataBlock& dataBlock) {

            auto dataLabelMode = config("graph.datalabel");

            nullable_string uri;
            auto flowTemplates = ywdb.selectFlowTemplatesByDataId(dataBlock.id.getValue());
            if (flowTemplates.size() > 0) {
                auto firstFlowTemplate = flowTemplates[0];
                std::string flowTemplate;
                if (firstFlowTemplate.scheme.hasValue()) {
                    flowTemplate += firstFlowTemplate.scheme.getValue() + ":";
                }
                flowTemplate += firstFlowTemplate.path;
                uri = nullable_string(flowTemplate);
            }

            bool isParam = ywdb.isInput(dataBlock.id.getValue()) && ywdb.isParamOnly(dataBlock.id.getValue());

            if (dataLabelMode == "NAME" || !uri.hasValue()) {
                if (isParam && config("graph.params") == "REDUCE") {
                    dot->node(dataBlock.name, dataBlock.name, "#FFFFFF");
                }
                else {
                    dot->node(dataBlock.name);
                }
            }
            else if (dataLabelMode == "URI") {
                dot->node(dataBlock.name, uri.str());
            }
            else {
                dot->recordNode(dataBlock.name, dataBlock.name, uri.str());
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
                    drawDataBlockAsNode(dataBlock);
                }
            }
        }

        void WorkflowGrapher::drawDataEdgesBetweenProgramNodes(const row_id& workflowId) {
            if (config("graph.edgelabels") == "SHOW") {
                auto programDataProgramEdges = ywdb.selectProgramDataProgramEdges(workflowId);
                if (programDataProgramEdges.size() > 0) {
                    dot->comment("Edges representing data blocks between program blocks");
                    for (auto programDataProgramEdge : programDataProgramEdges) {
                        dot->edge(programDataProgramEdge.upstreamProgramBlockName, programDataProgramEdge.downstreamProgramBlockName, programDataProgramEdge.dataBlockName);
                    }
                }
            }
            else {
                auto programProgramEdges = ywdb.selectProgramProgramEdges(workflowId);
                if (programProgramEdges.size() > 0) {
                    dot->comment("Edges representing data blocks between program blocks");
                    for (auto programProgramEdge : programProgramEdges) {
                        dot->edge(programProgramEdge.upstreamProgramBlockName, programProgramEdge.downstreamProgramBlockName);
                    }
                }
            }
        }

        void WorkflowGrapher::drawProgramEdgesBetweenDataNodes(const row_id& workflowId) {
            auto programEdges = ywdb.selectDataDataEdges(workflowId);
            if (programEdges.size() > 0) {
                dot->comment("Edges representing program blocks between data blocks");
                for (auto programEdge : programEdges) {
                    dot->edge(programEdge.inputDataBlockName, programEdge.outputDataBlockName);
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

        void WorkflowGrapher::applyWorkflowPortNodeStyle() {
            if (config("graph.styles") == "ON") {
                dot->comment("Style for nodes representing workflow ports");
                dot->setNodeShape(config("graph.portshape"));
                dot->setNodeFillcolor(config("graph.portfillcolor"));
                dot->setNodePeripheries(configuration.getIntValue("graph.portperipheries"));
                dot->setNodeWidth(configuration.getDoubleValue("graph.portsize"));
                dot->flushNodeStyle();
            }
        }

        void WorkflowGrapher::drawWorkflowInputsAsNodes(const row_id& workflowId) {

            auto inputDataNames = ywdb.selectWorkflowIODataNames(workflowId, Flow::Direction::IN);
            if (inputDataNames.size() > 0) {

                bool groupWorkflowPorts = config("graph.layoutstyles") == "ON"
                    && config("graph.portlayout") == "GROUP";

                if (groupWorkflowPorts) {
                    dot->comment("Start of hidden box around workflow inputs");
                    dot->beginSubgraph("workflow_inputs_box", false);
                }

                applyWorkflowPortNodeStyle();

                dot->comment("Nodes representing workflow input ports");
                for (auto name : inputDataNames) {
                    dot->node("workflow input " + name, "");
                }

                if (groupWorkflowPorts) {
                    dot->comment("End of hidden box around workflow inputs");
                    dot->endSubgraph();
                }
            }
        }

        void WorkflowGrapher::drawWorkflowOutputsAsNodes(const row_id& workflowId) {

            auto outputDataNames = ywdb.selectWorkflowIODataNames(workflowId, Flow::Direction::OUT);
            if (outputDataNames.size() > 0) {

                bool groupWorkflowPorts = config("graph.layoutstyles") == "ON"
                    && config("graph.portlayout") == "GROUP";

                if (groupWorkflowPorts) {
                    dot->comment("Start of hidden box around workflow outputs");
                    dot->beginSubgraph("workflow_outputs_box", false);
                }

                applyWorkflowPortNodeStyle();

                dot->comment("Nodes representing workflow output ports");
                for (auto name : outputDataNames) {
                    dot->node("workflow output " + name, "");
                }

                if (groupWorkflowPorts) {
                    dot->comment("End of hidden box around workflow outputs");
                    dot->endSubgraph();
                }
            }
        }

        void WorkflowGrapher::drawEdgesFromWorkflowInputsToDataNodes(const row_id& workflowId) {
            auto inputDataNames = ywdb.selectWorkflowIODataNames(workflowId, Flow::Direction::IN);
            if (inputDataNames.size() > 0) {
                dot->comment("Edges representing flow of workflow input data");
                for (auto name : inputDataNames) {
                    dot->edge("workflow input " + name, name );
                }
            }
        }

        void WorkflowGrapher::drawEdgesFromDataNodesToWorkflowOutputs(const row_id& workflowId) {
            auto outputDataNames = ywdb.selectWorkflowIODataNames(workflowId, Flow::Direction::OUT);
            if (outputDataNames.size() > 0) {
                dot->comment("Edges representing flow of workflow output data");
                for (auto name : outputDataNames) {
                    dot->edge(name, "workflow output " + name);
                }
            }
        }

        void  WorkflowGrapher::drawEdgesFromWorkflowInputsToProgramNodes(const row_id& workflowId) {
            bool labelEdges = (config("graph.edgelabels") == "SHOW");
            auto dataProgramEdges = ywdb.selectWorkflowIODataProgramEdges(workflowId, Flow::Direction::IN);
            if (dataProgramEdges.size() > 0) {
                dot->comment("Edges representing flow of workflow input data to program blocks");
                for (auto dataProgramEdge : dataProgramEdges) {
                    if (labelEdges) {
                        dot->edge("workflow input " + dataProgramEdge.dataName, dataProgramEdge.programName, dataProgramEdge.dataName);
                    }
                    else {
                        dot->edge("workflow input " + dataProgramEdge.dataName, dataProgramEdge.programName);
                    }
                }
            }
        }

        void  WorkflowGrapher::drawEdgesFromProgramNodesToWorkflowOutputs(const row_id& workflowId) {
            bool labelEdges = (config("graph.edgelabels") == "SHOW");
            auto dataProgramEdges = ywdb.selectWorkflowIODataProgramEdges(workflowId, Flow::Direction::OUT);
            if (dataProgramEdges.size() > 0) {
                dot->comment("Edges representing flow of workflow program blocks to workflow outputs");
                for (auto dataProgramEdge : dataProgramEdges) {
                    if (labelEdges) {
                        dot->edge(dataProgramEdge.programName, "workflow output " + dataProgramEdge.dataName, dataProgramEdge.dataName);
                    }
                    else {
                        dot->edge(dataProgramEdge.programName, "workflow output " + dataProgramEdge.dataName);
                    }
                }
            }
        }
    }
}
