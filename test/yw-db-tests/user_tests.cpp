#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(User)

    YesWorkflowDB ywdb { false };

    YW_TEST_SETUP(User)
    {
        ywdb.createUserTable();
    }

YW_TEST_SET

    YW_TEST(User, InsertingFirstUserWithNameYieldsGeneratedId1)
    {
        Assert::AreEqual(1, ywdb.insert(User{ auto_id, "user1" }));
    }

    YW_TEST(User, InsertingFirstUserWithNoNameYieldsGeneratedId1)
    {
        Assert::AreEqual(1, ywdb.insert(User{ auto_id, nullable_string{} }));
    }

    YW_TEST(User, InsertingSecondUserWithNameYieldsGeneratedId2)
    {
        Expect::AreEqual(1, ywdb.insert(User{ auto_id, "user1" }));

        Assert::AreEqual(2, ywdb.insert(User{ auto_id, "user2" }));
    }

    YW_TEST(User, SelectingExistingUserWithNameByIdYieldsAssignedName)
    {
        Expect::AreEqual(1, ywdb.insert(User{ auto_id, "user1" }));

        auto user = ywdb.selectUserById(1);
        Expect::AreEqual(1L, user.id);
        Assert::AreEqual("user1", user.name.getValue());
    }

    YW_TEST(User, SelectingExistingUserNoNameByIdYieldsNullName)
    {
        Assert::AreEqual(1, ywdb.insert(User{ auto_id, nullable_string{} }));

        auto user = ywdb.selectUserById(1);
        Expect::AreEqual(1L, user.id);
        Assert::IsNull(user.name);
    }

    YW_TEST(User, SelectingNonexistentUserByIdThrowsException)
    {
        try {
            auto user = ywdb.selectUserById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No user row with that id", e.what());
        }
    }

YW_TEST_END