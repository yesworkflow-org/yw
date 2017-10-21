#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(ParsingException)

YW_TEST_SET

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw ParsingException();
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::ParsingException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdExceptionReferenceYieldsExceptionWithDefaultMessage)
    {
        try {
            throw ParsingException();
        }
        catch (const std::exception& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw ParsingException();
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::ParsingException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithDefaultMessage)
    {
        try {
            throw ParsingException();
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithUnsetSourceYieldsDefaultMessage)
    {
        try {
            throw ParsingException();
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw ParsingException("sample.sh");
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = ParsingException();
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(ParsingException, CallingGetSourceOnParsingExceptionWithUnsetSourceYieldsNullableStringWithUnsetValue)
    {
        try {
            throw ParsingException();
        }
        catch (const ParsingException& e) {
            Assert::IsFalse(e.getSource().hasValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }


    YW_TEST(ParsingException, CallingGetSourceOnParsingExceptionWithSetSourceYieldsSource)
    {
        try {
            throw ParsingException("sample.sh");
        }
        catch (const ParsingException& e) {
            Assert::IsTrue(e.getSource().hasValue());
            Assert::AreEqual("sample.sh", e.getSource().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END