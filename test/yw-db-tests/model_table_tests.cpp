#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(ModelTable)

   YesWorkflowDB ywdb{ false };
	long user4, user19, user101;

	YW_TEST_SETUP(ModelTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(4, ywdb.insert(UserRow{ (user4 = 4), "user1" }));
		Expect::AreEqual(19, ywdb.insert(UserRow{ (user19 = 19), "user2" }));
		Expect::AreEqual(101, ywdb.insert(UserRow{ (user101 = 101), "user3" }));

		ywdb.createModelTable();
	}

YW_TEST_SET

    YW_TEST(ModelTable, InsertOneRow_GeneratedIdIs_1)
    {		
		Assert::AreEqual(1, ywdb.insert(ModelRow{ auto_id, user4, "2017-06-22 10:52:00.000" }));
    }

    YW_TEST(ModelTable, InsertTwoRows_SecondGeneratedIdIs_2)
    {
		Expect::AreEqual(1, ywdb.insert(ModelRow{ auto_id, user4, "2017-06-22 10:52:00.000" }));
		
		Assert::AreEqual(2, ywdb.insert(ModelRow{ auto_id, user19, "2017-06-22 10:52:01.000" }));
    }

    YW_TEST(ModelTable, SelectModelById_RowExists) {
        
		Expect::AreEqual(1, ywdb.insert(ModelRow{ auto_id, user19, "2017-06-22 10:52:00.000" }));
		Expect::AreEqual(2, ywdb.insert(ModelRow{ auto_id, user101, "2017-06-22 10:52:01.000" }));

		auto model = ywdb.selectModelById(2L);
        Assert::AreEqual(2, model.id.getValue());
        Assert::AreEqual(101, model.userId);
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