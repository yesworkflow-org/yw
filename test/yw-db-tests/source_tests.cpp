#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(Source)

    YesWorkflowDB ywdb { false };
    row_id file22, file70;

    YW_TEST_SETUP(Source)
    {
        ywdb.createFileTable();
        Expect::AreEqual(22, ywdb.insert(File{ (file22 = 22), "main.c" }));
        Expect::AreEqual(70, ywdb.insert(File{ (file70 = 70), "script.sh" }));

        ywdb.createSourceTable();
    }

YW_TEST_SET

    YW_TEST(Source, InsertSource_OneRow_GeneratedIdIs_1)
    {
        Assert::AreEqual(1, ywdb.insert(Source{ auto_id, file22, "C" }));
    }

    YW_TEST(Source, InsertSource_TwoRows_SecondGeneratedIdIs_2)
    {
        Expect::AreEqual(1, ywdb.insert(Source{ auto_id, file22, "C" }));
        Assert::AreEqual(2, ywdb.insert(Source{ auto_id, file70, "Bash" }));
    }

    YW_TEST(Source, SelectSourceById_RowExists)
    {
        Expect::AreEqual(1, ywdb.insert(Source{ auto_id, file22, "C" }));
        Expect::AreEqual(2, ywdb.insert(Source{ auto_id, file70, "Bash" }));

        auto source = ywdb.selectSourceById(2);
        Assert::AreEqual(2, source.id.getValue());
        Assert::AreEqual(70L, source.fileId);
        Assert::AreEqual("Bash", source.language.getValue());
    }

    YW_TEST(Source, SelectSourceById_RowDoesntExist) {
        try {
            auto source = ywdb.selectSourceById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No source row with that id", e.what());
        }
    }

YW_TEST_END