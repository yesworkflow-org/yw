#include "yw_db_tests.h"

using namespace yw;
using namespace yw::test;
using namespace yw::db;

using std::make_unique;
using std::string;

YW_TEST_FIXTURE(Line)

    YesWorkflowDB ywdb { false };
    row_id file99, source34;

    YW_TEST_SETUP(Line)
    {
        ywdb.createFileTable();
        Expect::AreEqual(99, (ywdb.insert(File{ (file99 = 99), "main.c" })));

        ywdb.createSourceTable();
        Expect::AreEqual(34, ywdb.insert(Source{ (source34 = 34), file99, "C" }));

        ywdb.createLineTable();
    }

YW_TEST_SET

    YW_TEST(Line, FieldValuesMatchAssignedValuesWithNulls) {
        Assert::AreEqual(
            "NULL|34|1|NULL",
            Line{ auto_id, 34, 1, null_string }.fieldValues()
        );
    }

    YW_TEST(Line, FieldValuesMatchAssignedValuesWithoutNulls) {
        Assert::AreEqual(
            "8|34|1|@begin block",
            Line{ 8, 34, 1, "@begin block" }.fieldValues()
        );
    }

    YW_TEST(Line, InsertingFirstLineYieldsGeneratedId1)
    {
        Assert::AreEqual(1, ywdb.insert(Line(auto_id, source34, 1, "@begin block")));
    }

    YW_TEST(Line, InsertingSecondLineYieldsGeneratedId2)
    {
        Expect::AreEqual(1, ywdb.insert(Line(auto_id, source34, 1, "@begin block")));
        Assert::AreEqual(2, ywdb.insert(Line(auto_id, source34, 2, "@end block")));
    }

    YW_TEST(Line, SelectingExistingLineByIdYieldsCorrectAssignedValues)
    {
        Expect::AreEqual(1, ywdb.insert(Line(auto_id, source34, 1, "@begin block")));
        Expect::AreEqual(2, ywdb.insert(Line(auto_id, source34, 4, "@in port")));
        Assert::AreEqual(3, ywdb.insert(Line(auto_id, source34, 5, "@end block")));

        auto lineRow = ywdb.selectLineById(2);
        Assert::AreEqual(2L, lineRow.id);
        Assert::AreEqual(34, lineRow.sourceId);
        Assert::AreEqual(4L, lineRow.number);
        Assert::AreEqual("@in port", lineRow.text.getValue());
    }

    YW_TEST(Line, SelectingNonexistentLineByIdThrowsException) {
        try {
            auto user = ywdb.selectLineById(1);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No line row with that id", e.what());
        }
    }

YW_TEST_END