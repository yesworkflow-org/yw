#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

YW_TEST_FIXTURE(AnnotationListener)

	YesWorkflowDB ywdb;
	AnnotationListener* listener;
	StderrRecorder stderrRecorder;

	YW_TEST_SETUP(AnnotationListener) {

		long userId, modelId, languageId, sourceId;

		Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));
		Expect::AreEqual(1, (modelId = ywdb.insert(ModelRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));
		Expect::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ auto_id, "C" })));
		Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, modelId, languageId, null_id })));

		listener = new AnnotationListener(ywdb, sourceId);
	}

YW_TEST_SET

	YW_TEST(AnnotationListener, EnterBeginHandlerInsertsBeginAnnotation)
	{
		YWParserBuilder parser_builder("@begin b");
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->begin());
		Expect::EmptyString(stderrRecorder.str());
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, WhenEndAnnotationHasArgumentEnterEndHandlerInsertsEndAnnotationWithBlockName)
	{
		YWParserBuilder parser_builder("@end b");
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->end());
		Expect::EmptyString(stderrRecorder.str());
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, WhenEndAnnotationHasNoArgumentEnterEndHandlerInsertsEndAnnotationWithoutBlockName)
	{
		YWParserBuilder parser_builder("@end");
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->end());
		Expect::EmptyString(stderrRecorder.str());
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 3, "@end", null_string }, ywdb.selectAnnotationById(1));
	}

YW_TEST_END
