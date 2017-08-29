#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(DataBlock)

    YesWorkflowDB ywdb { false };
    row_id model28;

    YW_TEST_SETUP(DataBlock)
    {
        ywdb.createUserTable();
        ywdb.createExtractionTable();

        ywdb.createModelTable();
        Expect::AreEqual(28, ywdb.insert(Model{ (model28 = 28), null_id, null_id, "2017-06-22 10:52:00.000" }));

        ywdb.createProgramBlockTable();
        ywdb.createDataBlockTable();
    }
          
YW_TEST_SET

    YW_TEST(DataBlock, FieldValuesMatchAssignedValuesWithNulls) {
        Assert::AreEqual(
            "NULL|28|NULL|NULL|d1", 
            DataBlock{ auto_id, 28, null_id, null_id, "d1" }.fieldValues()
        );
    }

    YW_TEST(DataBlock, FieldValuesMatchAssignedValuesWithoutNulls) {
        Assert::AreEqual(
            "7|28|2|17|d2", 
            DataBlock{ 7, 28, 2, 17, "d2" }.fieldValues()
        );
    }

    YW_TEST(DataBlock, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(DataBlock{ auto_id, model28, null_id, null_id, "d" }));
    }

    YW_TEST(DataBlock, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(DataBlock{ auto_id, model28, null_id, null_id, "d" }));
        Assert::AreEqual(2, ywdb.insert(DataBlock{ auto_id, model28, null_id, 1, "e" }));
    }

    YW_TEST(DataBlock, SelectById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(DataBlock{ auto_id, model28, null_id, null_id, "d" }));
        Expect::AreEqual(2, ywdb.insert(DataBlock{ auto_id, model28, null_id, 1, "e" }));

        auto data = ywdb.selectDataBlockById(2);
        Assert::AreEqual(2L, data.id);
        Assert::AreEqual(28, data.modelId);
        Assert::AreEqual(1L, data.structureId);
        Assert::AreEqual("e", data.name);
    }
    
    YW_TEST(DataBlock, SelectById_RowDoesntExist) {
        try {
            auto source = ywdb.selectDataBlockById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No data block with that id", e.what());
        }
    }

YW_TEST_END