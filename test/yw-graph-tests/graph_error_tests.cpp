
#include "yw_graph_tests.h"
#include "yw_parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(GraphError)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source) {
        auto sourceFilePath = writeTempFile("sample.yw", source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsIn)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @in p"

        )"));

        Assert::AreEqual(
            "ERROR: There was a problem parsing the YW annotations in the source files."    EOL
            "CAUSE: An unexpected token '@in' was encountered on line 1 at column 3."       EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsDesc)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @desc description

        )"));

        Assert::AreEqual(
            "ERROR: There was a problem parsing the YW annotations in the source files."    EOL
            "CAUSE: An unexpected token '@desc' was encountered on line 1 at column 2."     EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(GraphError, ErrorReportedWhenOnlyAnnotationIsEnd)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

            /* @end w */

        )"));

        Assert::AreEqual(
            "ERROR: There was a problem parsing the YW annotations in the source files."    EOL
            "CAUSE: An unexpected token '@end' was encountered on line 1 at column 3."      EOL,
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

        )"));

        Assert::AreEqual(
            "ERROR: There was a problem parsing the YW annotations in the source files."    EOL
            "CAUSE: An unexpected token '@out' was encountered on line 4 at column 2."      EOL,
            stderrRecorder.str()
        );
    }

    //YW_TEST(GraphError, ErrorReportedBeginLacksProgramBlockName)
    //{
    //    runGraphCLIOnMalformedInput(trimmargins(R"(

    //        # @begin 
    //        # @end

    //    )"));

    //    Assert::AreEqual(
    //        "ERROR: There was a problem parsing the YW annotations in the source files."    EOL
    //        "CAUSE: An unexpected token '@out' was encountered on line 4 at column 2."      EOL,
    //        stderrRecorder.str()
    //    );
    //}

YW_TEST_END
