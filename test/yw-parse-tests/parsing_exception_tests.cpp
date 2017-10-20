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
            Expect::Fail();
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::ParsingException>", e.what());
        } 
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdExceptionReferenceYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw ParsingException();
            Expect::Fail();
        }
        catch (const std::exception& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw ParsingException();
            Expect::Fail();
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::ParsingException>", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw ParsingException();
            Expect::Fail();
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithUnsetSourceYieldsDefaultMessage)
    {
        try {
            throw ParsingException();
            Expect::Fail();
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw ParsingException("sample.sh");
            Expect::Fail();
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations in source sample.sh.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CatchingParsingExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = ParsingException("");
            exception.setSource("sample.sh");
            throw exception;
            Expect::Fail();
        }
        catch (const ParsingException& e) {
            Assert::AreEqual("A problem occurred parsing YW annotations in source sample.sh.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(ParsingException, CallingGetSourceOnParsingExceptionWithUnsetSourceYieldsNullableStringWithUnsetValue)
    {
        try {
            throw ParsingException();
            Expect::Fail();
        }
        catch (const ParsingException& e) {
            Assert::IsFalse(e.getSource().hasValue());
        }
        catch (...) { Expect::Fail(); }
    }


    YW_TEST(ParsingException, CallingGetSourceOnParsingExceptionWithSetSourceYieldsSource)
    {
        try {
            throw ParsingException("sample.sh");
            Expect::Fail();
        }
        catch (const ParsingException& e) {
            Assert::IsTrue(e.getSource().hasValue());
            Assert::AreEqual("sample.sh", e.getSource().getValue());
        }
        catch (...) { Expect::Fail(); }
    }

YW_TEST_END