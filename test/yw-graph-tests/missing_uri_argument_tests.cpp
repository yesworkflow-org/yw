
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MissingUriArgument)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MissingUriArgument, WhenUriIsLastTokenOnLineReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
            # @begin b
            # @in p @uri
            # @end b

        )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingUriArgument, WhenUriIsImmediatelyFollowedByOtherAnnotationReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @uri @param
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingUriArgument, WhenUriIsImmediatelyFollowedByEmptyPairOfSingleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @uri ''
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingUriArgument, WhenUriIsImmediatelyFollowedByEmptyPairOfDoubleQuotesReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @uri ""
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingUriArgument, WhenUriIsImmediatelyFollowedByDoubleQuotedSpaceReportMissingArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @uri " "
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MissingUriArgument, WhenUriIsOnlySchemaSpaceReportMissingPathArgument)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
        
                # @begin b
                # @in p @uri http:
                # @end b

            )"));

        Assert::AreEqual(
            "ERROR: The annotation '@uri' at column 9 of line 2 in source file 'sample.yw' is missing the required path template argument."  EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
