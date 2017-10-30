
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingPortDescArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingPortDescArgument, WhenPortDescIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in p @desc
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 9 of line 2 in source file 'sample.yw' is missing the required port description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortDescArgument, WhenPortDesccIsImmediatelyFollowedByOtherAnnotationReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @desc @param
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 9 of line 2 in source file 'sample.yw' is missing the required port description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortDescArgument, WhenPortDescIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @desc ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 9 of line 2 in source file 'sample.yw' is missing the required port description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingPortDescArgument, WhenPortDescIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @desc ""
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 9 of line 2 in source file 'sample.yw' is missing the required port description argument."  EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(MissingPortDescArgument, WhenPortDescFollowingInPortWithMissingArgumentIsImmediatelyFollowedByDoubleQuotedSingleSpaceReportMissingArgument)
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

    YW_TEST(MissingPortDescArgument, WhenPortDescWithValidArgumentFollowsInPortWithMissingArgumentReportPortHasMissingArgument)
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

YW_TEST_END
