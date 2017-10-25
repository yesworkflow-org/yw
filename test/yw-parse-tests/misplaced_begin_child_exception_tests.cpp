#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedBeginChildException)

YW_TEST_SET

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedBeginChildException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("The '@in' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedBeginChildException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("The '@in' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (const MisplacedBeginChildException& e) {
            Assert::AreEqual("The '@in' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100, "sample.sh");
        }
        catch (const MisplacedBeginChildException& e) {
            Assert::AreEqual("The '@in' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CatchingMisplacedBeginChildExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = MisplacedBeginChildException("@in", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const MisplacedBeginChildException& e) {
            Assert::AreEqual("The '@in' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CallingGetDetailsOnMisplacedBeginChildExceptionWithUnsetDetailsYieldsDefaultDetails)
    {
        try {
            throw MisplacedBeginChildException("@in", 40, 100);
        }
        catch (const MisplacedBeginChildException& e) {
            Assert::AreEqual("The @in annotation must be used within a program block and before any nested blocks.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedBeginChildException, CallingGetDetailsOnMisplacedBeginChildExceptionnWithSetDetailYieldsCustomDetails)
    {
        try {
            auto exception = MisplacedBeginChildException("@in", 40, 100);
            exception.setDetails("Details about the exception.");
            throw exception;
        }
        catch (const MisplacedBeginChildException& e) {
            Assert::IsTrue(e.getDetails().hasValue());
            Assert::AreEqual("Details about the exception.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END