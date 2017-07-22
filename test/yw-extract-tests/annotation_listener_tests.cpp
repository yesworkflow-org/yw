#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

YW_TEST_FIXTURE(AnnotationListener)

	YesWorkflowDB ywdb;
	std::shared_ptr<SourceLoader> sourceLoader;
	AnnotationListener* listener;
	StderrRecorder stderrRecorder;

	void storeAndParse(std::string code) {
		sourceLoader->loadFromString(code);
		YWParserBuilder parser_builder(code);
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
	}

	YW_TEST_SETUP(AnnotationListener) {

		long userId, modelId, languageId, sourceId;

		Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));
		Expect::AreEqual(1, (modelId = ywdb.insert(ModelRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));
		Expect::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ auto_id, "C" })));
		Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, modelId, languageId, null_id })));

		sourceLoader = std::make_shared<SourceLoader>(ywdb, sourceId);
		listener = new AnnotationListener(ywdb, sourceId);
	}

YW_TEST_SET

	YW_TEST(AnnotationListener, BeginAnnotationAtStartOfOnlyLineInsertsOneLineAndOneAnnotation)
	{
		this->storeAndParse(
			"@begin b"
		);

		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, BeginAnnotationInMiddleOfOnlyLineInsertsOneLineAndOneAnnotation)
	{
		this->storeAndParse(
			"     @begin b"
		);

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 5, 12, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, BeginAnnotationOnSecondOfThreeLinesInsertsThreeLinesAndOneAnnotation)
	{
		this->storeAndParse(
			"\n"
			"@begin b" "\n"
			"\n"
		);

		Assert::AreEqual(3, ywdb.getRowCount("line"));
		Assert::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 2, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, BeginAndEndOnOnlyLineInsertsOneLineAndTwoAnnotations)
	{
		this->storeAndParse("@begin b @end b");

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(2, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
		Assert::AreEqual(AnnotationRow{ 2, null_id, 1, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
	}

	YW_TEST(AnnotationListener, BeginAndEndOnFiveLinesInsertsFiveLineAndTwoAnnotations)
	{
		this->storeAndParse(
			"\n"
			"@begin b" "\n"
			"\n"
			"@end b" "\n"
			"\n"
		);

		Assert::AreEqual(5, ywdb.getRowCount("line"));
		Assert::AreEqual(2, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 2, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
		Assert::AreEqual(AnnotationRow{ 2, null_id, 4, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
	}

	YW_TEST(AnnotationListener, WhenEndHasNoArgumentAnnotationHasNullBlockName)
	{
		Assert::AreEqual(0, ywdb.getRowCount("line"));
		Assert::AreEqual(0, ywdb.getRowCount("annotation"));

		this->storeAndParse(
			"@begin b @end"
		);

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(2, ywdb.getRowCount("annotation"));

		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
		Assert::AreEqual(AnnotationRow{ 2, null_id, 1, 9, 12, "@end", null_string }, ywdb.selectAnnotationById(2));
	}

YW_TEST_END
