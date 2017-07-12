#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(LineTable)

	YesWorkflowDB ywdb { false };

	YW_TEST_SETUP(LineTable)
	{
		ywdb.createFileTable();
		ywdb.createLineTable();
	}

YW_TEST_SET

    YW_TEST(LineTable, InsertingFirstLineYieldsGeneratedId1)
    {
        long fileId;
		Expect::AreEqual(1, (fileId = ywdb.insert(FileRow{ "main.c" })));

		Assert::AreEqual(1, ywdb.insert(LineRow(fileId, 1, "@begin block")));
    }

    YW_TEST(LineTable, InsertingSecondLineYieldsGeneratedId2)
    {
		long fileId;
		Expect::AreEqual(1, (fileId = ywdb.insert(FileRow{ "main.c" })));
		Expect::AreEqual(1, ywdb.insert(LineRow(fileId, 1, "@begin block")));
		
		Assert::AreEqual(2, ywdb.insert(LineRow(fileId, 2, "@end block")));
	}

    YW_TEST(LineTable, SelectingExistingLineByIdYieldsCorrectAssignedValues) {
		long fileId;
		Expect::AreEqual(1, (fileId = ywdb.insert(FileRow{ "main.c" })));
		Expect::AreEqual(1, ywdb.insert(LineRow(fileId, 1, "@begin block")));
		Expect::AreEqual(2, ywdb.insert(LineRow(fileId, 2, "@end block")));

        auto lineRow = ywdb.selectLineById(2L);
		Assert::AreEqual(2L, lineRow.id);
		Assert::AreEqual(1L, lineRow.fileId);
		Assert::AreEqual(2L, lineRow.number);
		Assert::AreEqual("@end block", lineRow.text);
        Assert::AreEqual("|2|1|2|@end block|", lineRow.str());
    }

    YW_TEST(LineTable, SelectingNonexistentLineByIdThrowsException) {
        try {
            auto user = ywdb.selectLineById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END