#include "yw_common_tests.h"

using namespace yw;
using namespace yw::test;

YW_TEST_FIXTURE(StdioRecorders)


YW_TEST_SET

    YW_TEST(StdioRecorders, NewStderrRecorderHasNoContent)
    {
        StderrRecorder recorder;
        Assert::EmptyString(recorder.str());
    }

    YW_TEST(StdioRecorders, StderrRecorderCapturesSingleOutputToStderr)
    {
        StderrRecorder recorder;
        std::cerr << "single output" << std::endl;

        Assert::AreEqual(
            "single output" EOL, 
            recorder.str()
        );
    }

    YW_TEST(StdioRecorders, StderrRecorderCapturesConsecutiveOutputsToStderr)
    {
        StderrRecorder recorder;
        std::cerr << "first output" << std::endl;
        std::cerr << "second output" << std::endl;

        Assert::AreEqual(
            "first output"  EOL
            "second output" EOL
            , recorder.str()
        );
    }

    YW_TEST(StdioRecorders, StderrRecorderAccumulatesFurtherOutputsFollowingStr)
    {
        StderrRecorder recorder;
        std::cerr << "first output" << std::endl;
        Expect::AreEqual("first output" EOL, recorder.str());

        std::cerr << "second output" << std::endl;

        Assert::AreEqual(
            "first output"  EOL
            "second output" EOL
            , recorder.str()
        );
    }

    YW_TEST(StdioRecorders, StderrRecorderInNestedBlockRestoresPriorStderrRecorderOnExit)
    {
        StderrRecorder outerRecorder;
        std::cerr << "first output to outer recorder" << std::endl;
        Expect::AreEqual("first output to outer recorder" EOL, outerRecorder.str());

        {
            StderrRecorder innerRecorder;
            std::cerr << "output to inner recorder" << std::endl;
            Expect::AreEqual("output to inner recorder" EOL, innerRecorder.str());
        }

        Expect::AreEqual("first output to outer recorder" EOL, outerRecorder.str());
        std::cerr << "second output to outer recorder" << std::endl;

        Assert::AreEqual(
            "first output to outer recorder"  EOL
            "second output to outer recorder" EOL
            , outerRecorder.str()
        );
    }

    YW_TEST(StdioRecorders, StderrRecorderFieldInClassInstanceCapturesOutput)
    {
        class A { public: StderrRecorder recorder; };
        A a;
        std::cerr << "first output" << std::endl;

        Expect::AreEqual("first output" EOL, a.recorder.str());
    }

    YW_TEST(StdioRecorders, StderrRecorderFieldInBaseClassInstanceCapturesOutputRecordedBySubclass)
    {
        class A { public: StderrRecorder recorder; };
        class B : public A {};
        B b;
        std::cerr << "first output" << std::endl;

        Expect::AreEqual("first output" EOL, b.recorder.str());
    }

    YW_TEST(StdioRecorders, ExceptionThrownBySubclassMethodRestoresOuterRecorder)
    {
        StderrRecorder outerRecorder;

        std::cerr << "first output" << std::endl;
        Expect::AreEqual("first output" EOL, outerRecorder.str());

        class A { public: StderrRecorder innerRecorder; };
        class B : public A { public: void f() { throw std::exception{}; } };

        try {
            B b;
            std::cerr << "second output" << std::endl;
            Expect::AreEqual("second output" EOL, b.innerRecorder.str());
            b.f();
        }
        catch (std::exception e) {
        }

        std::cerr << "third output" << std::endl;

        Assert::AreEqual(
            "first output"  EOL
            "third output"  EOL
            , outerRecorder.str()
        );

    }


YW_TEST_END
