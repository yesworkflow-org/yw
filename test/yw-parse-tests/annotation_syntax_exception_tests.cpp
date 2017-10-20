#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(AnnotationSyntaxException)

YW_TEST_SET

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw AnnotationSyntaxException(100, 40);
            Expect::Fail();
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::AnnotationSyntaxException>", e.what());
        } 
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(100, 40);
            Expect::Fail();
        }
        catch (const std::exception& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw AnnotationSyntaxException(100, 40);
            Expect::Fail();
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::AnnotationSyntaxException>", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(100, 40);
            Expect::Fail();
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw AnnotationSyntaxException(100, 40);
            Expect::Fail();
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw AnnotationSyntaxException(100, 40, "sample.sh");
            Expect::Fail();
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }


    YW_TEST(AnnotationSyntaxException, CatchingAnnotationSyntaxExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = AnnotationSyntaxException(100, 40);
            exception.setSource("sample.sh");
            throw exception;
            Expect::Fail();
        }
        catch (const AnnotationSyntaxException& e) {
            Assert::AreEqual("An annotation syntax error was encountered at column 40 of line 100 in source file 'sample.sh'.", e.what());
        }
        catch (...) { Expect::Fail(); }
    }

YW_TEST_END