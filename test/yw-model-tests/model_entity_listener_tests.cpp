#include "yw_model_tests.h"

using namespace yw;
using namespace yw::model;
using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;

using Tag = yw::db::Annotation::Tag;

YW_TEST_FIXTURE(ModelEntityListener)

    YesWorkflowDB ywdb;
    row_id modelId, extractionId, sourceId;
    std::shared_ptr<SourceLoader> sourceLoader;
    ModelEntityListener* listener;
    StderrRecorder stderrRecorder;

    void storeAndParse(const std::string& code) {
        sourceLoader->insertSourceLinesFromString(sourceId, code);
        YWParserBuilder parser_builder(code);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
    }

    YW_TEST_SETUP(ModelEntityListener) {

        row_id userId;

        Expect::AreEqual(1, (userId = ywdb.insert(User{ auto_id, "user1" })));
        Expect::AreEqual(1, (extractionId = ywdb.insert(Extraction{ auto_id, userId, "2017-06-22 10:52:00.000" })));
        Expect::AreEqual(1, (sourceId = ywdb.insert(Source{ auto_id, null_id, "C" })));
        Expect::AreEqual(1, (modelId = ywdb.insert(Model{ auto_id, userId, extractionId, "2017-06-22 10:52:00.000" })));

        sourceLoader = std::make_shared<SourceLoader>(ywdb);
        listener = new ModelEntityListener{ ywdb, modelId, extractionId, sourceId };
    }

