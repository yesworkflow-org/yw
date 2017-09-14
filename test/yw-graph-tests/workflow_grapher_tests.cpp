
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
    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(WorkflowGrapher, EmptyWorkflowReturnsEmptyGraph)
    {
        auto modelId = ModelBuilder{ ywdb }.buildModelFromString(R"(
            
            @begin b
            @end b
        
        )");

        WorkflowGrapher grapher{ ywdb };
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

        Configuration config;
        config.insert(Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
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

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
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

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
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
        Configuration config;
        config.insert(Setting{ "graph.workflow", "v", Setting::SettingSource::COMMAND_LINE });
        WorkflowGrapher grapher{ ywdb, config };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph v {
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
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

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            
            /* Style for nodes representing data blocks in workflow */
            node[shape=box style="rounded,filled" fillcolor="#FFFFCC" peripheries=1 fontname=Helvetica]
            
            /* Nodes representing data blocks in workflow */
            d1
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b2
            b1 -> d1
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

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId);

        Assert::AreEqual((trimmargins(R"(

            digraph w {
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            
            /* Style for nodes representing data blocks in workflow */
            node[shape=box style="rounded,filled" fillcolor="#FFFFCC" peripheries=1 fontname=Helvetica]
            
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

YW_TEST_END
