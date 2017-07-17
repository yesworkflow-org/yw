#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(LineTable)

	YesWorkflowDB ywdb { false };
	long user8, model17, language18, file99, source34;
	
	YW_TEST_SETUP(LineTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(8, ywdb.insert(UserRow{ (user8 = 8), "user1" }));

		ywdb.createModelTable();
		Expect::AreEqual(17, ywdb.insert(ModelRow{ (model17 = 17), user8, "2017-06-22 10:52:00.000" }));

		ywdb.createFileTable();
		Expect::AreEqual(99, (ywdb.insert(FileRow{ (file99 = 99), "main.c" })));

		ywdb.createLanguageTable();
		Expect::AreEqual(18, ywdb.insert(LanguageRow{ (language18 = 18), "C" }));

		ywdb.createSourceTable();
		Expect::AreEqual(34, ywdb.insert(SourceRow{ (source34 = 34), model17, language18, file99 }));

		ywdb.createLineTable();
	}

YW_TEST_SET

    YW_TEST(LineTable, InsertingFirstLineYieldsGeneratedId1)
    {
		Assert::AreEqual(1, ywdb.insert(LineRow(auto_id, source34, 1, "@begin block")));
    }

	YW_TEST(LineTable, InsertingSecondLineYieldsGeneratedId2)
	{
		Expect::AreEqual(1, ywdb.insert(LineRow(auto_id, source34, 1, "@begin block")));
		Assert::AreEqual(2, ywdb.insert(LineRow(auto_id, source34, 2, "@end block")));
	}

	YW_TEST(LineTable, SelectingExistingLineByIdYieldsCorrectAssignedValues) 
	{
		Expect::AreEqual(1, ywdb.insert(LineRow(auto_id, source34, 1, "@begin block")));
		Expect::AreEqual(2, ywdb.insert(LineRow(auto_id, source34, 4, "@in port")));
		Assert::AreEqual(3, ywdb.insert(LineRow(auto_id, source34, 5, "@end block")));

		auto lineRow = ywdb.selectLineById(2L);
		Assert::AreEqual(2L, lineRow.id);
		Assert::AreEqual(34, lineRow.sourceId);
		Assert::AreEqual(4L, lineRow.number);
		Assert::AreEqual("@in port", lineRow.text);
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