#include "yw_extract_tests.h"

using namespace yw::extract;
using namespace yw::parse;
using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

YW_TEST_FIXTURE(SourceLoader)

    YesWorkflowDB ywdb;
    std::shared_ptr<SourceLoader> sourceLoader;
    long sourceId; 
    StderrRecorder stderrRecorder;

    YW_TEST_SETUP(SourceLoader) 
    {
        Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ auto_id, null_id, "C" })));
        sourceLoader = std::make_shared<SourceLoader>(ywdb);
    }

YW_TEST_SET

    YW_TEST(SourceLoader, LoadingOneLineFromStringInsertsOneRowIntoLineTable)
    {
        sourceLoader->insertSourceLinesFromString(sourceId, "@begin b");
        Assert::AreEqual(1, ywdb.getRowCount("line"));
        Assert::AreEqual(LineRow{ 1, 1, 1, "@begin b" }, ywdb.selectLineById(1));
    }

    YW_TEST(SourceLoader, LoadingTwoLinesFromStringInsertsOneTwoRowsIntoLineTable)
    {
        sourceLoader->insertSourceLinesFromString(
            sourceId,
            "@begin b"	EOL
            "@end b"	EOL);
        Assert::AreEqual(2, ywdb.getRowCount("line"));
        Assert::AreEqual(LineRow{ 1, 1, 1, "@begin b" }, ywdb.selectLineById(1));
        Assert::AreEqual(LineRow{ 2, 1, 2, "@end b" }, ywdb.selectLineById(2));
    }

YW_TEST_END
