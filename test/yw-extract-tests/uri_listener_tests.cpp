#include "yw_extract_tests.h"
#include "random_testing.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;

using Tag = yw::db::Annotation::Tag;

YW_TEST_FIXTURE(UriAnnotationListener)

    YesWorkflowDB ywdb;
    row_id extractionId, sourceId;
    std::shared_ptr<SourceLoader> sourceLoader;
    AnnotationListener* listener;
    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void storeAndParse(const std::string& code) {
        sourceLoader->insertSourceLinesFromString(sourceId, code);
        YWParserBuilder parser_builder(code);
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, parser_builder.parse()->script());
    }

    YW_TEST_SETUP(UriAnnotationListener) {

        row_id userId;

        Expect::AreEqual(1, (userId = ywdb.insert(User{ auto_id, "user1" })));
        Expect::AreEqual(1, (extractionId = ywdb.insert(Extraction{ auto_id, userId, "2017-06-22 10:52:00.000" })));
        Expect::AreEqual(1, (sourceId = ywdb.insert(Source{ auto_id, null_id, "C" })));

        sourceLoader = std::make_shared<SourceLoader>(ywdb);
        listener = new AnnotationListener(ywdb, extractionId, sourceId);
    }

YW_TEST_SET

    YW_TEST(UriAnnotationListener, WhenFileAnnotationHasSimplePathArgumentAnnotationCapturesThatPath)
    {
        this->storeAndParse(trimmargins(R"(

            @begin b
            @out d @file /path
            @end b

        )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::FILE, 2, 2, 2, 7, 17, "@file", "/path" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

    YW_TEST(UriAnnotationListener, WhenFileAnnotationHasSingleSlashArgumentAnnotationCapturesThatPath)
    {
        this->storeAndParse(trimmargins(R"(

                @begin b
                @out d @file /
                @end b

            )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::FILE, 2, 2, 2, 7, 13, "@file", "/" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

    YW_TEST(UriAnnotationListener, WhenUriAnnotationHasSimplePathArgumentAnnotationCapturesThatPath)
    {
        this->storeAndParse(trimmargins(R"(

                @begin b
                @out d @uri /path
                @end b

            )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::URI, 2, 2, 2, 7, 16, "@uri", "/path" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

    YW_TEST(UriAnnotationListener, WhenUriAnnotationHasIsSingleSlashAnnotationCapturesThatPath)
    {
        this->storeAndParse(trimmargins(R"(

                @begin b
                @out d @uri /
                @end b

            )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::URI, 2, 2, 2, 7, 12, "@uri", "/" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

    YW_TEST(UriAnnotationListener, WhenUriAnnotationHasFileSchemeColonSlashAnnotationCapturesThatPath)
    {
        this->storeAndParse(trimmargins(R"(

                @begin b
                @out d @uri file:/
                @end b

            )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::URI, 2, 2, 2, 7, 17, "@uri", "file:/" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

    YW_TEST(UriAnnotationListener, WhenUriAnnotationHasUrlForArgumentAnnotationCapturesThatUrlrt)
    {
        this->storeAndParse(trimmargins(R"(

                @begin b
                @out d @uri http://foo.org/bar.txt 
                @end b

            )"));

        Assert::AreEqual(3, ywdb.getRowCount("line"));
        Assert::AreEqual(4, ywdb.getRowCount("annotation"));
        Assert::AreEqual(Annotation{ 1, extractionId, Tag::BEGIN, null_id, 1, 1, 0, 7, "@begin", "b" }, ywdb.selectAnnotationById(1));
        Assert::AreEqual(Annotation{ 2, extractionId, Tag::OUT, 1, 2, 1, 0, 5, "@out", "d" }, ywdb.selectAnnotationById(2));
        Assert::AreEqual(Annotation{ 3, extractionId, Tag::URI, 2, 2, 2, 7, 33, "@uri", "http://foo.org/bar.txt" }, ywdb.selectAnnotationById(3));
        Assert::AreEqual(Annotation{ 4, extractionId, Tag::END, 1, 3, 1, 0, 5, "@end", "b" }, ywdb.selectAnnotationById(4));
    }

YW_TEST_END
