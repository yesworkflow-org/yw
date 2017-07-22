#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

YW_TEST_FIXTURE(SourceLoader)

	YesWorkflowDB ywdb;
	std::shared_ptr<SourceLoader> sourceLoader;
	StderrRecorder stderrRecorder;

	YW_TEST_SETUP(SourceLoader) {

		long userId, modelId, languageId, sourceId;

		Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));
		Expect::AreEqual(1, (modelId = ywdb.insert(ModelRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));
		Expect::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ auto_id, "YW" })));
		Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, modelId, languageId, null_id })));

		sourceLoader = std::make_shared<SourceLoader>(ywdb, sourceId);
	}

YW_TEST_SET

	YW_TEST(SourceLoader, LoadingOneLineFromStringInsertsOneRowIntoLineTable)
	{
		sourceLoader->loadFromString("@begin b");
		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(LineRow{ 1, 1, 1, "@begin b" }, ywdb.selectLineById(1));
	}

	YW_TEST(SourceLoader, LoadingTwoLinesFromStringInsertsOneTwoRowsIntoLineTable)
	{
		sourceLoader->loadFromString(
			"@begin b"	EOL
			"@end b"	EOL);
		Assert::AreEqual(2, ywdb.getRowCount("line"));
		Assert::AreEqual(LineRow{ 1, 1, 1, "@begin b" }, ywdb.selectLineById(1));
		Assert::AreEqual(LineRow{ 2, 1, 2, "@end b" }, ywdb.selectLineById(2));
	}


YW_TEST_END
