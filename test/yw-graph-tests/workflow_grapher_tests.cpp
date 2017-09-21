
#include "yw_graph_tests.h"

using namespace yw;
using namespace yw::db;
using namespace yw::config;
using namespace yw::extract;
using namespace yw::graph;
using namespace yw::model;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(WorkflowGrapher)

    YesWorkflowDB ywdb;
    Configuration config;
    StderrRecorder stderrRecorder;

    YW_TEST_SETUP(WorkflowGrapher) {
        config.insert(Setting{ "graph.styles", "OFF", Setting::SettingSource::COMMAND_LINE });
        config.insert(Setting{ "graph.layoutstyles", "OFF", Setting::SettingSource::COMMAND_LINE });
    }

YW_TEST_SET

    YW_TEST(WorkflowGrapher, EmptyWorkflowReturnsEmptyGraph)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(
            
            @begin b
            @end b
        
        )");

        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph b {
            }

            )")), dotText);
    }

    YW_TEST(WorkflowGrapher, SingleProgramWorkflowReturnsOneNodeGraphWithoutCommentsWhenDotCommentsAreOff)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b
                @end b

            @end w

        )");

        config.insert(Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            b
            }

            )")), dotText);
    }

    YW_TEST(WorkflowGrapher, SingleProgramWorkflowReturnsOneNodeGraphWithCommentsWhenDotCommentsOnByDefault)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b
                @end b

            @end w

        )");

        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing program blocks in workflow */
            b
            }

            )")), dotText);
    }


    YW_TEST(WorkflowGrapher, TwoProgramWorkflowReturnsTwoNodeGraph)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b1
                @end b1

                @begin b2
                @end b2

            @end w

        )");

        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            }

            )")), dotText);
    }

    YW_TEST(WorkflowGrapher, WithThreeTopLevelProgramBlocksNamedBlockIsWorkflowRendered)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin u
            @end u

            @begin v

                @begin b1
                @end b1

                @begin b2
                @end b2

            @end v

            @begin w
            @end w


        )");
        config.insert(Setting{ "graph.workflow", "v", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph v {
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            }

            )")), dotText);
    }

    YW_TEST(WorkflowGrapher, WorkflowWithTwoProgramsAndOneChannelYieldsThreeNodes)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b1
                @out d1
                @end b1

                @begin b2
                @in d1
                @end b2

            @end w

        )");

        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            
            /* Nodes representing data blocks in workflow */
            d1
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b2
            b1 -> d1
            }

            )")), dotText);
    }

    YW_TEST(WorkflowGrapher, InDataViewWorkflowWithTwoProgramsAndOneChannelYieldsThreeNodes)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b1
                @out d1
                @end b1

                @begin b2
                @in d1
                @out d2
                @end b2

                @begin b3
                @in d2
                @end b3

            @end w

        )");

        config.insert(Setting{ "graph.view", "DATA", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing data blocks in workflow */
            d1
            d2
            
            /* Edges representing program blocks between data blocks */
            d1 -> d2
            }

            )")), dotText);
    }


    YW_TEST(WorkflowGrapher, WorkflowWithTwoProgramsTwoChannelsYieldsFourNodes)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w

                @begin b1
                @out d1
                @out d2
                @end b1

                @begin b2
                @in d1
                @in d2
                @end b2

            @end w

        )");

        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            
            /* Nodes representing data blocks in workflow */
            d1
            d2
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b2
            d2 -> b2
            b1 -> d1
            b1 -> d2
            }

            )")), dotText);
    }

     YW_TEST(WorkflowGrapher, WorkflowWithInputYieldsNodeAndEdgeForInput)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w
            @in d1

                @begin b
                @in d1
                @end b

            @end w

        )");

        config.insert(Setting{ "graph.layoutstyles", "ON", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Start of box around nodes in workflow */
            subgraph cluster_workflow_box_outer { label=""; color=black; penwidth=2
            subgraph cluster_workflow_box_inner { label=""; penwidth=0
            
            /* Nodes representing program blocks in workflow */
            b
            
            /* Nodes representing data blocks in workflow */
            d1
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b
            
            /* End of box around nodes in workflow */
            }}
            
            /* Start of hidden box around workflow inputs */
            subgraph cluster_workflow_inputs_box_outer { label=""; penwidth=0
            subgraph cluster_workflow_inputs_box_inner { label=""; penwidth=0
            
            /* Nodes representing workflow input ports */
            "workflow input d1" [label=""]
            
            /* End of hidden box around workflow inputs */
            }}
            
            /* Edges representing flow of workflow input data */
            "workflow input d1" -> d1
            }

            )")), dotText);
    }

     YW_TEST(WorkflowGrapher, WorkflowWithInputsAndOutputsYieldsNodesAndEdgesForBoth)
     {
         auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(

            @begin w
            @in d1
            @out d2

                @begin b
                @in d1
                @out d2
                @end b

            @end w

        )");

         WorkflowGrapher grapher{ ywdb, config };
         auto dotText = grapher.graph(modelId);

         Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Nodes representing program blocks in workflow */
            b
            
            /* Nodes representing data blocks in workflow */
            d1
            d2
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b
            b -> d2
            
            /* Nodes representing workflow input ports */
            "workflow input d1" [label=""]
            
            /* Nodes representing workflow output ports */
            "workflow output d2" [label=""]
            
            /* Edges representing flow of workflow input data */
            "workflow input d1" -> d1
            
            /* Edges representing flow of workflow output data */
            d2 -> "workflow output d2"
            }

            )")), dotText);
     }


YW_TEST_END
