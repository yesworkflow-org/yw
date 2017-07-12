#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(ModelTable)

   YesWorkflowDB ywdb{ false };
	long user1, user2, user3;

	YW_TEST_SETUP(ModelTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(1, (user1 = ywdb.insert(UserRow{ "user1" })));
		Expect::AreEqual(2, (user2 = ywdb.insert(UserRow{ "user2" })));
		Expect::AreEqual(3, (user3 = ywdb.insert(UserRow{ "user3" })));

		ywdb.createModelTable();
	}

YW_TEST_SET

    YW_TEST(ModelTable, InsertOneRow_GeneratedIdIs_1)
    {		
		Assert::AreEqual(1, ywdb.insert(ModelRow{ user1, "2017-06-22 10:52:00.000" }));
    }

    YW_TEST(ModelTable, InsertTwoRows_SecondGeneratedIdIs_2)
    {
		Expect::AreEqual(1, ywdb.insert(ModelRow{ user1, "2017-06-22 10:52:00.000" }));
		
		Assert::AreEqual(2, ywdb.insert(ModelRow{ user2, "2017-06-22 10:52:01.000" }));
    }

    YW_TEST(ModelTable, SelectModelById_RowExists) {
        
		Expect::AreEqual(1, ywdb.insert(ModelRow{ user2, "2017-06-22 10:52:00.000" }));
		Expect::AreEqual(2, ywdb.insert(ModelRow{ user3, "2017-06-22 10:52:01.000" }));

		auto model = ywdb.selectModelById(2L);
        Assert::AreEqual(2, model.id);
        Assert::AreEqual(3, model.userId);
        Assert::AreEqual(std::string("2017-06-22 10:52:01.000"), model.creationDate);
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