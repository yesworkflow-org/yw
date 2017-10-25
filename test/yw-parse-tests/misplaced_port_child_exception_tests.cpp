#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedPortChildException)

YW_TEST_SET

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedPortChildException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("The '@as' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedPortChildException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("The '@as' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (const MisplacedPortChildException& e) {
            Assert::AreEqual("The '@as' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100, "sample.sh");
        }
        catch (const MisplacedPortChildException& e) {
            Assert::AreEqual("The '@as' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CatchingMisplacedPortChildExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = MisplacedPortChildException("@as", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const MisplacedPortChildException& e) {
            Assert::AreEqual("The '@as' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CallingGetDetailsOnMisplacedPortChildExceptionWithUnsetDetailsYieldsDefaultDetsils)
    {
        try {
            throw MisplacedPortChildException("@as", 40, 100);
        }
        catch (const MisplacedPortChildException& e) {
            Assert::AreEqual("Each @as annotation must follow and qualify a port (@in, @out or @param) annotation.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedPortChildException, CallingGetDetailsOnMisplacedPortChildExceptionnWithSetDetailsYieldsCustomDetails)
    {
        try {
            auto exception = MisplacedPortChildException("@as", 40, 100);
            exception.setDetails("Details about the exception.");
            throw exception;
        }
        catch (const MisplacedPortChildException& e) {
            Assert::IsTrue(e.getDetails().hasValue());
            Assert::AreEqual("Details about the exception.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END