YW_TEST_SET

    YW_TEST(ModelEntityListener, WhenBeginAnnotationAtStartOfOnlyLineInsertOneBlockWithNullWorkflowId)
    {
        this->storeAndParse(R"(

            @begin b

        )");

        Expect::NonEmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        auto programBlock = ywdb.selectProgramBlockById(1);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, programBlock);
        Assert::IsTrue(! programBlock.workflowId.hasValue());
    }

    YW_TEST(ModelEntityListener, WhenBeginAndEndAtStartOfOnlyLineInsertOneBlockWithNullWorkflowId)
    {
        this->storeAndParse(R"(
        
            @begin b @end b
        
        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        auto programBlock = ywdb.selectProgramBlockById(1);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, programBlock);
        Assert::IsFalse(programBlock.workflowId.hasValue());
    }

    YW_TEST(ModelEntityListener, WhenTwoBeginEndPairsAtTopLevelSecondOfTwoBlocksHasNullWorkflowId)
    {
        this->storeAndParse(R"(
            
            @begin b
            @end b

            @begin c
            @end c

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(2, ywdb.getRowCount("program_block"));

        auto programBlock2 = ywdb.selectProgramBlockById(2);
        Assert::AreEqual(ProgramBlock{ 2, modelId, null_id, 3, "c" }, programBlock2);
        Assert::IsFalse(programBlock2.workflowId.hasValue());
    }

    YW_TEST(ModelEntityListener, WhenTwoBeginEndPairsAreNestedAtTopLevelWorkflowIdOfNestedBlockIsIdOfTopBlock)
    {
        this->storeAndParse(R"(

            @begin b
                @begin c
                @end c
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(2, ywdb.getRowCount("program_block"));

        auto topProgramBlock = ywdb.selectProgramBlockById(1);
        auto nestedProgramBlock = ywdb.selectProgramBlockById(2);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, topProgramBlock);
        Assert::AreEqual(ProgramBlock{ 2, modelId, 1, 2, "c" }, nestedProgramBlock);
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock.workflowId.getValue());
    }

    YW_TEST(ModelEntityListener, WhenTwoBlocksAreNestedInsideTopLevelWorkflowIdOfSecondNestedBlockIsIdOfTopBlock)
    {
        this->storeAndParse(R"(

            @begin b
            
                @begin c
                @end c
                
                @begin d
                @end d
            
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(3, ywdb.getRowCount("program_block"));

        auto topProgramBlock = ywdb.selectProgramBlockById(1);
        auto nestedProgramBlock1 = ywdb.selectProgramBlockById(2);
        auto nestedProgramBlock2 = ywdb.selectProgramBlockById(3);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, topProgramBlock);
        Assert::AreEqual(ProgramBlock{ 2, modelId, 1, 2, "c" }, nestedProgramBlock1);
        Assert::AreEqual(ProgramBlock{ 3, modelId, 1, 4, "d" }, nestedProgramBlock2);
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock1.workflowId.getValue());
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock2.workflowId.getValue());
    }

    YW_TEST(ModelEntityListener, WhenBlockIsDoublyNestedItsWorkflowIdIsIdOfImmediateParentBlock)
    {
        this->storeAndParse(R"(
            
            @begin b
                @begin c
                    @begin d
                    @end d
                @end c
            @end b
        
        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(3, ywdb.getRowCount("program_block"));

        auto topProgramBlock = ywdb.selectProgramBlockById(1);
        auto nestedProgramBlock = ywdb.selectProgramBlockById(2);
        auto doublyNestedProgramBlock = ywdb.selectProgramBlockById(3);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, topProgramBlock);
        Assert::AreEqual(ProgramBlock{ 2, modelId, 1, 2, "c" }, nestedProgramBlock);
        Assert::AreEqual(ProgramBlock{ 3, modelId, 2, 3, "d" }, doublyNestedProgramBlock);
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock.workflowId.getValue());
        Assert::AreEqual(nestedProgramBlock.id.getValue(), doublyNestedProgramBlock.workflowId.getValue());
    }

    YW_TEST(ModelEntityListener, WhenNestedBlockFollowsDoublyNestedBlockItsWorkflowIdIsIdOfTopBlock)
    {
        this->storeAndParse(R"(
            
            @begin b
                
                @begin c
                    @begin d
                    @end d
                @end c
                
                @begin e
                @end e
            
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(4, ywdb.getRowCount("program_block"));

        auto topProgramBlock = ywdb.selectProgramBlockById(1);
        auto nestedProgramBlock1 = ywdb.selectProgramBlockById(2);
        auto doublyNestedProgramBlock = ywdb.selectProgramBlockById(3);
        auto nestedProgramBlock2 = ywdb.selectProgramBlockById(4);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, topProgramBlock);
        Assert::AreEqual(ProgramBlock{ 2, modelId, 1, 2, "c" }, nestedProgramBlock1);
        Assert::AreEqual(ProgramBlock{ 3, modelId, 2, 3, "d" }, doublyNestedProgramBlock);
        Assert::AreEqual(ProgramBlock{ 4, modelId, 1, 6, "e" }, nestedProgramBlock2);
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock1.workflowId.getValue());
        Assert::AreEqual(nestedProgramBlock1.id.getValue(), doublyNestedProgramBlock.workflowId.getValue());
        Assert::AreEqual(topProgramBlock.id.getValue(), nestedProgramBlock2.workflowId.getValue());
    }

    YW_TEST(ModelEntityListener, WhenSecondTopBlockFollowsDoublyNestedBlocksItsWorkflowIdIsNull)
    {
        this->storeAndParse(R"(

            @begin b
                @begin c
                    @begin d
                    @end d
                @end c
            @end b

            @begin e
            @end e

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(4, ywdb.getRowCount("program_block"));

        auto topProgramBlock1 = ywdb.selectProgramBlockById(1);
        auto nestedProgramBlock = ywdb.selectProgramBlockById(2);
        auto doublyNestedProgramBlock = ywdb.selectProgramBlockById(3);
        auto topProgramBlock2 = ywdb.selectProgramBlockById(4);
        Assert::AreEqual(ProgramBlock{ 1, modelId, null_id, 1, "b" }, topProgramBlock1);
        Assert::AreEqual(ProgramBlock{ 2, modelId, 1, 2, "c" }, nestedProgramBlock);
        Assert::AreEqual(ProgramBlock{ 3, modelId, 2, 3, "d" }, doublyNestedProgramBlock);
        Assert::AreEqual(ProgramBlock{ 4, modelId, null_id, 7, "e" }, topProgramBlock2);
        Assert::AreEqual(topProgramBlock1.id.getValue(), nestedProgramBlock.workflowId.getValue());
        Assert::AreEqual(nestedProgramBlock.id.getValue(), doublyNestedProgramBlock.workflowId.getValue());
        Assert::IsFalse(topProgramBlock2.workflowId.hasValue());
    }

    YW_TEST(ModelEntityListener, WhenInPortHasOneNameInsertOnePortOneFlowAndOneDataBlock)
    {
        this->storeAndParse(R"(

            @begin b
            @in p
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(1, ywdb.getRowCount("port"));
        Assert::AreEqual(1, ywdb.getRowCount("flow"));
        Assert::AreEqual(1, ywdb.getRowCount("data_block"));
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, ywdb.selectPortById(1));
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "p" }, ywdb.selectDataBlockById(1));
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
    }

    YW_TEST(ModelEntityListener, WhenInPortHasTwoNamesInsertTwoPorts)
    {
        this->storeAndParse(R"(

            @begin b
            @in p q
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(2, ywdb.getRowCount("port"));
        Assert::AreEqual(2, ywdb.getRowCount("flow"));
        Assert::AreEqual(2, ywdb.getRowCount("data_block"));
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, ywdb.selectPortById(1));
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "p" }, ywdb.selectDataBlockById(1));
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual(Port{ 2, 1, 3, "q" }, ywdb.selectPortById(2));
        Assert::AreEqual(DataBlock{ 2, modelId, null_id, "q" }, ywdb.selectDataBlockById(2));
        Assert::AreEqual(Flow{ 2, 2, 2, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(2));
    }

    YW_TEST(ModelEntityListener, WhenTwoInPortsInsertTwoPorts)
    {
        this->storeAndParse(R"(

            @begin b
            @in p
            @in q
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(2, ywdb.getRowCount("port"));
        Assert::AreEqual(2, ywdb.getRowCount("flow"));
        Assert::AreEqual(2, ywdb.getRowCount("data_block"));
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, ywdb.selectPortById(1));
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "p" }, ywdb.selectDataBlockById(1));
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual(Port{ 2, 1, 3, "q" }, ywdb.selectPortById(2));
        Assert::AreEqual(DataBlock{ 2, modelId, null_id, "q" }, ywdb.selectDataBlockById(2));
        Assert::AreEqual(Flow{ 2, 2, 2, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(2));
    }

    YW_TEST(ModelEntityListener, WhenTwoOutPortsInsertTwoPorts)
    {
        this->storeAndParse(R"(

            @begin b
            @out p
            @out q
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(2, ywdb.getRowCount("port"));
        Assert::AreEqual(2, ywdb.getRowCount("flow"));
        Assert::AreEqual(2, ywdb.getRowCount("data_block"));
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, ywdb.selectPortById(1));
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "p" }, ywdb.selectDataBlockById(1));
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::OUT, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual(Port{ 2, 1, 3, "q" }, ywdb.selectPortById(2));
        Assert::AreEqual(DataBlock{ 2, modelId, null_id, "q" }, ywdb.selectDataBlockById(2));
        Assert::AreEqual(Flow{ 2, 2, 2, Flow::Direction::OUT, 1, 1 }, ywdb.selectFlowById(2));
    }

    YW_TEST(ModelEntityListener, WhenInPortHasAliasPortTakesNameAndDataBlockTakesAlias)
    {
        this->storeAndParse(R"(

            @begin b
            @in p @as d
            @end b

       )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(1, ywdb.getRowCount("port"));
        Assert::AreEqual(1, ywdb.getRowCount("flow"));
        Assert::AreEqual(1, ywdb.getRowCount("data_block"));
        auto port = ywdb.selectPortById(1);
        auto dataBlock = ywdb.selectDataBlockById(1);
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, port);
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "d" }, dataBlock);
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual("p", port.name);
        Assert::AreEqual("d", dataBlock.name);
    }

    YW_TEST(ModelEntityListener, WhenInPortWithTwoPortNamesHasAliasDataForFirstPortTakesNameAndDataForSecondPortTakesAlias)
    {
        this->storeAndParse(R"(

            @begin b
            @in p q @as d
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(2, ywdb.getRowCount("port"));
        Assert::AreEqual(2, ywdb.getRowCount("flow"));
        Assert::AreEqual(2, ywdb.getRowCount("data_block"));
        auto port1 = ywdb.selectPortById(1);
        auto dataBlock1 = ywdb.selectDataBlockById(1);
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, port1);
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "p" }, dataBlock1);
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual("p", port1.name);
        Assert::AreEqual("p", dataBlock1.name);
        auto port2 = ywdb.selectPortById(2);
        auto dataBlock2 = ywdb.selectDataBlockById(2);
        Assert::AreEqual(Port{ 2, 1, 3, "q" }, port2);
        Assert::AreEqual(DataBlock{ 2, modelId, null_id, "d" }, dataBlock2);
        Assert::AreEqual(Flow{ 2, 2, 2, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(2));
        Assert::AreEqual("q", port2.name);
        Assert::AreEqual("d", dataBlock2.name);
    }

    YW_TEST(ModelEntityListener, WhenFirstInPortHasAliasAndSecondInPortDoesNotDataBlockForFirstPortTakesAlias)
    {
        this->storeAndParse(R"(

            @begin b
            @in p @as d
            @in q
            @end b

        )");

        Expect::EmptyString(stderrRecorder.str());
        Expect::AreEqual(1, ywdb.getRowCount("program_block"));

        Assert::AreEqual(2, ywdb.getRowCount("port"));
        Assert::AreEqual(2, ywdb.getRowCount("flow"));
        Assert::AreEqual(2, ywdb.getRowCount("data_block"));
        auto port1 = ywdb.selectPortById(1);
        auto dataBlock1 = ywdb.selectDataBlockById(1);
        Assert::AreEqual(Port{ 1, 1, 2, "p" }, port1);
        Assert::AreEqual(DataBlock{ 1, modelId, null_id, "d" }, dataBlock1);
        Assert::AreEqual(Flow{ 1, 1, 1, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(1));
        Assert::AreEqual("p", port1.name);
        Assert::AreEqual("d", dataBlock1.name);
        auto port2 = ywdb.selectPortById(2);
        auto dataBlock2 = ywdb.selectDataBlockById(2);
        Assert::AreEqual(Port{ 2, 1, 4, "q" }, port2);
        Assert::AreEqual(DataBlock{ 2, modelId, null_id, "q" }, dataBlock2);
        Assert::AreEqual(Flow{ 2, 2, 2, Flow::Direction::IN, 1, 1 }, ywdb.selectFlowById(2));
        Assert::AreEqual("q", port2.name);
        Assert::AreEqual("q", dataBlock2.name);
    }

YW_TEST_END
