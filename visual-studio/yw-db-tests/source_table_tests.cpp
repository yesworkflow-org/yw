#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw_db;
using std::make_unique;

namespace yw_db_tests
{
    TEST_CLASS(SourceTableTests)
    {
    public:

        TEST_METHOD(TestInsertSource_OneRow_GeneratedIdIs_1)
        {
            YesWorkflowDB ywdb;
            auto rowId = ywdb.insertSource("path to source");
            Assert::AreEqual(1L, (long)rowId);
        }

        TEST_METHOD(TestInsertSource_TwoRows_SecondGeneratedIdIs_2)
        {
            YesWorkflowDB ywdb;
            ywdb.insertSource("path to first source");
            auto secondRowId = ywdb.insertSource("path to second source");
            Assert::AreEqual(2L, (long)secondRowId);
        }

        TEST_METHOD(TestSelectSourceById_RowExists) {
            YesWorkflowDB ywdb;
            ywdb.insertSource("path to source");
            auto source = ywdb.selectSourceById(1L);
            Assert::AreEqual(std::string("path to source"), source);
        }

        TEST_METHOD(TestSelectSourceById_RowDoesntExist) {
            YesWorkflowDB ywdb;
            try {
                auto source = ywdb.selectSourceById(1L);
                Assert::Fail();
            }
            catch (std::runtime_error& e) {
                Assert::AreEqual("No row with that id", e.what());
            }
        }
    };
}