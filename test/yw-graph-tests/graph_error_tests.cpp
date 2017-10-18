
#include "yw_graph_tests.h"
#include "yw_parser_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(GraphError)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

YW_TEST_SET

    YW_TEST(GraphError, WorkflowPortFollowsNestedBlock)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

                @begin w
                    @begin b
                    @end b
                @out p
                @end w

        )");

        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });

        Assert::EmptyString(stdoutRecorder.str());
        //Assert::AreEqual(
        //    "Error extracting annotations: line 6:16 mismatched input '@out' expecting EndKeyword" EOL EOL,
        //     stderrRecorder.str());
    }

YW_TEST_END
