#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

YW_TEST_FIXTURE(OutlineExporter)

    YesWorkflowDB ywdb;
    std::shared_ptr<SourceLoader> sourceLoader;
    AnnotationListener* listener;
    StderrRecorder stderrRecorder;

    void storeAndParse(const std::string& code) {
        sourceLoader->loadFromString(code);
        YWParserBuilder parser_builder(code);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
    }

    YW_TEST_SETUP(OutlineExporter) {

        long userId, extractionId, sourceId;

        Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ auto_id, "user1" })));
        Expect::AreEqual(1, (extractionId = ywdb.insert(ExtractionRow{ auto_id, userId, "2017-06-22 10:52:00.000" })));
        Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, null_id, null_string })));

        sourceLoader = std::make_shared<SourceLoader>(ywdb, sourceId);
        listener = new AnnotationListener(ywdb, extractionId, sourceId);
    }

YW_TEST_SET

    YW_TEST(OutlineExporter, WhenBeginAndEndAtStartOfSubsequentLinesOutlineIsSameAsSource)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ywdb};

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, WhenBeginAndEndOnSameLineOutlineSpansTwoLines)
    {
        this->storeAndParse(
            "@begin b @end b"
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DescriptionOfBeginFollowsOnSameLineByDefault)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@desc the only block"  EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b @desc the only block"  EOL
            "@end b"                         EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DescriptionNotIndentedOnLineFollowingBeginIfQualiferIndentSizeIsZero)
    {
        this->storeAndParse(
            "@begin b @desc description of block @end b"
        );
        OutlineExporter exporter{ ywdb, 0, 0 };

        Assert::AreEqual(
            "@begin b"                      EOL
            "@desc description of block"    EOL
            "@end b"                        EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DescriptionIndentedOnLineFollowingBeginIfQualiferIndentSizeIsTwo)
    {
        this->storeAndParse(
            "@begin b @desc description of block @end b"
        );
        OutlineExporter exporter{ ywdb, 0, 2 };

        Assert::AreEqual(
            "@begin b"                      EOL
            "  @desc description of block"  EOL
            "@end b"                        EOL
            , exporter.getOutline(1));
    }

    YW_TEST(OutlineExporter, DescriptionOfPortFollowsOnSameLineByDefault)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"                      EOL
            "@in p @desc the only port"     EOL
            "@end b"                        EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DescriptionOfPortFollowsUnindentedOnNextLineIfIndentSizeIsZero)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 0 };

        Assert::AreEqual(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@end b"                EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DescriptionOfPortFollowsIndentedOnNextLineIfIndentSizeIsTwo)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 2 };

        Assert::AreEqual(
            "@begin b"                  EOL
            "@in p"                     EOL
            "  @desc the only port"     EOL
            "@end b"                    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasFollowsPortOnSameLineByDefault)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"                  EOL
            "@in p @as name of data"    EOL
            "@end b"                    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasIsUnindentedOnNextLineIfIndentSizeIsZero)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 0 };

        Assert::AreEqual(
            "@begin b"          EOL
            "@in p"             EOL
            "@as name of data"  EOL
            "@end b"            EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasIsIndentedOnNextLineIfIndentSizeIsTwo)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 2 };

        Assert::AreEqual(
            "@begin b"              EOL
            "@in p"                 EOL
            "  @as name of data"    EOL
            "@end b"                EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasAndDescriptionFollowPortOnSameLineByDefault)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"                                      EOL
            "@in p @desc the only port @as name of data"    EOL
            "@end b"                                        EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasAndDescriptionAreUnindentedOnFolloingLinesIfIndentSizeIsZero)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 0 };

        Assert::AreEqual(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@as name of data"      EOL
            "@end b"                EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, AliasAndDescriptionAreIndentedOnFolloingLinesIfIndentSizeIsTwo)
    {
        this->storeAndParse(
            "@begin b"              EOL
            "@in p"                 EOL
            "@desc the only port"   EOL
            "@as name of data"      EOL
            "@end b"                EOL
        );
        OutlineExporter exporter{ ywdb, 0, 2 };

        Assert::AreEqual(
            "@begin b"              EOL
            "@in p"                 EOL
            "  @desc the only port" EOL
            "  @as name of data"    EOL
            "@end b"                EOL
            , exporter.getOutline());
    }


    YW_TEST(OutlineExporter, WhenBeginEndAndFourPortAnnotationsOnSameLineOutlineSpansSixLines)
    {
        this->storeAndParse(
            "@begin b @in p @param q @out r @return s @end b"
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@in p"     EOL
            "@param q"  EOL
            "@out r"    EOL
            "@return s" EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, WhenPortAnnotationHasThreeArgumentsOutlineHasThreePortAnnotations)
    {
        this->storeAndParse(
            "@begin b @in p q r @out s t u @end b"
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@in p"     EOL
            "@in q"     EOL
            "@in r"     EOL
            "@out s"    EOL
            "@out t"    EOL
            "@out u"    EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, NestedBlockIsNotIndentedByDefault)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            ""          EOL
            "@begin c"  EOL
            "@end c"    EOL
            ""          EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, NestedBlockIsIndentedOnceWhenIndentSizeNonzero)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb, 4 };

        Assert::AreEqual(
            "@begin b"      EOL
            ""              EOL
            "    @begin c"  EOL
            "    @end c"    EOL
            ""              EOL
            "@end b"        EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DoublyNestedBlockIsNotIndentedByDefault)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@begin d"  EOL
            "@end d"    EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            ""          EOL
            "@begin c"  EOL
            ""          EOL
            "@begin d"  EOL
            "@end d"    EOL
            ""          EOL
            "@end c"    EOL
            ""          EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, PortsOnDoublyNestedBlockAreNotIndentedByDefault)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@in p q"   EOL
            "@begin c"  EOL
            "@in s"     EOL
            "@begin d"  EOL
            "@in t u"   EOL
            "@end d"    EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@in p"     EOL
            "@in q"     EOL
            ""          EOL
            "@begin c"  EOL
            "@in s"     EOL
            ""          EOL
            "@begin d"  EOL
            "@in t"     EOL
            "@in u"     EOL
            "@end d"    EOL
            ""          EOL
            "@end c"    EOL
            ""          EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, DoublyNestedBlockIsIndentedTwiceWhenIndentSizeNonzero)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@begin d"  EOL
            "@end d"    EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb, 4 };

        Assert::AreEqual(
            "@begin b"            EOL
            ""                    EOL
            "    @begin c"        EOL
            ""                    EOL
            "        @begin d"    EOL
            "        @end d"      EOL
            ""                    EOL
            "    @end c"          EOL
            ""                    EOL
            "@end b"              EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, WhenEndAnnotationLacksArgumentItsArgumentInOutlineMatchesThatOfBegin)
    {
        this->storeAndParse(
            "@begin b @end"
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, WhenNestedEndAnnotationsLackArgumentsTheirArgumentInOutlineMatchThosOfPairedBegins)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@begin d"  EOL
            "@end"      EOL
            "@end"      EOL
            "@end"      EOL
        );
        OutlineExporter exporter{ ywdb, 4 };

        Assert::AreEqual(
            "@begin b"            EOL
            ""                    EOL
            "    @begin c"        EOL
            ""                    EOL
            "        @begin d"    EOL
            "        @end d"      EOL
            ""                    EOL
            "    @end c"          EOL
            ""                    EOL
            "@end b"              EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, PortsOnDoublyNestedBlockAreIndentedTwiceWhenIndentSizeNonzero)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@in p q"   EOL
            "@begin c"  EOL
            "@in s"     EOL
            "@begin d"  EOL
            "@in t u"   EOL
            "@end d"    EOL
            "@end c"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb, 4 };

        Assert::AreEqual(
            "@begin b"          EOL
            "@in p"             EOL
            "@in q"             EOL
            ""                  EOL
            "    @begin c"      EOL
            "    @in s"         EOL
            ""                  EOL
            "        @begin d"  EOL
            "        @in t"     EOL
            "        @in u"     EOL
            "        @end d"    EOL
            ""                  EOL
            "    @end c"        EOL
            ""                  EOL
            "@end b"            EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, SecondNestedBlockIsIndentedOnceWhenIndentSizeNonzero)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@begin c"  EOL
            "@end c"    EOL
            "@begin d"  EOL
            "@end d"    EOL
            "@end b"    EOL
        );
        OutlineExporter exporter{ ywdb, 4 };

        Assert::AreEqual(
            "@begin b"      EOL
            ""              EOL
            "    @begin c"  EOL
            "    @end c"    EOL
            ""              EOL
            "    @begin d"  EOL
            "    @end d"    EOL
            ""              EOL
            "@end b"        EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, SecondTopLevelBlockIsNotIndented)
    {
        this->storeAndParse(
            "@begin b"  EOL
            "@end b"    EOL
            "@begin c"  EOL
            "@end c"    EOL
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"    EOL
            ""          EOL
            "@begin c"  EOL
            "@end c"    EOL
            , exporter.getOutline());
    }

    YW_TEST(OutlineExporter, SecondTopLevelBlockOnSameLineIsNotIndented)
    {
        this->storeAndParse(
            "@begin b @end b @begin c @end c"
        );
        OutlineExporter exporter{ ywdb };

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"    EOL
            ""          EOL
            "@begin c"  EOL
            "@end c"    EOL
            , exporter.getOutline());
    }

YW_TEST_END
