
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(GraphError)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsIn)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @in p"

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@in' was encountered at column 3 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsDesc)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @desc description

        )"), "sample.sh");

        Assert::AreEqual(
            "ERROR: An unexpected token '@desc' was encountered at column 2 of line 1 in source file 'sample.sh'."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsEnd)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

            /* @end w */

        )"), "sample.c");

        Assert::AreEqual(
            "ERROR: An unexpected token '@end' was encountered at column 3 of line 1 in source file 'sample.c'."    EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedWhenWorkflowPortFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

            # @begin w
            #    @begin b
            #    @end b
            # @out p
            # @end w

        )"), "sample.py");

        Assert::AreEqual(
            "ERROR: An unexpected token '@out' was encountered at column 2 of line 4 in source file 'sample.py'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedBeginLacksProgramBlockName)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

            # @begin 
            # @end

        )"));

        Assert::AreEqual(
            "ERROR: An annotation syntax error was encountered at column 2 of line 1 in source file 'sample.yw'."   EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
