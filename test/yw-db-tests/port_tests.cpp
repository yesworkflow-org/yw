#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;
using Tag = yw::db::Annotation::Tag;

YW_TEST_FIXTURE(Port)

    YesWorkflowDB ywdb { false };
    row_id user13;
    row_id extraction17;
    row_id source8;
    row_id line19, line25, line119, line125;
    row_id annotation11, annotation16, annotation22, annotation36;
    row_id model77;
    row_id block1, block2;

    YW_TEST_SETUP(Port)
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
        Expect::AreEqual(125, ywdb.insert(Line{ (line125 = 125), source8, 14, "@in second port" }));

        ywdb.createAnnotationTable();
        Expect::AreEqual(11, ywdb.insert(Annotation{ (annotation11 = 11), extraction17, Tag::BEGIN, null_id, line19, 1, 0, 11, "@begin", "block" }));
        Assert::AreEqual(16, ywdb.insert(Annotation{ (annotation16 = 16), extraction17, Tag::IN, annotation11, line25, 1, 0, 7, "@in", "port" }));
        Expect::AreEqual(22, ywdb.insert(Annotation{ (annotation22 = 22), extraction17, Tag::BEGIN, annotation11, line119, 1, 0, 18, "@begin", "nested block" }));
        Assert::AreEqual(36, ywdb.insert(Annotation{ (annotation36 = 36), extraction17, Tag::IN, annotation22, line125, 1, 0, 14, "@in", "second port" }));

        ywdb.createModelTable();
        Expect::AreEqual(77, ywdb.insert(Model{ (model77 = 77), user13, extraction17, "2017-06-22 10:52:00.000" }));

        ywdb.createProgramBlockTable();
        Expect::AreEqual(1, (block1 = ywdb.insert(ProgramBlock{ auto_id, model77, null_id, annotation11, "block" })));
        Expect::AreEqual(2, (block2 = ywdb.insert(ProgramBlock{ auto_id, model77, block1, annotation22, "nested block" })));

        ywdb.createPortTable();
    }

YW_TEST_SET

    YW_TEST(Port, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(Port{ auto_id, block1, annotation16, "port" }));
    }

    YW_TEST(Port, InsertTwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(Port{ auto_id, block1, annotation16, "port" }));
        Assert::AreEqual(2, ywdb.insert(Port{ auto_id, block2, annotation36, "second port" }));
    }

    YW_TEST(Port, SelectById_RowExists) {

        Expect::AreEqual(1, ywdb.insert(Port{ auto_id, block1, annotation16, "port" }));
        Expect::AreEqual(2, ywdb.insert(Port{ auto_id, block2, annotation36, "second port" }));

        auto port = ywdb.selectPortById(2);
        Assert::AreEqual(2, port.id.getValue());
        Assert::AreEqual(2, port.programBlockId);
        Assert::AreEqual(36, port.annotationId.getValue());
        Assert::AreEqual(std::string("second port"), port.name);
    }
    
    YW_TEST(Port, SelectById_RowDoesntExist) {
        try {
            auto user = ywdb.selectPortById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No port row with that id", e.what());
        }
    }

YW_TEST_END