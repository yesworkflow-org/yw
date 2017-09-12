
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
    row_id modelId = 1;
    StderrRecorder stderrRecorder;
    Configuration grapherConfiguration;


YW_TEST_SET

    YW_TEST(WorkflowGrapher, EmptyWorkflowReturnsEmptyGraph)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString( R"(
            
            @begin b
            @end b
        
        )");

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId, "b");

        Assert::AreEqual(
            "digraph b {"   EOL
            "}"             EOL
            , dotText);
    }

    YW_TEST(WorkflowGrapher, SingleProgramWorkflowReturnsOneNodeGraph)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString(R"(

            @begin w

                @begin b
                @end b

            @end w

        )");

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId, "w");

        Assert::AreEqual(
            "digraph w {"   EOL
            "b"             EOL
            "}"             EOL
            , dotText);
    }

    YW_TEST(WorkflowGrapher, TwoProgramWorkflowReturnsTwoNodeGraph)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString(R"(

            @begin w

                @begin b1
                @end b1

                @begin b2
                @end b2

            @end w

        )");

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId, "w");

        Assert::AreEqual(
            "digraph w {"   EOL
            "b1"            EOL
            "b2"            EOL
            "}"             EOL
            , dotText);
    }

    YW_TEST(WorkflowGrapher, WithThreeTopLevelProgramBlocksNamedBlockIsWorkflowRendered)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString(R"(

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

        WorkflowGrapher grapher{ ywdb };
        auto dotText = grapher.graph(modelId, "v");

        Assert::AreEqual(
            "digraph v {"   EOL
            "b1"            EOL
            "b2"            EOL
            "}"             EOL
            , dotText);
    }

    YW_TEST(WorkflowGrapher, WorkflowWithTwoProgramsAndOneChannelYieldsThreeNodes)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString(R"(

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
        auto dotText = grapher.graph(modelId, "w");

        Assert::AreEqual(
            "digraph w {"   EOL
            "b1"            EOL
            "b2"            EOL
            "d1"            EOL
            "d1 -> b2"      EOL
            "b1 -> d1"      EOL
            "}"             EOL
            , dotText);
    }

    YW_TEST(WorkflowGrapher, WorkflowWithTwoProgramsTwoChannelsYieldsFourNodes)
    {
        ModelBuilder builder(ywdb);
        builder.buildModelFromString(R"(

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
        auto dotText = grapher.graph(modelId, "w");

        Assert::AreEqual(
            "digraph w {"   EOL
            "b1"            EOL
            "b2"            EOL
            "d1"            EOL
            "d2"            EOL
            "d1 -> b2"      EOL
            "d2 -> b2"      EOL
            "b1 -> d1"      EOL
            "b1 -> d2"      EOL
            "}"             EOL
            , dotText);
    }


YW_TEST_END
