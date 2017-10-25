#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedEndException)

YW_TEST_SET

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionAsStdExceptionValueYieldsExceptionWithSlicingWarningInMessage)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (std::exception e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedEndException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
}

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionAsStdExceptionReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (const std::exception& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionAsStdRuntimeErrorValueYieldsExceptionWithSlicingWarningMessage)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (std::runtime_error e) {
            Assert::AreEqual("<sliced instance of yw::parse::MisplacedEndException>", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionAsStdRuntimeErrorReferenceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (const std::runtime_error& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionWithUnsetSourceYieldsExceptionWithMessageGivingColumnAndLine)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (const MisplacedEndException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionWithSetSourceInConstructorsYieldsMessageIncludingSource)
    {
        try {
            throw MisplacedEndException("@end", 40, 100, "sample.sh");
        }
        catch (const MisplacedEndException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CatchingMisplacedEndExceptionWithSetSourceViaMethodYieldsMessageIncludingSource)
    {
        try {
            auto exception = MisplacedEndException("@end", 40, 100);
            exception.setSource("sample.sh");
            throw exception;
        }
        catch (const MisplacedEndException& e) {
            Assert::AreEqual("The '@end' annotation was unexpected at column 40 of line 100 in source file 'sample.sh'.", e.what());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CallingGetDetailsOnMisplacedEndExceptionWithUnsetDetailsYieldsDefaultDetails)
    {
        try {
            throw MisplacedEndException("@end", 40, 100);
        }
        catch (const MisplacedEndException& e) {
            Assert::AreEqual("Each @end annotation is paired with the closest preceding @begin annotation to delimit a program block.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

    YW_TEST(MisplacedEndException, CallingGetDetailsOnMisplacedEndExceptionWithSetDetailsYieldsCustomDetails)
    {
        try {
            auto exception = MisplacedEndException("@end", 40, 100);
            exception.setDetails("Details about the exception.");
            throw exception;
        }
        catch (const MisplacedEndException& e) {
            Assert::IsTrue(e.getDetails().hasValue());
            Assert::AreEqual("Details about the exception.", e.getDetails().getValue());
            return;
        }
        Assert::Fail(L"Expected exception not caught.");
    }

YW_TEST_END