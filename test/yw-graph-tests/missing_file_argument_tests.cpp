
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingFileArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingFileArgument, WhenFileIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in p @file
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@file' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingFileArgument, WhenFileIsImmediatelyFollowedByOtherAnnotationReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @file @param
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@file' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingFileArgument, WhenFileIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @file ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@file' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingFileArgument, WhenfileIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @file ""
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@file' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingFileArgument, WhenfileIsImmediatelyFollowedByDoubleQuotedSpaceReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @file " "
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@file' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
