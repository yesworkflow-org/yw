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
		Assert::AreEqual(AnnotationRow{ 2, 1, 1, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
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
		Assert::AreEqual(AnnotationRow{ 2, 1, 4, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
	}

	YW_TEST(AnnotationListener, WhenEndHasNoArgumentAnnotationHasNullBlockName)
	{
		this->storeAndParse(
			"@begin b @end"
		);

		auto endAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 12, "@end", null_string }, endAnnotation);

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

	YW_TEST(AnnotationListener, WhenParamWithSingleArgumentFollowsBeginOnNextLineQualifyingIdOfInIsIdOfBegin)
	{
		this->storeAndParse(
			"@begin b"	EOL
			"@param p"	EOL
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto paramAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(2, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 2, 0, 7, "@param", "p" }, paramAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), paramAnnotation.qualifiesId.getValue());
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
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 13, "@in", "p" }, inAnnotation);
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
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 17, "@in", "p" }, inAnnotation1);
		Expect::AreEqual(AnnotationRow{ 3, 1, 1, 9, 17, "@in", "q" }, inAnnotation2);
		Expect::AreEqual(AnnotationRow{ 4, 1, 1, 9, 17, "@in", "r" }, inAnnotation3);
		Expect::AreEqual(AnnotationRow{ 5, 4, 1, 19, 43, "@desc", "description of port" }, descAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());

		Assert::AreEqual(inAnnotation3.id.getValue(), descAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenInWithAliasFollowsInOnSameLineQualifyingIdOfAliasIsIdOfIn)
	{
		this->storeAndParse(
			"@begin b @in p @as name of data port receives"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation = ywdb.selectAnnotationById(2);
		auto aliasAnnotation = ywdb.selectAnnotationById(3);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(3, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 13, "@in", "p" }, inAnnotation);
		Expect::AreEqual(AnnotationRow{ 3, 2, 1, 15, 44, "@as", "name of data port receives" }, aliasAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

		Assert::AreEqual(inAnnotation.id.getValue(), aliasAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenInWithAliasFollowsInOnNextLineQualifyingIdOfAliasIsIdOfIn)
	{
		this->storeAndParse(
			"@begin b @in p"					EOL
			"@as name of data port receives"	EOL
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation = ywdb.selectAnnotationById(2);
		auto aliasAnnotation = ywdb.selectAnnotationById(3);
		Expect::AreEqual(2, ywdb.getRowCount("line"));
		Expect::AreEqual(3, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 13, "@in", "p" }, inAnnotation);
		Expect::AreEqual(AnnotationRow{ 3, 2, 2, 0, 29, "@as", "name of data port receives" }, aliasAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

		Assert::AreEqual(inAnnotation.id.getValue(), aliasAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenParamFollowsInAliasFollowingParamHasQualifyingIdOfParam)
	{
		this->storeAndParse(
			"@begin b"							EOL
			"@in p q"							EOL
			"@param r"							EOL
			"@as name of data param receives"	EOL
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto inAnnotation1 = ywdb.selectAnnotationById(2);
		auto inAnnotation2 = ywdb.selectAnnotationById(3);
		auto paramAnnotation = ywdb.selectAnnotationById(4);
		auto aliasAnnotation = ywdb.selectAnnotationById(5);
		Expect::AreEqual(4, ywdb.getRowCount("line"));
		Expect::AreEqual(5, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 2, 0, 6, "@in", "p" }, inAnnotation1);
		Expect::AreEqual(AnnotationRow{ 3, 1, 2, 0, 6, "@in", "q" }, inAnnotation2);
		Expect::AreEqual(AnnotationRow{ 4, 1, 3, 0, 7, "@param", "r" }, paramAnnotation);
		Expect::AreEqual(AnnotationRow{ 5, 4, 4, 0, 30, "@as", "name of data param receives" }, aliasAnnotation);
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation2.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation.id.getValue(), paramAnnotation.qualifiesId.getValue());

		Assert::AreEqual(paramAnnotation.id.getValue(), aliasAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenOutWithSingleArgumentFollowsBeginOnSameLineQualifyingIdOfOutIsIdOfBegin)
	{
		this->storeAndParse(
			"@begin b @out p"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto outAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 14, "@out", "p" }, outAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), outAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenReturnWithSingleArgumentFollowsBeginOnSameLineQualifyingIdOfReturnIsIdOfBegin)
	{
		this->storeAndParse(
			"@begin b @return p"
		);

		auto beginAnnotation = ywdb.selectAnnotationById(1);
		auto returnAnnotation = ywdb.selectAnnotationById(2);
		Expect::AreEqual(1, ywdb.getRowCount("line"));
		Expect::AreEqual(2, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 17, "@return", "p" }, returnAnnotation);

		Assert::AreEqual(beginAnnotation.id.getValue(), returnAnnotation.qualifiesId.getValue());
	}

	YW_TEST(AnnotationListener, WhenParamFollowsInAliasFollowingParamHasQualifyingIdOfParam__FOO)
	{
		this->storeAndParse(
			"@begin b @desc description of block b"	EOL
			"@in p q"								EOL
			"@out r s"								EOL
			"@end b"								EOL
													EOL
			"@begin c"								EOL
			"@param t"								EOL
			"@return u"								EOL
			"@as name of data param receives"		EOL
			"@end c"								EOL
		);

		auto beginAnnotation1 = ywdb.selectAnnotationById(1);
		auto descAnnotation = ywdb.selectAnnotationById(2);
		auto inAnnotation1 = ywdb.selectAnnotationById(3);
		auto inAnnotation2 = ywdb.selectAnnotationById(4);
		auto outAnnotation1 = ywdb.selectAnnotationById(5);
		auto outAnnotation2 = ywdb.selectAnnotationById(6);
		auto endAnnotation1 = ywdb.selectAnnotationById(7);
		auto beginAnnotation2 = ywdb.selectAnnotationById(8);
		auto paramAnnotation = ywdb.selectAnnotationById(9);
		auto returnAnnotation = ywdb.selectAnnotationById(10);
		auto aliasAnnotation = ywdb.selectAnnotationById(11);
		auto endAnnotation2 = ywdb.selectAnnotationById(12);
		Expect::AreEqual(10, ywdb.getRowCount("line"));
		Expect::AreEqual(12, ywdb.getRowCount("annotation"));
		Expect::AreEqual(AnnotationRow{ 1, null_id, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
		Expect::AreEqual(AnnotationRow{ 2, 1, 1, 9, 36, "@desc", "description of block b" }, descAnnotation);
		Expect::AreEqual(AnnotationRow{ 3, 1, 2, 0, 6, "@in", "p" }, inAnnotation1);
		Expect::AreEqual(AnnotationRow{ 4, 1, 2, 0, 6, "@in", "q" }, inAnnotation2);
		Expect::AreEqual(AnnotationRow{ 5, 1, 3, 0, 7, "@out", "r" }, outAnnotation1);
		Expect::AreEqual(AnnotationRow{ 6, 1, 3, 0, 7, "@out", "s" }, outAnnotation2);
		Expect::AreEqual(AnnotationRow{ 7, 1, 4, 0, 5, "@end", "b" }, endAnnotation1);
		Expect::AreEqual(AnnotationRow{ 8, null_id, 6, 0, 7, "@begin", "c" }, beginAnnotation2);
		Expect::AreEqual(AnnotationRow{ 9, 8, 7, 0, 7, "@param", "t" }, paramAnnotation);
		Expect::AreEqual(AnnotationRow{ 10, 8, 8, 0, 8, "@return", "u" }, returnAnnotation);
		Expect::AreEqual(AnnotationRow{ 11, 10, 9, 0, 30, "@as", "name of data param receives" }, aliasAnnotation);
		Expect::AreEqual(AnnotationRow{ 12, 8, 10, 0, 5, "@end", "c" }, endAnnotation2);

		Expect::AreEqual(beginAnnotation1.id.getValue(), descAnnotation.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation1.id.getValue(), inAnnotation1.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation1.id.getValue(), inAnnotation2.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation1.id.getValue(), outAnnotation1.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation1.id.getValue(), outAnnotation2.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation2.id.getValue(), paramAnnotation.qualifiesId.getValue());
		Expect::AreEqual(beginAnnotation2.id.getValue(), returnAnnotation.qualifiesId.getValue());

		Assert::AreEqual(returnAnnotation.id.getValue(), aliasAnnotation.qualifiesId.getValue());
	}


YW_TEST_END
