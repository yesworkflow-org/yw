#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(Data)

    YesWorkflowDB ywdb { false };

    YW_TEST_SETUP(Data)
    {
        ywdb.createDataTable();
    }

YW_TEST_SET

    YW_TEST(Data, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(Data{ auto_id, null_id, "d" }));
    }

    YW_TEST(Data, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(Data{ auto_id, null_id, "d" }));
        Assert::AreEqual(2, ywdb.insert(Data{ auto_id, 1, "e" }));
    }

    YW_TEST(Data, SelectById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(Data{ auto_id, null_id, "d" }));
        Expect::AreEqual(2, ywdb.insert(Data{ auto_id, 1, "e" }));

        auto data = ywdb.selectDataById(2L);
        Assert::AreEqual(2, data.id.getValue());
        Assert::AreEqual(1, data.partOfId.getValue());
        Assert::AreEqual("e", data.name);
    }
    
    YW_TEST(Data, SelectById_RowDoesntExist) {
        try {
            auto source = ywdb.selectDataById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No data row with that id", e.what());
        }
    }

YW_TEST_END