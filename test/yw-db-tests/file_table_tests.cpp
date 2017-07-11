#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(FileTable)

	YesWorkflowDB ywdb { false };

	YW_TEST_SETUP(FileTable)
	{
		ywdb.createUserTable();
		ywdb.createFileTable();
	}

YW_TEST_SET

    YW_TEST(FileTable, InsertFile_OneRow_GeneratedIdIs_1)
    {
        long userId, fileId;
        Assert::AreEqual(1, (userId = ywdb.insertUser("user1")));
        Assert::AreEqual(1, (fileId = ywdb.insertFile("main.c", userId)));
    }

    YW_TEST(FileTable, InsertFile_TwoRows_SecondGeneratedIdIs_2)
    {
        long user1;
        Assert::AreEqual(1, user1 = ywdb.insertUser("user1"));
        long file1, file2;
        Assert::AreEqual(1, (file1 = ywdb.insertFile("main.c", user1)));
        Assert::AreEqual(2, (file2 = ywdb.insertFile("script.sh", user1)));
    }

    YW_TEST(FileTable, SelectFileById_RowExists) {
        long user1, user2, user3;
        Assert::AreEqual(1, (user1 = ywdb.insertUser("user1")));
        Assert::AreEqual(2, (user2 = ywdb.insertUser("user2")));
        Assert::AreEqual(3, (user3 = ywdb.insertUser("user3")));
        long file1, file2;
        Assert::AreEqual(1, file1 = ywdb.insertFile("main.c", user2));
        Assert::AreEqual(2, file2 = ywdb.insertFile("script.sh", user3));

        auto fileRow = ywdb.selectFileById(2L);
        Assert::AreEqual("|2|script.sh|owner|", fileRow.str());
    }

    YW_TEST(FileTable, SelectFileById_RowDoesntExist) {
        try {
            auto user = ywdb.selectFileById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END