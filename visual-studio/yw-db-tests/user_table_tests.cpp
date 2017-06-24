#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw_db;
using std::make_unique;

namespace yw_db_tests
{
    TEST_CLASS(UserTableTests)
    {
    public:

        TEST_METHOD(TestInsertUser_OneRow_GeneratedIdIs_1)
        {
            YesWorkflowDB ywdb;
            auto rowId = ywdb.insertUser("user1");
            Assert::AreEqual(1L, (long)rowId);
        }

        TEST_METHOD(TestInsertUser_TwoRows_SecondGeneratedIdIs_2)
        {
            YesWorkflowDB ywdb;
            ywdb.insertUser("user1");
            auto secondRowId = ywdb.insertUser("user2");
            Assert::AreEqual(2L, (long)secondRowId);
        }

        TEST_METHOD(TestSelectUserById_RowExists) {
            YesWorkflowDB ywdb;
            ywdb.insertUser("user1");
            auto user = ywdb.selectUserById(1L);
            Assert::AreEqual(1L, user.id);
            Assert::AreEqual(std::string("user1"), user.name);
        }

        TEST_METHOD(TestSelectUserById_RowDoesntExist) {
            YesWorkflowDB ywdb;
            try {
                auto user = ywdb.selectUserById(1L);
                Assert::Fail();
            }
            catch (std::runtime_error& e) {
                Assert::AreEqual("No row with that id", e.what());
            }
        }
    };
}