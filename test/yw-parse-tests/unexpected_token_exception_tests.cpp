#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(UnexpectedTokenException)

YW_TEST_SET

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::UnexpectedTokenException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("An unexpected token '@end' was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::UnexpectedTokenException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("An unexpected token '@end' was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100);
        }
        catch (const UnexpectedTokenException& e) {
            Assert::AreEqual("An unexpected token '@end' was encountered at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw UnexpectedTokenException("@end", 40, 100, "sample.sh");
        }
        catch (const UnexpectedTokenException& e) {
            Assert::AreEqual("An unexpected token '@end' was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(UnexpectedTokenException, CatchingUnexpectedTokenExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = UnexpectedTokenException("@end", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const UnexpectedTokenException& e) {
            Assert::AreEqual("An unexpected token '@end' was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END