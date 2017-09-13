
#include "yw_graph_tests.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(WorkflowGraphCLI)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

YW_TEST_SET

    YW_TEST(WorkflowGraphCLI, RunningWithNoCommandYieldsErrorMessage)
    {
        auto commandLine = yw::cli::CommandLine("yw");
        yw::graph::main(commandLine);

        Assert::AreEqual("Error: No command given." EOL, stderrRecorder.str());
        Assert::AreEqual("Usage: yw graph <path-to-script>" EOL, stdoutRecorder.str());
}

    YW_TEST(WorkflowGraphCLI, RunningWithNoArgumentsYieldsErrorMessage)
    {
        auto commandLine = yw::cli::CommandLine("yw graph"); 
        yw::graph::main(commandLine);

        Assert::AreEqual("Error: No file names given as arguments." EOL, stderrRecorder.str());
        Assert::AreEqual("Usage: yw graph <path-to-script>" EOL, stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningOnMinimalModelYieldsDotFile)
    {
        auto sourceFilePath = writeTempFile(
            "hello.py",
            R"(
                @begin workflow
                @end workflow
            )");

        auto commandLine = yw::cli::CommandLine("yw graph " + sourceFilePath);
        yw::graph::main(commandLine);

        Assert::EmptyString(stderrRecorder.str());
        Assert::AreEqual(
            "digraph workflow {"    EOL
            "}"                     EOL
        , stdoutRecorder.str());
    }

YW_TEST_END
