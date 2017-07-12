#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(LanguageTable)

	YesWorkflowDB ywdb { false };

	YW_TEST_SETUP(LanguageTable)
	{
		ywdb.createLanguageTable();
	}

YW_TEST_SET

    YW_TEST(LanguageTable, InserOneRow_GeneratedIdIs_1)
    {
	auto rowId = ywdb.insert(LanguageRow{ "C" });
        Assert::AreEqual(1, rowId);
    }

    YW_TEST(LanguageTable, InsertTwoRows_SecondGeneratedIdIs_2) 
    {
		ywdb.insert(LanguageRow{ "C" });
        Assert::AreEqual(2, ywdb.insert(LanguageRow{ "Java" }));
    }

    YW_TEST(LanguageTable, SelectLanguageById_RowExists) {
		ywdb.insert(LanguageRow{ "C" });
        auto language = ywdb.selectLanguageById(1L);
        Assert::AreEqual(1, language.id);
        Assert::AreEqual(std::string("C"), language.name);
    }

    YW_TEST(LanguageTable, SelectLanguageById_RowDoesntExist)
    {
        try {
            auto language = ywdb.selectLanguageById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END