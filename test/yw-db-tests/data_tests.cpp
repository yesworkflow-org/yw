#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(DataBlock)

    YesWorkflowDB ywdb { false };

    YW_TEST_SETUP(DataBlock)
    {
        ywdb.createDataBlockTable();
    }

YW_TEST_SET

    YW_TEST(DataBlock, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(DataBlock{ auto_id, null_id, "d" }));
    }

    YW_TEST(DataBlock, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(DataBlock{ auto_id, null_id, "d" }));
        Assert::AreEqual(2, ywdb.insert(DataBlock{ auto_id, 1, "e" }));
    }

    YW_TEST(DataBlock, SelectById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(DataBlock{ auto_id, null_id, "d" }));
        Expect::AreEqual(2, ywdb.insert(DataBlock{ auto_id, 1, "e" }));

        auto data = ywdb.selectDataBlockById(2L);
        Assert::AreEqual(2, data.id.getValue());
        Assert::AreEqual(1, data.structureId.getValue());
        Assert::AreEqual("e", data.name);
    }
    
    YW_TEST(DataBlock, SelectById_RowDoesntExist) {
        try {
            auto source = ywdb.selectDataBlockById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No data block with that id", e.what());
        }
    }

YW_TEST_END