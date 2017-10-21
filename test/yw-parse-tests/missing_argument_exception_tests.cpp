#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingArgumentException)

YW_TEST_SET

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::MissingArgumentException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingExceptionDetails)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("The annotation '@begin' at column 40 of line 100 is missing the required block name argument.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::MissingArgumentException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingExceptionDetails)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("The annotation '@begin' at column 40 of line 100 is missing the required block name argument.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionWithUnsetSourceYieldsExceptionWithMessageGivingExceptionDetailsWithNoSource)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100);
        }
        catch (const MissingArgumentException& e) {
            Assert::AreEqual("The annotation '@begin' at column 40 of line 100 is missing the required block name argument.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionWithSetSourceInConstructorsYieldsMessageGivingExceptionDetailsIncludingSource)
    {
        try {
            throw MissingArgumentException("@begin", "block name", 40, 100, "sample.sh");
        }
        catch (const MissingArgumentException& e) {
            Assert::AreEqual("The annotation '@begin' at column 40 of line 100 in source file 'sample.sh' is missing the required block name argument.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MissingArgumentException, CatchingMissingArgumentExceptionWithSetSourceViaMethodYieldsMessageGivingExceptionDetailsIncludingSource)
    {
        try {
            auto exception = MissingArgumentException("@begin", "block name", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const MissingArgumentException& e) {
            Assert::AreEqual("The annotation '@begin' at column 40 of line 100 in source file 'sample.sh' is missing the required block name argument.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END