
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingBlockDescArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingBlockDescArgument, WhenProgramBlockDescIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @desc
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 3 of line 0 in source file 'sample.yw' is missing the required block description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBlockDescArgument, WhenProgramBlockDescIsImmediatelyFollowedByOtherAnnotationReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @desc @param
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 3 of line 0 in source file 'sample.yw' is missing the required block description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBlockDescArgument, WhenProgramBlockDescIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @desc ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 3 of line 0 in source file 'sample.yw' is missing the required block description argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingBlockDescArgument, WhenProgramBlockDescIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @desc ""
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 3 of line 0 in source file 'sample.yw' is missing the required block description argument."  EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(MissingBlockDescArgument, WhenProgramBlockDescIsImmediatelyFollowedByDoubleQuotedSingleSpaceReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @desc " "
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@desc' at column 3 of line 0 in source file 'sample.yw' is missing the required block description argument."  EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
