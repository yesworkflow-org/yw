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
            long userId, modelId, languageId, fileId, sourceId;
            Assert::AreEqual(1L, (userId = ywdb.insertUser("user1")));
            Assert::AreEqual(1L, (modelId = ywdb.insertModel(userId, "2017-06-22 10:52:00.000")));
            Assert::AreEqual(1L, (fileId = ywdb.insertFile("main.c", userId)));
            Assert::AreEqual(1L, (languageId = ywdb.insertLanguage("C")));
            Assert::AreEqual(1L, (sourceId = ywdb.insertSource(modelId, languageId, fileId)));
        }

        TEST_METHOD(TestInsertSource_TwoRows_SecondGeneratedIdIs_2)
        {
            YesWorkflowDB ywdb;
            long userId, modelId, language1, language2, file1, file2, source1, source2;
            Assert::AreEqual(1L, (userId = ywdb.insertUser("user1")));
            Assert::AreEqual(1L, (modelId = ywdb.insertModel(userId, "2017-06-22 10:52:00.000")));
            Assert::AreEqual(1L, (file1 = ywdb.insertFile("main.c", userId)));
            Assert::AreEqual(2L, (file2 = ywdb.insertFile("script.sh", userId)));
            Assert::AreEqual(1L, (language1 = ywdb.insertLanguage("C")));
            Assert::AreEqual(2L, (language2 = ywdb.insertLanguage("Bash")));
            Assert::AreEqual(1L, (source1 = ywdb.insertSource(modelId, language1, file1)));
            Assert::AreEqual(2L, (source2 = ywdb.insertSource(modelId, language2, file2)));
        }

        TEST_METHOD(TestSelectSourceById_RowExists) {
            YesWorkflowDB ywdb;
            long userId, modelId, languageId, fileId, sourceId;
            Assert::AreEqual(1L, (userId = ywdb.insertUser("user1")));
            Assert::AreEqual(1L, (modelId = ywdb.insertModel(userId, "2017-06-22 10:52:00.000")));
            Assert::AreEqual(1L, (fileId = ywdb.insertFile("main.c", userId)));
            Assert::AreEqual(1L, (languageId = ywdb.insertLanguage("C")));
            Assert::AreEqual(1L, (sourceId = ywdb.insertSource(modelId, languageId, fileId)));

            auto source = ywdb.selectSourceById(1L);
            Assert::AreEqual(1L, source.id);
            Assert::AreEqual(1L, source.model);
            Assert::AreEqual(1L, source.file);
            Assert::AreEqual(1L, source.language);
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