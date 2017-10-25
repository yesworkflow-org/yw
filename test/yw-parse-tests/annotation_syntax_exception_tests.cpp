#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(AnnotationSyntaxException)

YW_TEST_SET

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw AnnotationSyntaxException(40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::AnnotationSyntaxException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw AnnotationSyntaxException(40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::AnnotationSyntaxException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(40, 100);
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw AnnotationSyntaxException(40, 100, "sample.sh");
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }


    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = AnnotationSyntaxException(40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CallingGetDetailsOnAnnotationSyntaxExceptionWithUnsetDetailsYieldsNullString)
    {
        try {
            throw AnnotationSyntaxException(40, 100, "sample.sh");
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::IsFalse(e.getDetails().hasValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(AnnotationSyntaxException, CallingGetDetailsOnAnnotationSyntaxExceptionWithSetDetailsYieldsDetails)
    {
        try {
            auto exception = AnnotationSyntaxException(40, 100, "sample.sh");
            exception.setDetails("Details about the exception.");
            throw exception;
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::IsTrue(e.getDetails().hasValue());
            Assert::AreEqual("Details about the exception.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }


YW_TEST_END