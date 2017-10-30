
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingPortAsArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingPortAsArgument, WhenAsIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in p @as
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
            stderrRecorder.str()
        );
    }

   YW_TEST(MissingPortAsArgument, WhenAsIsImmediatelyFollowedByDescKeywordReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @as @param
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
            stderrRecorder.str()
        );
    }

   YW_TEST(MissingPortAsArgument, WhenAsIsImmediatelyFollowedByEndKeywordReportMissingArgument)
   {
       runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @as @end

            )"));

       Assert::AreEqual(
           "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
           stderrRecorder.str()
       );
   }

   YW_TEST(MissingPortAsArgument, WhenAsIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @as ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
            stderrRecorder.str()
        );
    }

   YW_TEST(MissingPortAsArgument, WhenAsIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
   {
       runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @as ""
                # @end b

            )"));

       Assert::AreEqual(
           "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
           stderrRecorder.str()
       );
   }
   YW_TEST(MissingPortAsArgument, WhenAsIsImmediatelyFollowedByDoubleQuotedSpaceReportMissingArgument)
   {
       runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @as " "
                # @end b

            )"));

       Assert::AreEqual(
           "ERROR: The annotation '@as' at column 9 of line 2 in source file 'sample.yw' is missing the required data name argument."  EOL,
           stderrRecorder.str()
       );
   }

YW_TEST_END
