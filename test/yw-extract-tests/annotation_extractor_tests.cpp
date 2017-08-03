#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::string;

using Tag = yw::db::AnnotationRow::Tag;

YW_TEST_FIXTURE(AnnotationExtractor)

    YesWorkflowDB ywdb;
    AnnotationExtractor extractor{ ywdb };
    StderrRecorder stderrRecorder;

YW_TEST_SET

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
        Expect::AreEqual(0, ywdb.getRowCount("user"));
        Expect::AreEqual(6, ywdb.getRowCount("line"));
        Expect::AreEqual(5, ywdb.getRowCount("annotation"));
        Expect::AreEqual(FileRow{ 1, "hello.py" }, ywdb.selectFileById(1));
        Expect::AreEqual(ExtractionRow{ 1, null_id, "" }, ywdb.selectExtractionById(1));

        Assert::AreEqual(1, ywdb.getRowCount("extraction"));
        Assert::AreEqual(1, ywdb.getRowCount("source"));
        Assert::AreEqual(1, ywdb.getRowCount("file"));
    }

YW_TEST_END
