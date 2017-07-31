#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;
using namespace yw::sqlite;

using std::make_unique;

YW_TEST_FIXTURE(SourceTable)

    YesWorkflowDB ywdb { false };
    row_id file22, file70;

    YW_TEST_SETUP(SourceTable)
    {
        ywdb.createFileTable();
        Expect::AreEqual(22, ywdb.insert(FileRow{ (file22 = 22), "main.c" }));
        Expect::AreEqual(70, ywdb.insert(FileRow{ (file70 = 70), "script.sh" }));

        ywdb.createSourceTable();
    }

YW_TEST_SET

    YW_TEST(SourceTable, InsertSource_OneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(SourceRow{ auto_id, file22, "C" }));
    }

    YW_TEST(SourceTable, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(SourceRow{ auto_id, file22, "C" }));
        Assert::AreEqual(2, ywdb.insert(SourceRow{ auto_id, file70, "Bash" }));
    }

    YW_TEST(SourceTable, SelectSourceById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(SourceRow{ auto_id, file22, "C" }));
        Expect::AreEqual(2, ywdb.insert(SourceRow{ auto_id, file70, "Bash" }));

        auto source = ywdb.selectSourceById(2L);
        Assert::AreEqual(2, source.id.getValue());
        Assert::AreEqual(70, source.fileId.getValue());
        Assert::AreEqual("Bash", source.language.getValue());
    }

    YW_TEST(SourceTable, SelectSourceById_RowDoesntExist) {
        try {
            auto source = ywdb.selectSourceById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No source row with that id", e.what());
        }
    }

YW_TEST_END