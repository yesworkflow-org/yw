#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::make_unique;

YW_TEST_FIXTURE(SourceTable)

    YesWorkflowDB ywdb { false };
	row_id user9, model18, language4, language51, file22, file70;

	YW_TEST_SETUP(SourceTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(9, ywdb.insert(UserRow{ (user9 = 9), "user1" }));

		ywdb.createModelTable();
		Expect::AreEqual(18, ywdb.insert(ModelRow{ (model18 = 18), user9, "2017-06-22 10:52:00.000" }));

		ywdb.createFileTable();
		Expect::AreEqual(22, ywdb.insert(FileRow{ (file22 = 22), "main.c" }));
		Expect::AreEqual(70, ywdb.insert(FileRow{ (file70 = 70), "script.sh" }));

		ywdb.createLanguageTable();
		Expect::AreEqual(4, ywdb.insert(LanguageRow{ (language4 = 4), "C" }));
		Expect::AreEqual(51, ywdb.insert(LanguageRow{ (language51 = 51), "Bash" }));

		ywdb.createSourceTable();
	}

YW_TEST_SET
    
    YW_TEST(SourceTable, InsertSource_OneRow_GeneratedIdIs_1)
    {
		Assert::AreEqual(1, ywdb.insert(SourceRow{ auto_id, model18, language4, file22 }));
    }

    YW_TEST(SourceTable, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
		Expect::AreEqual(1, ywdb.insert(SourceRow{ auto_id, model18, language4, file22 }));
		Assert::AreEqual(2, ywdb.insert(SourceRow{ auto_id, model18, language51, file70 }));
    }

    YW_TEST(SourceTable, SelectSourceById_RowExists) 
	{
		Expect::AreEqual(1, ywdb.insert(SourceRow{ auto_id, model18, language4, file22 }));
		Expect::AreEqual(2, ywdb.insert(SourceRow{ auto_id, model18, language51, file70 }));

        auto source = ywdb.selectSourceById(2L);
        Assert::AreEqual(2, source.id.getValue());
        Assert::AreEqual(18, source.modelId);
		Assert::AreEqual(51, source.languageId);
		Assert::AreEqual(70, source.fileId.getValue());
    }

    YW_TEST(SourceTable, SelectSourceById_RowDoesntExist) {
        try {
            auto source = ywdb.selectSourceById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END