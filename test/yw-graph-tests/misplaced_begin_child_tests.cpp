
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

  
    YW_TEST(MisplacedBeginChild, ErrorReportedWhenDescIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
                // @desc description

            )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@desc' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."   EOL
            "NOTE:  The @desc annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@desc' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."   EOL
            "NOTE:  The @desc annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@desc' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'."   EOL
            "NOTE:  The @desc annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@desc' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'."   EOL
            "NOTE:  The @desc annotation must be used within a program block and before any nested blocks."   EOL,
            stderrRecorder.str()
        );
    }

  

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenInIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @in p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@in' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  The @in annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@in' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'." EOL
            "NOTE:  The @in annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@in' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'." EOL
            "NOTE:  The @in annotation must be used within a program block and before any nested blocks."   EOL,
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
            "ERROR: The '@in' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'." EOL
            "NOTE:  The @in annotation must be used within a program block and before any nested blocks."   EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenOutIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @out p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@out' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."    EOL
            "NOTE:  The @out annotation must be used within a program block and before any nested blocks."      EOL,
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
            "ERROR: The '@out' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."    EOL
            "NOTE:  The @out annotation must be used within a program block and before any nested blocks."      EOL,
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
            "ERROR: The '@out' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'."    EOL
            "NOTE:  The @out annotation must be used within a program block and before any nested blocks."      EOL,
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
            "ERROR: The '@out' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'."    EOL
            "NOTE:  The @out annotation must be used within a program block and before any nested blocks."      EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(MisplacedBeginChild, ErrorReportedWhenParamIsOnlyAnnotation)
    {
        runGraphCLIOnMalformedInput(trimmargins(R"(
            
            // @param p

        )"), "sample.cpp");

        Assert::AreEqual(
            "ERROR: The '@param' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."  EOL
            "NOTE:  The @param annotation must be used within a program block and before any nested blocks."    EOL,
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
            "ERROR: The '@param' annotation was unexpected at column 4 of line 1 in source file 'sample.cpp'."  EOL
            "NOTE:  The @param annotation must be used within a program block and before any nested blocks."    EOL,
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
            "ERROR: The '@param' annotation was unexpected at column 4 of line 5 in source file 'sample.cpp'."  EOL
            "NOTE:  The @param annotation must be used within a program block and before any nested blocks."    EOL,
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
            "ERROR: The '@param' annotation was unexpected at column 4 of line 4 in source file 'sample.cpp'."  EOL
            "NOTE:  The @param annotation must be used within a program block and before any nested blocks."    EOL,
            stderrRecorder.str()
        );
    }


YW_TEST_END
