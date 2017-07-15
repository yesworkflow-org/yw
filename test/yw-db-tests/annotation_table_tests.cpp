#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::sqlite;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(AnnotationTable)

    YesWorkflowDB ywdb { false };
	long userId, modelId, languageId, fileId, sourceId;

	YW_TEST_SETUP(AnnotationTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(1, (userId = ywdb.insert(UserRow{ "user1" })));

		ywdb.createModelTable();
		Expect::AreEqual(1, (modelId = ywdb.insert(ModelRow{ userId, "2017-06-22 10:52:00.000" })));

		ywdb.createFileTable();
		Expect::AreEqual(1, (fileId = ywdb.insert(FileRow{ "main.c" })));

		ywdb.createLanguageTable();
		Expect::AreEqual(1, (languageId = ywdb.insert(LanguageRow{ "C" })));

		ywdb.createSourceTable();
		Expect::AreEqual(1, (sourceId = ywdb.insert(SourceRow{ modelId, languageId, fileId })));

		ywdb.createLineTable();
		Expect::AreEqual(1, ywdb.insert(LineRow(sourceId, 1, "@begin block")));
		Expect::AreEqual(2, ywdb.insert(LineRow(sourceId, 4, "@in port")));
		Assert::AreEqual(3, ywdb.insert(LineRow(sourceId, 5, "@end block")));

		ywdb.createAnnotationTable();
	}

YW_TEST_SET
    
    YW_TEST(AnnotationTable, InsertingFirstAnnotationYieldsGeneratedId1)
    {
		Assert::AreEqual(1, ywdb.insert(AnnotationRow{ null_id, 1, 0, 11, "@begin", "block" }));
    }

    YW_TEST(AnnotationTable, InsertingQualifyingAnnotationYieldsGeneratedId2)
	{
		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ null_id, 1, 0, 11, "@begin", "block" } )));
		Assert::AreEqual(2, ywdb.insert(AnnotationRow{ annotation1 , 2, 0, 7, "@in", "port" }));
	}

	YW_TEST(AnnotationTable, SelectingFirstAnnotationByIdYieldsAssignedFieldValues) {

		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ null_id, 1, 0, 11, "@begin", "block" })));
		Assert::AreEqual(2, ywdb.insert(AnnotationRow{ annotation1 , 2, 0, 7, "@in", "port" }));

		auto annotation = ywdb.selectAnnotationById(1L);
		Assert::AreEqual(1, annotation.id.getValue());
		Assert::IsNull(annotation.qualifiesId);
		Assert::AreEqual(1, annotation.lineId);
		Assert::AreEqual(0, annotation.start);
		Assert::AreEqual(11, annotation.end);
		Assert::AreEqual("@begin", annotation.tag);
		Assert::AreEqual("block", annotation.value);
	}

    YW_TEST(AnnotationTable, SelectingQualifyingAnnotationByIdYieldsAssignedFieldValues) {

		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ null_id, 1, 0, 11, "@begin", "block" })));
		Assert::AreEqual(2, ywdb.insert(AnnotationRow{ annotation1 , 2, 0, 7, "@in", "port" }));

        auto annotation = ywdb.selectAnnotationById(2L);
        Assert::AreEqual(2, annotation.id.getValue());
		Assert::AreEqual(1, annotation.qualifiesId.getValue());
		Assert::AreEqual(2, annotation.lineId);
		Assert::AreEqual(0, annotation.start);
		Assert::AreEqual(7, annotation.end);
		Assert::AreEqual("@in", annotation.tag);
		Assert::AreEqual("port", annotation.value);
	}

    YW_TEST(AnnotationTable, SelectingNonexistent) {
        try {
            auto source = ywdb.selectAnnotationById(1L);
            Assert::Fail();
        }
        catch (std::runtime_error& e) {
            Assert::AreEqual("No row with that id", e.what());
        }
    }

YW_TEST_END