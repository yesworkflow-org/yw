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

	YW_TEST(AnnotationListener, WhenBeginAnnotationAtStartOfOnlyLineInsertsOneLineAndOneAnnotation)
	{
		this->storeAndParse(
			"@begin b"
		);

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, WhenBeginAnnotationInMiddleOfOnlyLineInsertsOneLineAndOneAnnotation)
	{
		this->storeAndParse(
			"     @begin b"
		);

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 5, 12, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, WhenBeginAnnotationOnSecondOfThreeLinesInsertsThreeLinesAndOneAnnotation)
	{
		this->storeAndParse(
			EOL
			"@begin b" EOL
			EOL
		);

		Assert::AreEqual(3, ywdb.getRowCount("line"));
		Assert::AreEqual(1, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 2, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
	}

	YW_TEST(AnnotationListener, WhenBeginAndEndOnOnlyLineInsertsOneLineAndTwoAnnotations)
	{
		this->storeAndParse("@begin b @end b");

		Assert::AreEqual(1, ywdb.getRowCount("line"));
		Assert::AreEqual(2, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
		Assert::AreEqual(AnnotationRow{ 2, null_id, 1, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
	}

	YW_TEST(AnnotationListener, WhenBeginAndEndSecondAndFourthOfFiveLinesInsertsFiveLineAndTwoAnnotations)
	{
		this->storeAndParse(
			EOL
			"@begin b" EOL
			EOL
			"@end b" EOL
			EOL
		);

		Assert::AreEqual(5, ywdb.getRowCount("line"));
		Assert::AreEqual(2, ywdb.getRowCount("annotation"));
		Assert::AreEqual(AnnotationRow{ 1, null_id, 2, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
		Assert::AreEqual(AnnotationRow{ 2, null_id, 4, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
	}

	YW_TEST(AnnotationListener, WhenEndHasNoArgumentAnnotationHasNullBlockName)
	{
		this->storeAndParse(
			"@begin b @end"
		);

		auto endAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(AnnotationRow{ 2, null_id, 1, 9, 12, "@end", null_string }, endAnnotation);

		Assert::IsNull(endAnnotation.value);
	}

	YW_TEST(AnnotationListener, WhenDescFollowsBeginOnSameLineQualifiesIdOfDescIsBeginId)
	{	
		this->storeAndParse(
			"@begin b @desc the description of the block"
		);
		
		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto descAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 42, "@desc", "the description of the block" }, descAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenDescFollowsBeginOnNextLineQualifiesIdOfDescIsBeginI)
	{
		this->storeAndParse(
			"@begin b"								EOL
			"@desc the description of the block"	EOL
		);
		
		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto descAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(2, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 2, 0, 33, "@desc", "the description of the block" }, descAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenInWithSingleArgumentFollowsBeginOnSameLineQualifyingIdOfInIsIdOfBegin)
	{
		this->storeAndParse(
			"@begin b @in p"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation = ywdb.selectAnnotationById(2);		
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 13, "@in", "p" }, inAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenInWithThreeArgurmentsFollowsBeginOnSameLineQualifyingIdOfEachIsIdOfBegin)
	{
		this->storeAndParse(
			"@begin b @in p q r"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation1 = ywdb.selectAnnotationById(2);
		auto inAnnotation2 = ywdb.selectAnnotationById(3);
		auto inAnnotation3 = ywdb.selectAnnotationById(4);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(4, ywdb.getRowCount("annotation"));

		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 17, "@in", "p" }, inAnnotation1);
		Expect::AreEqual(AnnotationRow{ 3, 1, 1, 9, 17, "@in", "q" }, inAnnotation2);
		Expect::AreEqual(AnnotationRow{ 4, 1, 1, 9, 17, "@in", "r" }, inAnnotation3);

		Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());
		Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation2.qualifiesId.getValue());
		Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation3.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenDescFollowsInWithSingleArgumentLineQualifyingIdOfDescIsIdOfIn)
	{
		this->storeAndParse(
			"@begin b @in p @desc description of port"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation = ywdb.selectAnnotationById(2);
		auto descAnnotation = ywdb.selectAnnotationById(3);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(3, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 39, "@in", "p" }, inAnnotation);
		Expect::AreEqual(AnnotationRow{ 3, 2, 1, 15, 39, "@desc", "description of port" }, descAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

		Assert::AreEqual(inAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenDescFollowsInWithMultiplesArgumentLineQualifyingIdOfDescIsIdOfFinalPort)
	{
		this->storeAndParse(
			"@begin b @in p q r @desc description of port"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation1 = ywdb.selectAnnotationById(2);
		auto inAnnotation2 = ywdb.selectAnnotationById(3);
		auto inAnnotation3 = ywdb.selectAnnotationById(4);
		auto descAnnotation = ywdb.selectAnnotationById(5);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(5, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 43, "@in", "p" }, inAnnotation1);
		Expect::AreEqual(AnnotationRow{ 3, 1, 1, 9, 43, "@in", "q" }, inAnnotation2);
		Expect::AreEqual(AnnotationRow{ 4, 1, 1, 9, 43, "@in", "r" }, inAnnotation3);
		Expect::AreEqual(AnnotationRow{ 5, 4, 1, 19, 43, "@desc", "description of port" }, descAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());

		Assert::AreEqual(inAnnotation3.id.getValue(), descAnnotation.qualifiesId.getValue());
	}

YW_TEST_END
