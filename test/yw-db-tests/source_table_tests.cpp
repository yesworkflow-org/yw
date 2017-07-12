#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(SourceTable)

    YesWorkflowDB ywdb { false };

	YW_TEST_SETUP(SourceTable)
	{
		ywdb.createUserTable();
		ywdb.createModelTable();
		ywdb.createFileTable();
		ywdb.createLanguageTable();
		ywdb.createSourceTable();
	}

YW_TEST_SET
    
    YW_TEST(SourceTable, InsertSource_OneRow_GeneratedIdIs_1)
    {
        long userId, modelId, languageId, fileId, sourceId;
		Assert::AreEqual(1, (userId = ywdb.insert(UserRow{ "user1" })));
		Assert::AreEqual(1, (modelId = ywdb.insert(ModelRow{ userId, "2017-06-22 10:52:00.000" })));
		Assert::AreEqual(1, (fileId = ywdb.insert(FileRow{"main.c",userId})));
		Assert::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ "C" })));
		Assert::AreEqual(1, ywdb.insert(SourceRow{ modelId, languageId, fileId }));
    }

    YW_TEST(SourceTable, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        long userId, modelId, language1, language2, file1, file2;
		Assert::AreEqual(1, (userId = ywdb.insert(UserRow{ "user1" })));
		Assert::AreEqual(1, (modelId = ywdb.insert(ModelRow{ userId, "2017-06-22 10:52:00.000" })));
		Assert::AreEqual(1, (file1 = ywdb.insert(FileRow{"main.c", userId})));
		Assert::AreEqual(2, (file2 = ywdb.insert(FileRow{"script.sh", userId})));
		Assert::AreEqual(1, (language1 = ywdb.insert(LanguageRow{ "C" })));
		Assert::AreEqual(2, (language2 = ywdb.insert(LanguageRow{ "Bash" })));
		Assert::AreEqual(1, ywdb.insert(SourceRow{ modelId, language1, file1 }));
		Assert::AreEqual(2, ywdb.insert(SourceRow{ modelId, language2, file2 }));
    }

    YW_TEST(SourceTable, SelectSourceById_RowExists) {
        long userId, modelId, languageId, fileId, sourceId;
		Assert::AreEqual(1, (userId = ywdb.insert(UserRow{ "user1" })));
		Assert::AreEqual(1, (modelId = ywdb.insert(ModelRow{ userId, "2017-06-22 10:52:00.000" })));
		Assert::AreEqual(1, (fileId = ywdb.insert(FileRow{"main.c",userId})));
		Assert::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ "C" })));
		Assert::AreEqual(1, ywdb.insert(SourceRow{ modelId, languageId, fileId }));

        auto source = ywdb.selectSourceById(1L);
        Assert::AreEqual(1, source.id);
        Assert::AreEqual(1, source.model);
        Assert::AreEqual(1, source.file);
        Assert::AreEqual(1, source.language);
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