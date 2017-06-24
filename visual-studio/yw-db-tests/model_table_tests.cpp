#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw::db;

using std::make_unique;
using std::string;

namespace yw {
    namespace db {

        TEST_CLASS(ModelTableTests)
        {
        public:

            TEST_METHOD(TestInsertModel_OneRow_GeneratedIdIs_1)
            {
                YesWorkflowDB ywdb;
                long userId, modelId;
                Assert::AreEqual(1L, (userId = ywdb.insertUser("user1")));
                Assert::AreEqual(1L, (modelId = ywdb.insertModel(userId, "2017-06-22 10:52:00.000")));
            }

            TEST_METHOD(TestInsertModel_TwoRows_SecondGeneratedIdIs_2)
            {
                YesWorkflowDB ywdb;
                long user1;
                Assert::AreEqual(1L, user1 = ywdb.insertUser("user1"));
                long model1, model2;
                Assert::AreEqual(1L, (model1 = ywdb.insertModel(user1, "2017-06-22 10:52:00.000")));
                Assert::AreEqual(2L, (model2 = ywdb.insertModel(user1, "2017-06-22 10:52:01.000")));
            }

            TEST_METHOD(TestSelectModelById_RowExists) {
                YesWorkflowDB ywdb;
                long user1, user2, user3;
                Assert::AreEqual(1L, (user1 = ywdb.insertUser("user1")));
                Assert::AreEqual(2L, (user2 = ywdb.insertUser("user2")));
                Assert::AreEqual(3L, (user3 = ywdb.insertUser("user3")));
                long model1, model2;
                Assert::AreEqual(1L, model1 = ywdb.insertModel(user2, "2017-06-22 10:52:00.000"));
                Assert::AreEqual(2L, model2 = ywdb.insertModel(user3, "2017-06-22 10:52:01.000"));
                auto model = ywdb.selectModelById(2L);
                Assert::AreEqual(2L, model.id);
                Assert::AreEqual(3L, model.creator);
                Assert::AreEqual(std::string("2017-06-22 10:52:01.000"), model.create_date);
            }

            TEST_METHOD(TestSelectModelById_RowDoesntExist) {
                YesWorkflowDB ywdb;
                try {
                    auto user = ywdb.selectModelById(1L);
                    Assert::Fail();
                }
                catch (std::runtime_error& e) {
                    Assert::AreEqual("No row with that id", e.what());
                }
            }
        };
    }
}