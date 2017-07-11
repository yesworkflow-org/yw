#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(ModelTable)

    YesWorkflowDB ywdb{ false };

	YW_TEST_SETUP(ModelTable)
	{
		ywdb.createUserTable();
		ywdb.createModelTable();
	}

YW_TEST_SET

    YW_TEST(ModelTable, InsertOneRow_GeneratedIdIs_1)
    {
        long userId, modelId;
        Assert::AreEqual(1, (userId = ywdb.insertUser("user1")));
        Assert::AreEqual(1, (modelId = ywdb.insertModel(userId, "2017-06-22 10:52:00.000")));
    }

    YW_TEST(ModelTable, InsertTwoRows_SecondGeneratedIdIs_2)
    {
        long user1;
        Assert::AreEqual(1, user1 = ywdb.insertUser("user1"));
        long model1, model2;
        Assert::AreEqual(1, (model1 = ywdb.insertModel(user1, "2017-06-22 10:52:00.000")));
        Assert::AreEqual(2, (model2 = ywdb.insertModel(user1, "2017-06-22 10:52:01.000")));
    }

    YW_TEST(ModelTable, SelectModelById_RowExists) {
        long user1, user2, user3;
        Assert::AreEqual(1, (user1 = ywdb.insertUser("user1")));
        Assert::AreEqual(2, (user2 = ywdb.insertUser("user2")));
        Assert::AreEqual(3, (user3 = ywdb.insertUser("user3")));
        long model1, model2;
        Assert::AreEqual(1, model1 = ywdb.insertModel(user2, "2017-06-22 10:52:00.000"));
        Assert::AreEqual(2, model2 = ywdb.insertModel(user3, "2017-06-22 10:52:01.000"));
        auto model = ywdb.selectModelById(2L);
        Assert::AreEqual(2, model.id);
        Assert::AreEqual(3, model.creator);
        Assert::AreEqual(std::string("2017-06-22 10:52:01.000"), model.create_date);
    }

    YW_TEST(ModelTable, SelectModelById_RowDoesntExist) {
        try {
            auto user = ywdb.selectModelById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END