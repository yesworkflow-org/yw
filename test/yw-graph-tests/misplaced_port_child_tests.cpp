
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedPortChild)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MisplacedPortChild, ErrorReportedWhenAsIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @as alias

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@as' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @as annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenAsPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @as alias
                        // @begin b
                        // @end b

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@as' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @as annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenAsFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @begin b 
                        // @begin c 
                        // @end c 
                        // @end b 
                        // @as alias

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@as' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'." EOL
            "NOTE:  Each @as annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenAsFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @begin b 
                        // @begin c 
                        // @end c 
                        // @as alias
                        // @end b 

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@as' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'." EOL
            "NOTE:  Each @as annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(MisplacedPortChild, ErrorReportedWhenFileIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @file path

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@file' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @file annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenFilePrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @file path
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@file' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @file annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenFileFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @file path

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@file' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'." EOL
            "NOTE:  Each @file annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenFileFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @file path
                    // @end b 

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@file' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'." EOL
            "NOTE:  Each @file annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }


   
    YW_TEST(MisplacedPortChild, ErrorReportedWhenUriIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @uri path

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@uri' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @uri annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenUriPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @uri path
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@uri' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  Each @uri annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedPortChild, ErrorReportedWhenUriFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @uri path

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@uri' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'." EOL
            "NOTE:  Each @uri annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }
    
    YW_TEST(MisplacedPortChild, ErrorReportedWhenUriFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @uri path
                    // @end b 

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@uri' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'." EOL
            "NOTE:  Each @uri annotation must follow and qualify a port (@in, @out or @param) annotation."   EOL,
            stderrRecorder.str()
        );
    }


YW_TEST_END
