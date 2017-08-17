#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(UserTable)

    YesWorkflowDB ywdb { false };

    YW_TEST_SETUP(UserTable)
    {
        ywdb.createUserTable();
    }

YW_TEST_SET

    YW_TEST(UserTable, InsertingFirstUserWithNameYieldsGeneratedId1)
    {
        Assert::AreEqual(1, ywdb.insert(UserRow{ auto_id, "user1" }));
    }

    YW_TEST(UserTable, InsertingFirstUserWithNoNameYieldsGeneratedId1)
    {
        Assert::AreEqual(1, ywdb.insert(UserRow{ auto_id, nullable_string{} }));
    }

    YW_TEST(UserTable, InsertingSecondUserWithNameYieldsGeneratedId2)
    {
        Expect::AreEqual(1, ywdb.insert(UserRow{ auto_id, "user1" }));

        Assert::AreEqual(2, ywdb.insert(UserRow{ auto_id, "user2" }));
    }

    YW_TEST(UserTable, SelectingExistingUserWithNameByIdYieldsAssignedName)
    {
        Expect::AreEqual(1, ywdb.insert(UserRow{ auto_id, "user1" }));

        auto user = ywdb.selectUserById(1L);
        Expect::AreEqual(1, user.id.getValue());
        Assert::AreEqual("user1", user.name.getValue());
    }

    YW_TEST(UserTable, SelectingExistingUserNoNameByIdYieldsNullName)
    {
        Assert::AreEqual(1, ywdb.insert(UserRow{ auto_id, nullable_string{} }));

        auto user = ywdb.selectUserById(1L);
        Expect::AreEqual(1, user.id.getValue());
        Assert::IsNull(user.name);
    }

    YW_TEST(UserTable, SelectingNonexistentUserByIdThrowsException)
    {
        try {
            auto user = ywdb.selectUserById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No user row with that id", e.what());
        }
    }

YW_TEST_END