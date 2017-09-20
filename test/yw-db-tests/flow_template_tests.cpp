#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

using Tag = yw::db::Annotation::Tag;
using Direction = yw::db::Flow::Direction;

YW_TEST_FIXTURE(FlowTemplate)

    YesWorkflowDB ywdb { false };
    row_id user13;
    row_id extraction17;
    row_id source8;
    row_id line19, line25, line119, line125;
    row_id annotation11, annotation16, annotation22, annotation36;
    row_id model77;
    row_id block12, block13;
    row_id port28, port88;
    row_id data5, data92;
    row_id flow8, flow99;

    YW_TEST_SETUP(FlowTemplate)
    {
        ywdb.createUserTable();
        Expect::AreEqual(13, ywdb.insert(User{ (user13 = 13), "user1" }));

        ywdb.createExtractionTable();
        Expect::AreEqual(17, ywdb.insert(Extraction{ (extraction17 = 17), user13, "2017-06-22 10:52:00.000" }));

        ywdb.createFileTable();

        ywdb.createSourceTable();
        Expect::AreEqual(8, ywdb.insert(Source{ (source8 = 8), null_id, "C" }));

        ywdb.createLineTable();
        Expect::AreEqual(19, ywdb.insert(Line{ (line19 = 19), source8, 1, "@begin block" }));
        Expect::AreEqual(25, ywdb.insert(Line{ (line25 = 25), source8, 4, "@in port" }));
        Expect::AreEqual(119, ywdb.insert(Line{ (line119 = 119), source8, 11, "@begin nested block" }));
        Expect::AreEqual(125, ywdb.insert(Line{ (line125 = 125), source8, 14, "@out second port" }));

        ywdb.createAnnotationTable();
        Expect::AreEqual(11, ywdb.insert(Annotation{ (annotation11 = 11), extraction17, Tag::BEGIN, null_id, line19, 1, 0, 11, "@begin", "block" }));
        Assert::AreEqual(16, ywdb.insert(Annotation{ (annotation16 = 16), extraction17, Tag::IN, annotation11, line25, 1, 0, 7, "@in", "port" }));
        Expect::AreEqual(22, ywdb.insert(Annotation{ (annotation22 = 22), extraction17, Tag::BEGIN, annotation11, line119, 1, 0, 18, "@begin", "nested block" }));
        Assert::AreEqual(36, ywdb.insert(Annotation{ (annotation36 = 36), extraction17, Tag::IN, annotation22, line125, 1, 0, 16, "@out", "second port" }));

        ywdb.createModelTable();
        Expect::AreEqual(77, ywdb.insert(Model{ (model77 = 77), user13, extraction17, "2017-06-22 10:52:00.000" }));

        ywdb.createProgramBlockTable();
        Expect::AreEqual(12, (ywdb.insert(ProgramBlock{ (block12 = 12), model77, null_id, annotation11, "block", null_string })));
        Expect::AreEqual(13, (ywdb.insert(ProgramBlock{ (block13 = 13), model77, block12, annotation22, "nested block", null_string })));

        ywdb.createPortTable();
        Expect::AreEqual(28, ywdb.insert(Port{ (port28 = 28), block12, annotation16, "port" }));
        Expect::AreEqual(88, ywdb.insert(Port{ (port88 = 88), block13, annotation36, "second port" }));

        ywdb.createDataBlockTable();
        Expect::AreEqual(5, ywdb.insert(DataBlock{ (data5 = 5), model77, null_id, null_id, "d" }));
        Expect::AreEqual(92, ywdb.insert(DataBlock{ (data92 = 92), model77, null_id, 5, "e" }));

        ywdb.createFlowTable();
        Expect::AreEqual(8, ywdb.insert(Flow{ (flow8 = 8), port28, data5, Direction::IN, 1, 2 }));
        Expect::AreEqual(99, ywdb.insert(Flow{ (flow99 = 99), port88, data92, Direction::OUT, 3, 4 }));

        ywdb.createFlowTemplateTable();
    }

YW_TEST_SET

    YW_TEST(FlowTemplate, FieldValuesMatchAssignedValuesWithNulls) {
        Assert::AreEqual(
            "NULL|8|NULL|/the/path",
            FlowTemplate{ auto_id, 8, null_string, "/the/path" }.fieldValues()
        );
    }

    YW_TEST(FlowTemplate, FieldValuesMatchAssignedValuesWithoutNulls) {
        Assert::AreEqual(
            "NULL|8|http|/the/path",
            FlowTemplate{ auto_id, 8, "http", "/the/path" }.fieldValues()
        );
    }

    YW_TEST(FlowTemplate, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(FlowTemplate{ auto_id, 8, "http", "/the/path" }));
    }

    YW_TEST(FlowTemplate, InsertTwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(FlowTemplate{ auto_id, 8, "http", "/the/path" }));
        Assert::AreEqual(2, ywdb.insert(FlowTemplate{ auto_id, 99, "file", "/another/path" }));
    }

    YW_TEST(FlowTemplate, SelectById_RowExists) {

        Expect::AreEqual(1, ywdb.insert(FlowTemplate{ auto_id, 8, "http", "/the/path" }));
        Assert::AreEqual(2, ywdb.insert(FlowTemplate{ auto_id, 99, "file", "/another/path" }));

        auto flowTemplate = ywdb.selectFlowTemplateById(2);
        Assert::AreEqual(2L, flowTemplate.id);
        Assert::AreEqual(99, flowTemplate.flow);
        Assert::AreEqual("file", flowTemplate.scheme.str());
        Assert::AreEqual("/another/path", flowTemplate.path);
    }
    
    YW_TEST(FlowTemplate, SelectById_RowDoesntExist) {
        try {
            auto user = ywdb.selectFlowTemplateById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No flow template with that id", e.what());
        }
    }

    YW_TEST(FlowTemplate, SelectByDataId_RowExists) {

        Expect::AreEqual(1, ywdb.insert(FlowTemplate{ auto_id, 8, "http", "/the/path" }));
        Assert::AreEqual(2, ywdb.insert(FlowTemplate{ auto_id, 99, "file", "/another/path" }));

        auto flowTemplates = ywdb.selectFlowTemplatesByDataId(92);
        Expect::AreEqual(1, flowTemplates.size());
        auto flowTemplate = flowTemplates[0];

        Assert::AreEqual(2L, flowTemplate.id);
        Assert::AreEqual(99, flowTemplate.flow);
        Assert::AreEqual("file", flowTemplate.scheme.str());
        Assert::AreEqual("/another/path", flowTemplate.path);
    }

YW_TEST_END