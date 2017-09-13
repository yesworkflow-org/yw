
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

        Assert::AreEqual(
            "digraph b {"   EOL
            "}"             EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph w {"   EOL
            "b"             EOL
            "}"             EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph w {"                                                       EOL
            ""                                                                  EOL
            "/* Nodes representing program blocks in workflow */"               EOL
            "b"                                                                 EOL
            "}"                                                                 EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph w {"                                                       EOL
            ""                                                                  EOL
            "/* Nodes representing program blocks in workflow */"               EOL
            "b1"                                                                EOL
            "b2"                                                                EOL
            "}"                                                                 EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph v {"                                                       EOL
            ""                                                                  EOL
            "/* Nodes representing program blocks in workflow */"               EOL
            "b1"                                                                EOL
            "b2"                                                                EOL
            "}"                                                                 EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph w {"                                                       EOL
            ""                                                                  EOL
            "/* Nodes representing program blocks in workflow */"               EOL
            "b1"                                                                EOL
            "b2"                                                                EOL
            ""                                                                  EOL
            "/* Nodes representing data blocks in workflow */"                  EOL
            "d1"                                                                EOL
            ""                                                                  EOL
            "/* Edges representing flow of data into and out of code blocks */" EOL
            "d1 -> b2"                                                          EOL
            "b1 -> d1"                                                          EOL
            "}"                                                                 EOL
            , dotText);
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

        Assert::AreEqual(
            "digraph w {"                                                       EOL
            ""                                                                  EOL
            "/* Nodes representing program blocks in workflow */"               EOL
            "b1"                                                                EOL
            "b2"                                                                EOL
            ""                                                                  EOL
            "/* Nodes representing data blocks in workflow */"                  EOL
            "d1"                                                                EOL
            "d2"                                                                EOL
            ""                                                                  EOL
            "/* Edges representing flow of data into and out of code blocks */" EOL
            "d1 -> b2"                                                          EOL
            "d2 -> b2"                                                          EOL
            "b1 -> d1"                                                          EOL
            "b1 -> d2"                                                          EOL
            "}"                                                                 EOL
            , dotText);
    }

YW_TEST_END
