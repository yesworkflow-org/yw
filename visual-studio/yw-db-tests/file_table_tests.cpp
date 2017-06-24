#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw::db;

using std::make_unique;
using std::string;

namespace yw {
    namespace db {

        TEST_CLASS(FileTableTests)
            {
            public:

                TEST_METHOD(TestInsertFile_OneRow_GeneratedIdIs_1)
                {
                    YesWorkflowDB ywdb;
                    long userId, fileId;
                    Assert::AreEqual(1L, (userId = ywdb.insertUser("user1")));
                    Assert::AreEqual(1L, (fileId = ywdb.insertFile("main.c", userId)));
                }

                TEST_METHOD(TestInsertFile_TwoRows_SecondGeneratedIdIs_2)
                {
                    YesWorkflowDB ywdb;
                    long user1;
                    Assert::AreEqual(1L, user1 = ywdb.insertUser("user1"));
                    long file1, file2;
                    Assert::AreEqual(1L, (file1 = ywdb.insertFile("main.c", user1)));
                    Assert::AreEqual(2L, (file2 = ywdb.insertFile("script.sh", user1)));
                }

                TEST_METHOD(TestSelectFileById_RowExists) {
                    YesWorkflowDB ywdb;
                    long user1, user2, user3;
                    Assert::AreEqual(1L, (user1 = ywdb.insertUser("user1")));
                    Assert::AreEqual(2L, (user2 = ywdb.insertUser("user2")));
                    Assert::AreEqual(3L, (user3 = ywdb.insertUser("user3")));
                    long file1, file2;
                    Assert::AreEqual(1L, file1 = ywdb.insertFile("main.c", user2));
                    Assert::AreEqual(2L, file2 = ywdb.insertFile("script.sh", user3));
                    auto file = ywdb.selectFileById(2L);
                    Assert::AreEqual(std::string("script.sh"), file.name);
                    Assert::AreEqual(3L, file.owner);
                }

                TEST_METHOD(TestSelectFileById_RowDoesntExist) {
                    YesWorkflowDB ywdb;
                    try {
                        auto user = ywdb.selectFileById(1L);
                        Assert::Fail();
                    }
                    catch (std::runtime_error& e) {
                        Assert::AreEqual("No row with that id", e.what());
                    }
                }
            };
        }
    }