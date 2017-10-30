
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingPortArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingPortArgument, WhenInKeywordIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedEndKeywordOnSameLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in ""
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByDoubleQuotedSpaceReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in " "
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByDescKeywordWithNoArgumentReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in @desc
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByDescKeywordWithDoubleQuotedTextArgumentReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in @desc "description of port"
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortArgument, WhenInKeywordIsImmediatelyFollowedByDescKeywordWithDoubleQuotedSingleSpaceArgumentReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in @desc " "
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@in' at column 3 of line 2 in source file 'sample.yw' is missing the required port name argument."  EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
