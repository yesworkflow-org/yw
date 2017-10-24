
#include "yw_graph_tests.h"
#include "parsing_exception.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(MisplacedBeginChild)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

    void runGraphCLIOnMalformedInput(std::string source, std::string fileName="sample.yw") {
        auto sourceFilePath = writeTempFile(fileName, source);
        yw::graph::cli(CommandLine{ "yw graph " + sourceFilePath });
        Expect::EmptyString(stdoutRecorder.str());
    }

YW_TEST_SET

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenAsIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @as alias

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@as' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenAsPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @as alias
                        // @begin b
                        // @end b

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@as' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenAsFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @begin b 
                        // @begin c 
                        // @end c 
                        // @end b 
                        // @as alias

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@as' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenAsFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                        // @begin b 
                        // @begin c 
                        // @end c 
                        // @as alias
                        // @end b 

                    )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@as' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenDescIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @desc description

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@desc' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenDescPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @desc description
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@desc' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenDescFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @desc description

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@desc' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenDescFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @desc description
                    // @end b 

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@desc' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenEndIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @end

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@end' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenEndPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @end
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@end' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenEndFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @end

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@end' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenFileIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @file path

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@file' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenFilePrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @file path
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@file' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenFileFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @file path

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@file' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenFileFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @file path
                    // @end b 

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@file' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenInIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @in p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@in' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenInPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @in p
                // @begin b
                // @end b

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@in' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenInFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @end b 
                // @in p 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@in' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenInFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @in p 
                // @end b 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@in' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenOutIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @out p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@out' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenOutPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @out p
                // @begin b
                // @end b

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@out' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenOutFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @end b 
                // @out p 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@out' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenOutFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @out p 
                // @end b 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@out' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenParamIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @param p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@param' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenParamPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @param p
                // @begin b
                // @end b

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@param' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenParamFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @end b 
                // @param p 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@param' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenParamFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @begin b 
                // @begin c 
                // @end c 
                // @param p 
                // @end b 

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@param' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenUriIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @uri path

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@uri' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenUriPrecedesFirstBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @uri path
                    // @begin b
                    // @end b

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@uri' was encountered at column 4 of line 1 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenUriFollowsAllBlocks)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @end b 
                    // @uri path

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@uri' was encountered at column 4 of line 5 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenUriFollowsNestedBlock)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                    // @begin b 
                    // @begin c 
                    // @end c 
                    // @uri path
                    // @end b 

                )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: An unexpected token '@uri' was encountered at column 4 of line 4 in source file 'sample.cpp'."   EOL,
            stderrRecorder.str()
        );
    }


YW_TEST_END
