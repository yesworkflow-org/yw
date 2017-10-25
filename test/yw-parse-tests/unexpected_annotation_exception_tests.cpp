#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(UnexpectedAnnotationException)

YW_TEST_SET

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::UnexpectedTokenException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::UnexpectedTokenException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (const UnexpectedAnnotationException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100, "sample.sh");
        }
        catch (const UnexpectedAnnotationException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CatchingUnexpectedTokenExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = UnexpectedAnnotationException("@end", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const UnexpectedAnnotationException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CallingGetDetailsOnAUnexpectedAnnotationExceptionnWithUnsetDetailsYieldsNullString)
    {
        try {
            throw UnexpectedAnnotationException("@end", 40, 100);
        }
        catch (const UnexpectedAnnotationException& e) {
            Assert::IsFalse(e.getDetails().hasValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedAnnotationException, CallingGetDetailsOnUnexpectedAnnotationExceptionWithSetDetailsYieldsDetails)
    {
        try {
            auto exception = UnexpectedAnnotationException("@end", 40, 100);
            exception.setDetails("Details about the exception.");
            throw exception;
        }
        catch (const UnexpectedAnnotationException& e) {
            Assert::IsTrue(e.getDetails().hasValue());
            Assert::AreEqual("Details about the exception.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END