
#include "yw_graph_tests.h"
#include "model_entity_listener.h"
#include "workflow_grapher.h"

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
    row_id modelId, sourceId;
    std::shared_ptr<SourceLoader> sourceLoader;
    ModelEntityListener* listener;
    StderrRecorder stderrRecorder;
    Configuration grapherConfiguration;

    void storeAndParse(const std::string& code) {
        sourceLoader->insertSourceLinesFromString(sourceId, code);
        YWParserBuilder parser_builder(code);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
    }

    YW_TEST_SETUP(WorkflowGrapher) {

        row_id userId, extractionId;

        Expect::AreEqual(1, (userId = ywdb.insert(User{ auto_id, "user1" })));
        Expect::AreEqual(1, (extractionId = ywdb.insert(Extraction{ auto_id, userId, "2017-06-22 10:52:00.000" })));
        Expect::AreEqual(1, (sourceId = ywdb.insert(Source{ auto_id, null_id, "C" })));
        Expect::AreEqual(1, (modelId = ywdb.insert(Model{ auto_id, userId, extractionId, "2017-06-22 10:52:00.000" })));

        sourceLoader = std::make_shared<SourceLoader>(ywdb);
        listener = new ModelEntityListener{ ywdb, modelId, extractionId, sourceId };
    }

YW_TEST_SET

    YW_TEST(WorkflowGrapher, EmptyWorkflowReturnsEmptyGraph)
    {
        this->storeAndParse( R"(
            
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
        this->storeAndParse( R"(

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
        this->storeAndParse(R"(

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
        this->storeAndParse(R"(

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

YW_TEST_END
