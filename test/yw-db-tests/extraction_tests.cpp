#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(Extraction)

    YesWorkflowDB ywdb { false };
    row_id user4, user19, user101;

    YW_TEST_SETUP(Extraction)
    {
        ywdb.createUserTable();
        Expect::AreEqual(4, ywdb.insert(User{ (user4 = 4), "user1" }));
        Expect::AreEqual(19, ywdb.insert(User{ (user19 = 19), "user2" }));
        Expect::AreEqual(101, ywdb.insert(User{ (user101 = 101), "user3" }));

        ywdb.createExtractionTable();
    }

YW_TEST_SET

    YW_TEST(Extraction, InsertOneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(Extraction{ auto_id, user4, "2017-06-22 10:52:00.000" }));
    }

    YW_TEST(Extraction, InsertTwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(Extraction{ auto_id, user4, "2017-06-22 10:52:00.000" }));

        Assert::AreEqual(2, ywdb.insert(Extraction{ auto_id, user19, "2017-06-22 10:52:01.000" }));
    }

    YW_TEST(Extraction, SelectById_RowExists) {

        Expect::AreEqual(1, ywdb.insert(Extraction{ auto_id, user19, "2017-06-22 10:52:00.000" }));
        Expect::AreEqual(2, ywdb.insert(Extraction{ auto_id, user101, "2017-06-22 10:52:01.000" }));

        auto extraction = ywdb.selectExtractionById(2L);
        Assert::AreEqual(2, extraction.id.getValue());
        Assert::AreEqual(101, extraction.userId.getValue());
        Assert::AreEqual(std::string("2017-06-22 10:52:01.000"), extraction.created);
    }

    YW_TEST(Extraction, SelectById_RowDoesntExist) {
        try {
            auto user = ywdb.selectExtractionById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No extraction row with that id", e.what());
        }
    }

YW_TEST_END