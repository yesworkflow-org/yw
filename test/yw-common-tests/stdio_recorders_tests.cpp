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

        Assert::AreEqual("single output" EOL, recorder.str());
    }

    YW_TEST(StdioRecorders, StderrRecorderCapturesConsecutiveOutputsToStderr)
    {
        StderrRecorder recorder;
        std::cerr << "first output" << std::endl;
        std::cerr << "second output" << std::endl;

        Assert::AreEqual(
            "first output"  EOL
            "second output" EOL
            , recorder.str());
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
            , recorder.str());
    }


YW_TEST_END
