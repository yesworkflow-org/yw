#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(DataTable)

    YesWorkflowDB ywdb { false };

    YW_TEST_SETUP(DataTable)
    {
        ywdb.createDataTable();
    }

YW_TEST_SET

    YW_TEST(DataTable, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(DataRow{ auto_id, null_id, "d" }));
    }

    YW_TEST(DataTable, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(DataRow{ auto_id, null_id, "d" }));
        Assert::AreEqual(2, ywdb.insert(DataRow{ auto_id, 1, "e" }));
    }

    YW_TEST(DataTable, SelectById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(DataRow{ auto_id, null_id, "d" }));
        Expect::AreEqual(2, ywdb.insert(DataRow{ auto_id, 1, "e" }));

        auto data = ywdb.selectDataById(2L);
        Assert::AreEqual(2, data.id.getValue());
        Assert::AreEqual(1, data.partOfId.getValue());
        Assert::AreEqual("e", data.name);
    }
    
    YW_TEST(DataTable, SelectById_RowDoesntExist) {
        try {
            auto source = ywdb.selectDataById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No data row with that id", e.what());
        }
    }

YW_TEST_END