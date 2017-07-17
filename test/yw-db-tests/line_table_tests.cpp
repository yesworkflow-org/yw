#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(LineTable)

	YesWorkflowDB ywdb { false };
	long userId, modelId, languageId, fileId, sourceId;
	
	YW_TEST_SETUP(LineTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));

		ywdb.createModelTable();
		Expect::AreEqual(1, (modelId = ywdb.insert(ModelRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));

		ywdb.createFileTable();
		Expect::AreEqual(1, (fileId = ywdb.insert(FileRow{ auto_id, "main.c" })));

		ywdb.createLanguageTable();
		Expect::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ auto_id, "C" })));

		ywdb.createSourceTable();
		Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, modelId, languageId, fileId })));

		ywdb.createLineTable();
	}

YW_TEST_SET

    YW_TEST(LineTable, InsertingFirstLineYieldsGeneratedId1)
    {
		Assert::AreEqual(1, ywdb.insert(LineRow(auto_id, sourceId, 1, "@begin block")));
    }

	YW_TEST(LineTable, InsertingSecondLineYieldsGeneratedId2)
	{
		Expect::AreEqual(1, ywdb.insert(LineRow(auto_id, sourceId, 1, "@begin block")));
		Assert::AreEqual(2, ywdb.insert(LineRow(auto_id, sourceId, 2, "@end block")));
	}

	YW_TEST(LineTable, SelectingExistingLineByIdYieldsCorrectAssignedValues) 
	{
		Expect::AreEqual(1, ywdb.insert(LineRow(auto_id, sourceId, 1, "@begin block")));
		Expect::AreEqual(2, ywdb.insert(LineRow(auto_id, sourceId, 4, "@in port")));
		Assert::AreEqual(3, ywdb.insert(LineRow(auto_id, sourceId, 5, "@end block")));

		auto lineRow = ywdb.selectLineById(2L);
		Assert::AreEqual(2L, lineRow.id);
		Assert::AreEqual(1L, lineRow.sourceId);
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