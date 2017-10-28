
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingBeginArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingBeginArgument, WhenBeginIsOnlyAnnotationAndItHasNoArgumentReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

            # @begin

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBeginArgument, WhenBeginOfASingleBeginEndPairHasNoArgumentReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

                # @begin
                # @end

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBeginArgument, WhenBeginIsImmediatelyFollowedByOtherAnnotationReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

                # @begin @param
                # @end

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBeginArgument, WhenBeginIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

                # @begin ''
                # @end

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBeginArgument, WhenBeginIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

                # @begin ""
                # @end

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBeginArgument, WhenBeginIsImmediatelyFollowedByDoubleQuotedSingleSpaceReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(

                # @begin " "
                # @end

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@begin' at column 3 of line 1 in source file 'sample.yw' is missing the required block name argument."  EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
