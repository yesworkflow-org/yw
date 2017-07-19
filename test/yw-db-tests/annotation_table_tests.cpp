#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::sqlite;
using namespace yw::db;

using std::make_unique;

YW_TEST_FIXTURE(AnnotationTable)

    YesWorkflowDB ywdb { false };
	long user13, model17, language2, file5, source8, line19, line25, line77;

	YW_TEST_SETUP(AnnotationTable)
	{
		ywdb.createUserTable();
		Expect::AreEqual(13, ywdb.insert(UserRow{ (user13 = 13), "user1" }));

		ywdb.createModelTable();
		Expect::AreEqual(17, ywdb.insert(ModelRow{ (model17 = 17), user13, "2017-06-22 10:52:00.000" }));

		ywdb.createFileTable();
		Expect::AreEqual(5, ywdb.insert(FileRow{ (file5 = 5), "main.c" }));

		ywdb.createLanguageTable();
		Expect::AreEqual(2, ywdb.insert(LanguageRow{ (language2 = 2), "C" }));

		ywdb.createSourceTable();
		Expect::AreEqual(8, ywdb.insert(SourceRow{ (source8 = 8), model17, language2, file5 }));

		ywdb.createLineTable();
		Expect::AreEqual(19, ywdb.insert(LineRow{ (line19 = 19), source8, 1, "@begin block" }));
		Expect::AreEqual(25, ywdb.insert(LineRow{ (line25 = 25), source8, 4, "@in port" }));
		Assert::AreEqual(77, ywdb.insert(LineRow{ (line77 = 77), source8, 5, "@end block" }));

		ywdb.createAnnotationTable();
	}

YW_TEST_SET
    
    YW_TEST(AnnotationTable, InsertingFirstAnnotationYieldsGeneratedId1)
    {
		Assert::AreEqual(1, ywdb.insert(AnnotationRow{ auto_id, null_id, line19, 0, 11, "@begin", "block" }));
    }

    YW_TEST(AnnotationTable, InsertingQualifyingAnnotationYieldsGeneratedId2)
	{
		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ auto_id, null_id, line19, 0, 11, "@begin", "block" } )));
		Assert::AreEqual(2, ywdb.insert(AnnotationRow{ auto_id, annotation1, line25, 0, 7, "@in", "port" }));
	}

	YW_TEST(AnnotationTable, SelectingFirstAnnotationByIdYieldsAssignedFieldValues) {

		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ auto_id, null_id, line19, 0, 11, "@begin", "block" })));

		auto annotation = ywdb.selectAnnotationById(1L);
		Assert::AreEqual(1, annotation.id.getValue());
		Assert::IsNull(annotation.qualifiesId);
		Assert::AreEqual(19, annotation.lineId);
		Assert::AreEqual(0, annotation.start);
		Assert::AreEqual(11, annotation.end);
		Assert::AreEqual("@begin", annotation.tag);
		Assert::AreEqual("block", annotation.value.getValue());
	}

    YW_TEST(AnnotationTable, SelectingQualifyingAnnotationByIdYieldsAssignedFieldValues) {

		long annotation1;
		Assert::AreEqual(1, (annotation1 = ywdb.insert(AnnotationRow{ auto_id, null_id, line19, 0, 11, "@begin", "block" })));
		Assert::AreEqual(2, ywdb.insert(AnnotationRow{ auto_id, annotation1, line25, 0, 7, "@in", "port" }));

        auto annotation = ywdb.selectAnnotationById(2L);
        Assert::AreEqual(2, annotation.id.getValue());
		Assert::AreEqual(1, annotation.qualifiesId.getValue());
		Assert::AreEqual(25, annotation.lineId);
		Assert::AreEqual(0, annotation.start);
		Assert::AreEqual(7, annotation.end);
		Assert::AreEqual("@in", annotation.tag);
		Assert::AreEqual("port", annotation.value.getValue());
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