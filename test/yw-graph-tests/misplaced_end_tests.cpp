
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedEnd)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MisplacedEnd, ErrorReportedWhenEndIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @end

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@end' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."                    EOL
            "NOTE:  Each @end annotation is paired with the closest preceding @begin annotation to delimit a program block."    EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedEnd, ErrorReportedWhenEndPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @end
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@end' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."                    EOL
            "NOTE:  Each @end annotation is paired with the closest preceding @begin annotation to delimit a program block."    EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedEnd, ErrorReportedWhenEndFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @end

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@end' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'."                    EOL
            "NOTE:  Each @end annotation is paired with the closest preceding @begin annotation to delimit a program block."    EOL,
            stderrRecorder.str()
        );
    }

YW_TEST_END
