#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(FileTable)

	YesWorkflowDB ywdb { false };

	YW_TEST_SETUP(FileTable)
	{
		ywdb.createFileTable();
	}

YW_TEST_SET

    YW_TEST(FileTable, InsertFile_OneRow_GeneratedIdIs_1)
    {
		Assert::AreEqual(1, ywdb.insert(FileRow{ "main.c" }));
    }

    YW_TEST(FileTable, InsertFile_TwoRows_SecondGeneratedIdIs_2)
    {
		Expect::AreEqual(1, ywdb.insert(FileRow{ "main.c" }));
		Assert::AreEqual(2, ywdb.insert(FileRow{ "script.sh" }));
    }

    YW_TEST(FileTable, SelectFileById_RowExists) {
		Expect::AreEqual(1, ywdb.insert(FileRow{ "main.c" }));
		Expect::AreEqual(2, ywdb.insert(FileRow{ "script.sh" }));

        auto file = ywdb.selectFileById(2L);
		Assert::AreEqual(2L, file.id);
		Assert::AreEqual("script.sh", file.name);

        Assert::AreEqual("|2|script.sh|", file.str());
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