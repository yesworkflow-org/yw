#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::string;

using Tag = yw::db::Annotation::Tag;

YW_TEST_FIXTURE(AnnotationExtractor)

    YesWorkflowDB ywdb;
    AnnotationExtractor extractor{ ywdb };
    StderrRecorder stderrRecorder;

YW_TEST_SET


    YW_TEST(AnnotationExtractor, ExtractingOneSourceStringYieldsOneExtractionOneSourceAndZeroFiles)
    {
        extractor.extractAnnotationsFromString(
            R"(
                # @begin hello world @desc Exercise YW with a classic program.
                # @out greeting @desc Greeting displayed to user.
                print("Hello world!")
                # @end hello world
            )");

        Expect::AreEqual("", stderrRecorder.str());
        Expect::AreEqual(6, ywdb.getRowCount("line"));
        Expect::AreEqual(5, ywdb.getRowCount("annotation"));

        Assert::AreEqual(1, ywdb.getRowCount("extraction"));
        Assert::AreEqual(1, ywdb.getRowCount("source"));
        Assert::AreEqual(0, ywdb.getRowCount("file"));
    }

    YW_TEST(AnnotationExtractor, ExtractingOneSourceFileYieldsOneExtractionOneSourceAndOneFile)
    {
        auto sourceFilePath = writeTempFile(
            "hello.py", 
            R"(
                # @begin hello world @desc Exercise YW with a classic program.
                # @out greeting @desc Greeting displayed to user.
                print("Hello world!")
                # @end hello world
            )");

        extractor.extractAnnotationsFromFile(sourceFilePath);
        
        Expect::AreEqual("", stderrRecorder.str());
        Expect::AreEqual(6, ywdb.getRowCount("line"));
        Expect::AreEqual(5, ywdb.getRowCount("annotation"));
        Expect::AreEqual(File{ 1, "hello.py" }, ywdb.selectFileById(1));

        Assert::AreEqual(1, ywdb.getRowCount("extraction"));
        Assert::AreEqual(1, ywdb.getRowCount("source"));
        Assert::AreEqual(1, ywdb.getRowCount("file"));
    }

    YW_TEST(AnnotationExtractor, ExtractingTwoSourceStringsYieldsTwoExtractionsTwoSourcesAndZeroFiles)
    {
        extractor.extractAnnotationsFromString(
            R"(
                # @begin hello world @desc Exercise YW with a classic program.
                # @out greeting @desc Greeting displayed to user.
                print("Hello world!")
                # @end hello world
            )");

        extractor.extractAnnotationsFromString(
            R"(
                # @begin hey world
                # @out greeting
                print("Hey world!")
                # @end hello world
            )");

        Expect::AreEqual("", stderrRecorder.str());
        Expect::AreEqual(12, ywdb.getRowCount("line"));
        Expect::AreEqual(8, ywdb.getRowCount("annotation"));

        Assert::AreEqual(2, ywdb.getRowCount("extraction"));
        Assert::AreEqual(2, ywdb.getRowCount("source"));
        Assert::AreEqual(0, ywdb.getRowCount("file"));
    }


    YW_TEST(AnnotationExtractor, ExtractingTwoSourceFilesSeparatelyYieldsTwoExtractionsTwoSourcesAndTwoFiles)
    {
        auto helloFilePath = writeTempFile(
            "hello.py",
            R"(
                # @begin hello world @desc Exercise YW with a classic program.
                # @out greeting @desc Greeting displayed to user.
                print("Hello world!")
                # @end hello world
            )");

        auto heyFilePath = writeTempFile(
            "hey.py",
            R"(
                # @begin hey world
                # @out greeting
                print("Hey world!")
                # @end hello world
            )");

        extractor.extractAnnotationsFromFile(helloFilePath);
        extractor.extractAnnotationsFromFile(heyFilePath);

        Expect::AreEqual("", stderrRecorder.str());
        Expect::AreEqual(12, ywdb.getRowCount("line"));
        Expect::AreEqual(8, ywdb.getRowCount("annotation"));
        Expect::AreEqual(File{ 1, "hello.py" }, ywdb.selectFileById(1));

        Assert::AreEqual(2, ywdb.getRowCount("extraction"));
        Assert::AreEqual(2, ywdb.getRowCount("source"));
        Assert::AreEqual(2, ywdb.getRowCount("file"));
    }

    YW_TEST(AnnotationExtractor, ExtractingTwoSourceFilesTogetherYieldsOneExtractionTwoSourcesAndTwoFiles)
    {
        auto helloFilePath = writeTempFile(
            "hello.py",
            R"(
                # @begin hello world @desc Exercise YW with a classic program.
                # @out greeting @desc Greeting displayed to user.
                print("Hello world!")
                # @end hello world
            )");

        auto heyFilePath = writeTempFile(
            "hey.py",
            R"(
                # @begin hey world
                # @out greeting
                print("Hey world!")
                # @end hello world
            )");

        extractor.extractAnnotationsFromFiles(std::vector<string> {helloFilePath, heyFilePath});

        Expect::AreEqual("", stderrRecorder.str());
        Expect::AreEqual(12, ywdb.getRowCount("line"));
        Expect::AreEqual(8, ywdb.getRowCount("annotation"));
        Expect::AreEqual(File{ 1, "hello.py" }, ywdb.selectFileById(1));
        Expect::AreEqual(File{ 2, "hey.py" }, ywdb.selectFileById(2));

        Assert::AreEqual(1, ywdb.getRowCount("extraction"));
        Assert::AreEqual(2, ywdb.getRowCount("source"));
        Assert::AreEqual(2, ywdb.getRowCount("file"));
    }

YW_TEST_END
