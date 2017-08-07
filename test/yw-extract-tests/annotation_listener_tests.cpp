#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using Tag = yw::db::AnnotationRow::Tag;

YW_TEST_FIXTURE(AnnotationListener)

    YesWorkflowDB ywdb;
    row_id extractionId, sourceId;
    std::shared_ptr<SourceLoader> sourceLoader;
    AnnotationListener* listener;
    StderrRecorder stderrRecorder;

    void storeAndParse(const std::string& code) {
        sourceLoader->insertSourceLinesFromString(sourceId, code);
        YWParserBuilder parser_builder(code);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
    }

    YW_TEST_SETUP(AnnotationListener) {

        long userId;

        Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));
        Expect::AreEqual(1, (extractionId = ywdb.insert(ExtractionRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));
        Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, null_id, "C" })));

        sourceLoader = std::make_shared<SourceLoader>(ywdb);
        listener = new AnnotationListener(ywdb, extractionId, sourceId);
    }

YW_TEST_SET

    YW_TEST(AnnotationListener, WhenBeginAnnotationAtStartOfOnlyLineInsertOneLineAndOneAnnotation)
    {
        this->storeAndParse(
            "@begin b"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(1, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
    }

    YW_TEST(AnnotationListener, WhenBeginAnnotationInMiddleOfOnlyLineInsertOneLineAndOneAnnotation)
    {
        this->storeAndParse(
            "     @begin b"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(1, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 5, 12, "@begin", "b" }, ywdb.selectAnnotationById(1));
    }

    YW_TEST(AnnotationListener, WhenCodePrecedesBeginAnnotationOnOnlyLineInsertOneLineAndOneAnnotation)
    {
        this->storeAndParse(
            "some code @begin b"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(1, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 10, 17, "@begin", "b" }, ywdb.selectAnnotationById(1));
    }

    YW_TEST(AnnotationListener, WhenBeginAnnotationOnSecondOfThreeLinesInsertThreeLinesAndOneAnnotation)
    {
        this->storeAndParse(
            EOL
            "@begin b" EOL
            EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(1, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 2, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
    }

    YW_TEST(AnnotationListener, NestedBeginAnnotationQualifiesParentBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@begin c"	EOL
            "@begin d"	EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation1 = ywdb.selectAnnotationById(1);
        auto beginAnnotation2 = ywdb.selectAnnotationById(2);
        auto beginAnnotation3 = ywdb.selectAnnotationById(3);
        Expect::AreEqual(3, ywdb.getRowCount("line"));
        Expect::AreEqual(3, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::BEGIN, 1, 2, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::BEGIN, 2, 3, 1, 0, 7, "@begin", "d" }, beginAnnotation3);

        Assert::AreEqual(beginAnnotation1.id.getValue(), beginAnnotation2.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation2.id.getValue(), beginAnnotation3.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenBeginAndEndOnOnlyLineInsertOneLineAndTwoAnnotations)
    {
        this->storeAndParse("@begin b @end b");
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenCodePrecedsBeginAndEndOnNextLineInsertTwoLinesAndTwoAnnotations)
    {
        this->storeAndParse(
            "some code"			EOL
            "@begin b @end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 2, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 2, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenBlockNameIsInSingleQuotesTheyAreNotIncludedInName)
    {
        this->storeAndParse(
            "@begin 'b'"    EOL
            "@end b"	    EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 9, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenTextFollowsBlockNameInSingleQuotesTextisNotIncludedInName)
    {
        this->storeAndParse(
            "@begin 'b' some text"    EOL
            "@end b"	    EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 9, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenTextFollowsBlockNameInDoubleQuotesTextisNotIncludedInName)
    {
        this->storeAndParse(R"(@begin "b" some text @end b)");
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 9, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 21, 26, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenNonNameTextFollowsBeginOnSameLineTheTextIsIgnored)
    {
        this->storeAndParse(
            "@begin b *"    EOL
            "@end b"	    EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenAnnotationsInCDelimitedCommentsDelimiterNotIncludedInArgument)
    {
        this->storeAndParse(
            "/* @begin b */"    EOL
            "/* @end b */"	    EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 3, 10, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 3, 8, "@end", "b" }, ywdb.selectAnnotationById(2));
    }


    YW_TEST(AnnotationListener, WhenAnotationsInDelimitedCommentsOnSameLineDelimitersNotIncludedInArgument)
    {
        this->storeAndParse(
            "/* @begin b */ some code /* @end b */"
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 3, 10, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 28, 33, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenTextBetweenBeginAndEndWithSingleQuotedArgumentsOnSameLineTextIsIgnored)
    {
        this->storeAndParse(
            "/* @begin 'only block' some text  @end 'only block' */"
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 3, 21, "@begin", "only block" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 34, 50, "@end", "only block" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenTextBetweenBeginAndEndWithDoubleQuotedArgumentsOnSameLineTextIsIgnored)
    {
        this->storeAndParse(R"(/* @begin "only block" some text  @end "only block" */)");
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 3, 21, "@begin", "only block" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 34, 50, "@end", "only block" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenCodeFollowsBeginAndEndOnNextLineInsertTwoLinesAndTwoAnnotations)
    {
        this->storeAndParse(
            "@begin b @end b"	EOL
            "some code"			EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 9, 14, "@end", "b" }, ywdb.selectAnnotationById(2));
    }


    YW_TEST(AnnotationListener, WhenCodeOnLineBetweenBeginAndEndInsertThreeLinesAndTwoAnnotations)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "some code"	EOL
            "@end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, SingleLevelEndAnnotationQualifiesSingleTopLevelBeginAnnotation)
    {
        this->storeAndParse("@begin b @end b");
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto endAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 9, 14, "@end", "b" }, endAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), endAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenBeginAndEndOnSecondAndFourthOfFiveLinesInsertFiveLineAndTwoAnnotations)
    {
        this->storeAndParse(
            EOL
            "@begin b" EOL
            EOL
            "@end b" EOL
            EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(5, ywdb.getRowCount("line"));
        Assert::AreEqual(2, ywdb.getRowCount("annotation"));
        Assert::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 2, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 4, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(2));
    }

    YW_TEST(AnnotationListener, WhenEndHasNoArgumentAnnotationHasNullBlockName)
    {
        this->storeAndParse(
            "@begin b @end"
        );
        Expect::EmptyString(stderrRecorder.str());

        auto endAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 1, 2, 9, 12, "@end", null_string }, endAnnotation);

        Assert::IsNull(endAnnotation.value);
    }


    YW_TEST(AnnotationListener, TopLevelEndAnnotationQualifiesMatchingTopLevelBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@end b"	EOL
            EOL
            "@begin c"	EOL
            "@end c"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation1 = ywdb.selectAnnotationById(1);
        auto endAnnotation1 = ywdb.selectAnnotationById(2);
        auto beginAnnotation2 = ywdb.selectAnnotationById(3);
        auto endAnnotation2 = ywdb.selectAnnotationById(4);
        Expect::AreEqual(5, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 0, 5, "@end", "b" }, endAnnotation1);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::BEGIN, null_id, 4, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 3, 5, 1, 0, 5, "@end", "c" }, endAnnotation2);

        Assert::AreEqual(beginAnnotation1.id.getValue(), endAnnotation1.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation2.id.getValue(), endAnnotation2.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenCodeBetweenBlocksTopLevelEndAnnotationQualifiesMatchingTopLevelBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@end b"	EOL
            "some code"	EOL
            "@begin c"	EOL
            "@end c"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation1 = ywdb.selectAnnotationById(1);
        auto endAnnotation1 = ywdb.selectAnnotationById(2);
        auto beginAnnotation2 = ywdb.selectAnnotationById(3);
        auto endAnnotation2 = ywdb.selectAnnotationById(4);
        Expect::AreEqual(5, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::END, 1, 2, 1, 0, 5, "@end", "b" }, endAnnotation1);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::BEGIN, null_id, 4, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 3, 5, 1, 0, 5, "@end", "c" }, endAnnotation2);

        Assert::AreEqual(beginAnnotation1.id.getValue(), endAnnotation1.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation2.id.getValue(), endAnnotation2.qualifiesId.getValue());
    }


    YW_TEST(AnnotationListener, NestedEndAnnotationQualifiesMatchingBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            EOL
            "@begin c"	EOL
            "@end c"	EOL
            EOL
            "@end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation1 = ywdb.selectAnnotationById(1);
        auto beginAnnotation2 = ywdb.selectAnnotationById(2);
        auto endAnnotation2 = ywdb.selectAnnotationById(3);
        auto endAnnotation1 = ywdb.selectAnnotationById(4);
        Expect::AreEqual(6, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::BEGIN, 1, 3, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::END, 2, 4, 1, 0, 5, "@end", "c" }, endAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 6, 1, 0, 5, "@end", "b" }, endAnnotation1);

        Assert::AreEqual(beginAnnotation1.id.getValue(), endAnnotation1.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation2.id.getValue(), endAnnotation2.qualifiesId.getValue());
    }


    YW_TEST(AnnotationListener, WhenCodeBetweenNestedBlocksNestedEndAnnotationQualifiesMatchingBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"		EOL
            "some code"		EOL
            "@begin c"		EOL
            "@end c"		EOL
            "more code"		EOL
            "@end b"		EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation1 = ywdb.selectAnnotationById(1);
        auto beginAnnotation2 = ywdb.selectAnnotationById(2);
        auto endAnnotation2 = ywdb.selectAnnotationById(3);
        auto endAnnotation1 = ywdb.selectAnnotationById(4);
        Expect::AreEqual(6, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::BEGIN, 1, 3, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::END, 2, 4, 1, 0, 5, "@end", "c" }, endAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 6, 1, 0, 5, "@end", "b" }, endAnnotation1);

        Assert::AreEqual(beginAnnotation1.id.getValue(), endAnnotation1.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation2.id.getValue(), endAnnotation2.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenDescFollowsBeginOnSameLineDescQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b @desc the description of the block"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto descAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::DESC, 1, 1, 2, 9, 42, "@desc", "the description of the block" }, descAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenDescFollowsBeginOnNextLineDescQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"								EOL
            "@desc the description of the block"	EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto descAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(2, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::DESC, 1, 2, 1, 0, 33, "@desc", "the description of the block" }, descAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenInWithSingleArgumentFollowsBeginOnSameLineInQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b @in p"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenInWithSingleArgumentFollowsBeginOnNextLineInQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@in p"		EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(2, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 2, 1, 0, 4, "@in", "p" }, inAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenCodeLineBetweenBeginAndInInQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "some code"	EOL
            "@in p"		EOL
            "@end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto endAnnotation = ywdb.selectAnnotationById(3);
        Expect::AreEqual(4, ywdb.getRowCount("line"));
        Expect::AreEqual(3, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 3, 1, 0, 4, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::END, 1, 4, 1, 0, 5, "@end", "b" }, endAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenCodeLineBetweenInAndOutBothPortsQualifyBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@in p"		EOL
            "some code"	EOL
            "@out q"	EOL
            "@end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto outAnnotation = ywdb.selectAnnotationById(3);
        auto endAnnotation = ywdb.selectAnnotationById(4);
        Expect::AreEqual(5, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 2, 1, 0, 4, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::OUT, 1, 4, 1, 0, 5, "@out", "q" }, outAnnotation);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 5, 1, 0, 5, "@end", "b" }, endAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation.id.getValue(), outAnnotation.qualifiesId.getValue());
    }


    YW_TEST(AnnotationListener, WhenParamWithSingleArgumentFollowsBeginOnSameLineParamQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b @param p"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto paramAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::PARAM, 1, 1, 2, 9, 16, "@param", "p" }, paramAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), paramAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenParamWithSingleArgumentFollowsBeginOnNextLineParamQualifiesBeginAnnotation)
    {
        this->storeAndParse(
            "@begin b"	EOL
            "@param p"	EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto paramAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(2, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::PARAM, 1, 2, 1, 0, 7, "@param", "p" }, paramAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), paramAnnotation.qualifiesId.getValue());
    }


    YW_TEST(AnnotationListener, WhenInWithThreeArgurmentsFollowsBeginOnSameLineQualifyingIdOfEachIsIdOfBegin)
    {
        this->storeAndParse(
            "@begin b @in p q r"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation1 = ywdb.selectAnnotationById(2);
        auto inAnnotation2 = ywdb.selectAnnotationById(3);
        auto inAnnotation3 = ywdb.selectAnnotationById(4);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));

        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 17, "@in", "p" }, inAnnotation1);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::IN, 1, 1, 3, 9, 17, "@in", "q" }, inAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::IN, 1, 1, 4, 9, 17, "@in", "r" }, inAnnotation3);

        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation2.qualifiesId.getValue());
        Assert::AreEqual(beginAnnotation.id.getValue(), inAnnotation3.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenDescFollowsInWithSingleArgumentLineQualifyingIdOfDescIsIdOfIn)
    {
        this->storeAndParse(
            "@begin b @in p @desc description of port @end b"
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto descAnnotation = ywdb.selectAnnotationById(3);
        auto endAnnotation = ywdb.selectAnnotationById(4);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::DESC, 2, 1, 3, 15, 39, "@desc", "description of port" }, descAnnotation);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 1, 4, 41, 46, "@end", "b" }, endAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

        Assert::AreEqual(inAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
    }


    YW_TEST(AnnotationListener, WhenDescTextIsSinglyQuotedTextFollowingDescriptionIsIgnored)
    {
        this->storeAndParse(
            "@begin b @in p @desc 'description of port' some extra text @end b"
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto descAnnotation = ywdb.selectAnnotationById(3);
        auto endAnnotation = ywdb.selectAnnotationById(4);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 1, 4, 59, 64, "@end", "b" }, endAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
        Expect::AreEqual(inAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());

        Assert::AreEqual(AnnotationRow{ 3, extractionId, Tag::DESC, 2, 1, 3, 15, 41, "@desc", "description of port" }, descAnnotation);
    }

    YW_TEST(AnnotationListener, WhenDescTextIsDoublyQuotedTextFollowingDescriptionIsIgnored)
    {
        this->storeAndParse(R"(@begin b @in p @desc "description of port" some extra text @end b)");
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto descAnnotation = ywdb.selectAnnotationById(3);
        auto endAnnotation = ywdb.selectAnnotationById(4);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 1, 4, 59, 64, "@end", "b" }, endAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());
        Expect::AreEqual(inAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());

        Assert::AreEqual(AnnotationRow{ 3, extractionId, Tag::DESC, 2, 1, 3, 15, 41, "@desc", "description of port" }, descAnnotation);
    }

    YW_TEST(AnnotationListener, WhenCodeBetweenPortNameAndDescAnnotationsDescQualifestInAnnotation)
    {
        this->storeAndParse(
            "@begin b @in p"					EOL
            "some code"							EOL
            "@desc description of port @end b"	EOL
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto descAnnotation = ywdb.selectAnnotationById(3);
        auto endAnnotation = ywdb.selectAnnotationById(4);
        Expect::AreEqual(3, ywdb.getRowCount("line"));
        Expect::AreEqual(4, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::DESC, 2, 3, 1, 0, 24, "@desc", "description of port" }, descAnnotation);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::END, 1, 3, 2, 26, 31, "@end", "b" }, endAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

        Assert::AreEqual(inAnnotation.id.getValue(), descAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenDescFollowsInWithMultiplesArgumentLineQualifyingIdOfDescIsIdOfFinalPort)
    {
        this->storeAndParse(
            "@begin b @in p q r @desc description of port @end b"
        );
        Expect::EmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation1 = ywdb.selectAnnotationById(2);
        auto inAnnotation2 = ywdb.selectAnnotationById(3);
        auto inAnnotation3 = ywdb.selectAnnotationById(4);
        auto descAnnotation = ywdb.selectAnnotationById(5);
        auto endAnnotation = ywdb.selectAnnotationById(6);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(6, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 17, "@in", "p" }, inAnnotation1);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::IN, 1, 1, 3, 9, 17, "@in", "q" }, inAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::IN, 1, 1, 4, 9, 17, "@in", "r" }, inAnnotation3);
        Expect::AreEqual(AnnotationRow{ 5, extractionId, Tag::DESC, 4, 1, 5, 19, 43, "@desc", "description of port" }, descAnnotation);
        Expect::AreEqual(AnnotationRow{ 6, extractionId, Tag::END, 1, 1, 6, 45, 50, "@end", "b" }, endAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation1.qualifiesId.getValue());

        Assert::AreEqual(inAnnotation3.id.getValue(), descAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenInWithAliasFollowsInOnSameLineQualifyingIdOfAliasIsIdOfIn)
    {
        this->storeAndParse(
            "@begin b @in p @as name of data port receives"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto aliasAnnotation = ywdb.selectAnnotationById(3);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(3, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::AS, 2, 1, 3, 15, 44, "@as", "name of data port receives" }, aliasAnnotation);
        Expect::AreEqual(beginAnnotation.id.getValue(), inAnnotation.qualifiesId.getValue());

        Assert::AreEqual(inAnnotation.id.getValue(), aliasAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenInWithAliasFollowsInOnNextLineQualifyingIdOfAliasIsIdOfIn)
    {
        this->storeAndParse(
            "@begin b @in p"					EOL
            "@as name of data port receives"	EOL
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation = ywdb.selectAnnotationById(2);
        auto aliasAnnotation = ywdb.selectAnnotationById(3);
        Expect::AreEqual(2, ywdb.getRowCount("line"));
        Expect::AreEqual(3, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 1, 2, 9, 13, "@in", "p" }, inAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::AS, 2, 2, 1, 0, 29, "@as", "name of data port receives" }, aliasAnnotation);
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
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto inAnnotation1 = ywdb.selectAnnotationById(2);
        auto inAnnotation2 = ywdb.selectAnnotationById(3);
        auto paramAnnotation = ywdb.selectAnnotationById(4);
        auto aliasAnnotation = ywdb.selectAnnotationById(5);
        Expect::AreEqual(4, ywdb.getRowCount("line"));
        Expect::AreEqual(5, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::IN, 1, 2, 1, 0, 6, "@in", "p" }, inAnnotation1);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::IN, 1, 2, 2, 0, 6, "@in", "q" }, inAnnotation2);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::PARAM, 1, 3, 1, 0, 7, "@param", "r" }, paramAnnotation);
        Expect::AreEqual(AnnotationRow{ 5, extractionId, Tag::AS, 4, 4, 1, 0, 30, "@as", "name of data param receives" }, aliasAnnotation);
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
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto outAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::OUT, 1, 1, 2, 9, 14, "@out", "p" }, outAnnotation);

        Assert::AreEqual(beginAnnotation.id.getValue(), outAnnotation.qualifiesId.getValue());
    }

    YW_TEST(AnnotationListener, WhenReturnWithSingleArgumentFollowsBeginOnSameLineQualifyingIdOfReturnIsIdOfBegin)
    {
        this->storeAndParse(
            "@begin b @return p"
        );
        Expect::NonEmptyString(stderrRecorder.str());

        auto beginAnnotation = ywdb.selectAnnotationById(1);
        auto returnAnnotation = ywdb.selectAnnotationById(2);
        Expect::AreEqual(1, ywdb.getRowCount("line"));
        Expect::AreEqual(2, ywdb.getRowCount("annotation"));
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::RETURN, 1, 1, 2, 9, 17, "@return", "p" }, returnAnnotation);

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
        Expect::EmptyString(stderrRecorder.str());

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
        Expect::AreEqual(AnnotationRow{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, beginAnnotation1);
        Expect::AreEqual(AnnotationRow{ 2, extractionId, Tag::DESC, 1, 1, 2, 9, 36, "@desc", "description of block b" }, descAnnotation);
        Expect::AreEqual(AnnotationRow{ 3, extractionId, Tag::IN, 1, 2, 1, 0, 6, "@in", "p" }, inAnnotation1);
        Expect::AreEqual(AnnotationRow{ 4, extractionId, Tag::IN, 1, 2, 2, 0, 6, "@in", "q" }, inAnnotation2);
        Expect::AreEqual(AnnotationRow{ 5, extractionId, Tag::OUT, 1, 3, 1, 0, 7, "@out", "r" }, outAnnotation1);
        Expect::AreEqual(AnnotationRow{ 6, extractionId, Tag::OUT, 1, 3, 2, 0, 7, "@out", "s" }, outAnnotation2);
        Expect::AreEqual(AnnotationRow{ 7, extractionId, Tag::END, 1, 4, 1, 0, 5, "@end", "b" }, endAnnotation1);
        Expect::AreEqual(AnnotationRow{ 8, extractionId, Tag::BEGIN, null_id, 6, 1, 0, 7, "@begin", "c" }, beginAnnotation2);
        Expect::AreEqual(AnnotationRow{ 9, extractionId, Tag::PARAM, 8, 7, 1, 0, 7, "@param", "t" }, paramAnnotation);
        Expect::AreEqual(AnnotationRow{ 10, extractionId, Tag::RETURN, 8, 8, 1, 0, 8, "@return", "u" }, returnAnnotation);
        Expect::AreEqual(AnnotationRow{ 11, extractionId, Tag::AS, 10, 9, 1, 0, 30, "@as", "name of data param receives" }, aliasAnnotation);
        Expect::AreEqual(AnnotationRow{ 12, extractionId, Tag::END, 8, 10, 1, 0, 5, "@end", "c" }, endAnnotation2);

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
