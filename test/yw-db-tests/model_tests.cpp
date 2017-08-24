#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(Model)

    YesWorkflowDB ywdb { false };
    row_id user4, user19, user101;
    row_id extraction2, extraction13;

    YW_TEST_SETUP(Model)
    {
        ywdb.createUserTable();
        Expect::AreEqual(4, ywdb.insert(User{ (user4 = 4), "user1" }));
        Expect::AreEqual(19, ywdb.insert(User{ (user19 = 19), "user2" }));
        Expect::AreEqual(101, ywdb.insert(User{ (user101 = 101), "user3" }));

        ywdb.createExtractionTable();
        Expect::AreEqual(2, ywdb.insert(Extraction{ {extraction2 = 2}, user19, "2017-06-22 10:52:00.000" }));
        Expect::AreEqual(13, ywdb.insert(Extraction{ {extraction13 = 13}, user101, "2017-06-22 10:52:01.000" }));

        ywdb.createModelTable();
    }

YW_TEST_SET

    YW_TEST(Model, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(Model{ auto_id, user4, extraction2, "2017-06-22 10:52:00.000" }));
    }

    YW_TEST(Model, InsertTwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(Model{ auto_id, user4, extraction2, "2017-06-22 10:52:00.000" }));
        Assert::AreEqual(2, ywdb.insert(Model{ auto_id, user19, extraction13, "2017-06-22 10:52:00.000" }));
    }

    YW_TEST(Model, SelectById_RowExists) {

        Expect::AreEqual(1, ywdb.insert(Model{ auto_id, user4, extraction2, "2017-06-22 10:52:00.000" }));
        Expect::AreEqual(2, ywdb.insert(Model{ auto_id, user19, extraction13, "2017-06-22 10:52:00.000" }));

        auto model = ywdb.selectModelById(2);
        Assert::AreEqual(2L, model.id);
        Assert::AreEqual(19L, model.userId);
        Assert::AreEqual(13L, model.extractionId);
        Assert::AreEqual(std::string("2017-06-22 10:52:00.000"), model.created);
    }
    
    YW_TEST(Model, SelectById_RowDoesntExist) {
        try {
            auto user = ywdb.selectModelById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No model row with that id", e.what());
        }
    }

YW_TEST_END