
#include "yw_graph_tests.h"
#include "random_testing.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(WorkflowGraphCLI)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

YW_TEST_SET

    YW_TEST(WorkflowGraphCLI, RunningWithNoCommandYieldsErrorMessage)
    {
        yw::graph::cli(CommandLine(trimmargins(R"(

            yw

        )")));

        Assert::EmptyString(stdoutRecorder.str());
        Assert::AreEqual(trimmargins(R"(
            
            ERROR: Command must be first non-option argument to YesWorkflow
            
            USAGE: yw <command> [source files] [options]
            
            Command                    Function
            -------                    --------
            graph                      Graphically renders workflow model of script.
            
            Option                     Description
            ------                     -----------
            -h, --help                 Displays detailed help including available 
                                         configuration options.
            <setting>=<value>          Assigns value to configuration setting.

        )"), trimmargins(stderrRecorder.str()) );
    }

    YW_TEST(WorkflowGraphCLI, RunningWithNoArgumentsYieldsErrorMessage)
    {
        yw::graph::cli(CommandLine(trimmargins(R"(

            yw graph

        )")));

        Assert::EmptyString(stdoutRecorder.str());
        Assert::AreEqual(trimmargins(R"(

            ERROR: No source files given as arguments.
            
            USAGE: yw <command> [source files] [options]
            
            Command                    Function
            -------                    --------
            graph                      Graphically renders workflow model of script.
            
            Option                     Description
            ------                     -----------
            -h, --help                 Displays detailed help including available 
                                         configuration options.
            <setting>=<value>          Assigns value to configuration setting.

        )"), trimmargins(stderrRecorder.str()));
    }

    YW_TEST(WorkflowGraphCLI, RunningWithHelpOptionDisplaysAvailableOptions)
    {
        yw::graph::cli(CommandLine(trimmargins(R"(

            yw -h

        )")));

        Assert::EmptyString(stdoutRecorder.str());
        Assert::AreEqual(trimmargins(R"(

            USAGE: yw <command> [source files] [options]
            
            Command                    Function
            -------                    --------
            graph                      Graphically renders workflow model of script.
            
            Option                     Description
            ------                     -----------
            -h, --help                 Displays detailed help including available 
                                         configuration options.
            <setting>=<value>          Assigns value to configuration setting.
            
            Setting                    Values (* indicates default)
            -------------              ----------------------------
            extract.sources            List of source files to extract annotations from
            graph.datalabel            Info to display in data nodes (NAME*, URI, or BOTH)
            graph.edgelabels           Labels on edges in process view (SHOW or HIDE*)
            graph.file                 Name of workflow graph image file to write
            graph.format               Format of workflow graph image file to write (DOT* or SVG)
            graph.layout               Direction of graph layout (TB*, LR, RL, or BT)
            graph.params               Visibility of parameters (SHOW or REDUCE*)
            graph.portlayout           Layout mode for workflow ports (GROUP*, RELAX, or HIDE)
            graph.programlabel         Info to display in program nodes (NAME*, DESCRIPTION, or BOTH)
            graph.title                Title for the graph as a whole
            graph.titleposition        Where to place graph title (TOP*, BOTTOM, or HIDE)
            graph.view                 Workflow view to render (PROCESS, DATA, or COMBINED*)
            graph.workflow             Name of workflow to graph
            graph.workflowbox          Box around nodes internal to workflow (SHOW* or HIDE)
            yw.config                  Name of local YW configuration file

        )"), trimmargins(stderrRecorder.str()));
    }

    YW_TEST(WorkflowGraphCLI, RunningOnEmptyModelYieldsDotFileWithNoNodes)
    {
        auto sourceFilePath = writeTempFile("sample.yw",R"(

            @begin workflow
            @end workflow

        )");

        yw::graph::cli(CommandLine(
            "yw graph " + sourceFilePath
        ));

        Assert::EmptyString(stderrRecorder.str());
        Assert::AreEqual((trimmargins(R"(

            digraph workflow {
            
            /* Start of box around nodes in workflow */
            subgraph cluster_workflow_box_outer { label=""; color=black; penwidth=2
            subgraph cluster_workflow_box_inner { label=""; penwidth=0
            
            /* End of box around nodes in workflow */
            }}
            }

        )"))
        , stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningOnEmptyModelWithGraphFormatSVGYieldsSvgFileWithNoNodes)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

            @begin workflow
            @end workflow

        )");

        yw::graph::cli(CommandLine(
            "yw graph graph.format=SVG " + sourceFilePath
        ));

        Assert::EmptyString(stderrRecorder.str());
        Assert::AreEqual((trimmargins(R"XML(

            <?xml version="1.0" encoding="UTF-8" standalone="no"?>
            <!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN"
             "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
            <!-- Generated by graphviz version 2.39.20160612.1140 (20090106.0545)
             -->
            <!-- Title: workflow Pages: 1 -->
            <svg width="8pt" height="8pt"
             viewBox="0.00 0.00 8.00 8.00" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
            <g id="graph0" class="graph" transform="scale(1 1) rotate(0) translate(4 4)">
            <title>workflow</title>
            <polygon fill="white" stroke="transparent" points="-4,4 -4,-4 4,-4 4,4 -4,4"/>
            </g>
            </svg>

        )XML"))
            , stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningOnEmptyModelWithGraphFormatLowercaseSvgYieldsSvgFileWithNoNodes)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

            @begin workflow
            @end workflow

        )");

        yw::graph::cli(CommandLine(
            "yw graph graph.format=svg " + sourceFilePath
        ));

        Assert::EmptyString(stderrRecorder.str());
        Assert::AreEqual((trimmargins(R"XML(

            <?xml version="1.0" encoding="UTF-8" standalone="no"?>
            <!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN"
             "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">
            <!-- Generated by graphviz version 2.39.20160612.1140 (20090106.0545)
             -->
            <!-- Title: workflow Pages: 1 -->
            <svg width="8pt" height="8pt"
             viewBox="0.00 0.00 8.00 8.00" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
            <g id="graph0" class="graph" transform="scale(1 1) rotate(0) translate(4 4)">
            <title>workflow</title>
            <polygon fill="white" stroke="transparent" points="-4,4 -4,-4 4,-4 4,4 -4,4"/>
            </g>
            </svg>

        )XML"))
            , stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningOnTwoProgramBlockWorkflowYieldsDotFileWithNodesAndEdgesAndComments)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

                @begin w
                
                    @begin b1
                    @out d1
                    @end b1
                
                    @begin b2
                    @in d1
                    @end b2
                
                @end w

            )");

        yw::graph::cli(CommandLine(
            "yw graph " + sourceFilePath
        ));

        Assert::EmptyString(stderrRecorder.str());

        Assert::AreEqual(trimmargins(R"(

            digraph w {
            
            /* Start of box around nodes in workflow */
            subgraph cluster_workflow_box_outer { label=""; color=black; penwidth=2
            subgraph cluster_workflow_box_inner { label=""; penwidth=0
            
            /* Style for nodes representing program blocks in workflow */
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            
            /* Nodes representing program blocks in workflow */
            b1
            b2
            
            /* Style for nodes representing data blocks in workflow */
            node[shape=box style="rounded,filled" fillcolor="#FFFFCC" peripheries=1 fontname=Helvetica]
            
            /* Nodes representing data blocks in workflow */
            d1
            
            /* Edges representing flow of data into and out of code blocks */
            d1 -> b2
            b1 -> d1
            
            /* End of box around nodes in workflow */
            }}
            }

            )"), stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningWithCommentsOffOnTwoProgramBlockWorkflowYieldsDotFileWithNodesAndEdgesAndNoComments)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

                @begin w

                    @begin b1
                    @out d1
                    @end b1

                    @begin b2
                    @in d1
                    @end b2

                @end w

            )");

        yw::graph::cli(CommandLine(
            "yw graph " + sourceFilePath + " graph.comments=OFF"
        ));

        Assert::EmptyString(stderrRecorder.str());
        Assert::AreEqual(trimmargins(R"(

            digraph w {
            subgraph cluster_workflow_box_outer { label=""; color=black; penwidth=2
            subgraph cluster_workflow_box_inner { label=""; penwidth=0
            node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
            b1
            b2
            node[shape=box style="rounded,filled" fillcolor="#FFFFCC" peripheries=1 fontname=Helvetica]
            d1
            d1 -> b2
            b1 -> d1
            }}
            }

            )"), stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, AnnotationListenerReportsParsingErrorFoundWhenParsingEmptyString)
    {
        auto sourceFilePath = writeTempFile("sample.yw", "");

        yw::graph::cli(CommandLine(
            "yw graph " + sourceFilePath + " graph.comments=OFF"
        ));
        Assert::AreEqual(
            "ERROR: The end of the file was reached unexpectedly while parsing annotations in source file 'sample.yw'." EOL, 
            stderrRecorder.str()
        );
    }

    YW_TEST(WorkflowGraphCLI, AnnotationListenerReportsErrorWhenCommandProgramSpecificOptionValueIsNotValid)
    {
        yw::graph::cli(CommandLine(
            "yw graph graph.format=FOO"
        ));
        Assert::AreEqual(
            "ERROR: Setting value FOO is not one of the allowed values (DOT* or SVG) for setting 'graph.format'." EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(WorkflowGraphCLI, AnnotationListenerReportsErrorWhenGraphOptionValueIsNotValid)
    {
        auto sourceFilePath = writeTempFile("sample.yw", R"(

            @begin workflow
            @end workflow

        )");

        yw::graph::cli(CommandLine(
            "yw graph graph.view=FOO " + sourceFilePath
        ));

        Assert::AreEqual(
            "ERROR: Setting value FOO is not one of the allowed values (PROCESS, DATA, or COMBINED*) for setting 'graph.view'." EOL,
            stderrRecorder.str()
        );
    }

    YW_TEST(WorkflowGraphCLI, AnnotationListenerReportsErrorWhenCommandLineOptionValueIsNotValid)
    {
        yw::graph::cli(CommandLine(
            "yw graph graph.format=FOO"
        ));

        Assert::AreEqual(
            "ERROR: Setting value FOO is not one of the allowed values (DOT* or SVG) for setting 'graph.format'." EOL,
            stderrRecorder.str()
        );
    }


    YW_TEST(WorkflowGraphCLI, AnnotationListenerCanParseRandomASCIITextWithoutNullPointerErrors)
    {
        RandomTextGenerator r;
        r.setSeed(42);
        for (int i = 0; i < 100; ++i) {
            auto text = r.getRandomASCIIText(10000);
            auto sourceFilePath = writeTempFile("sample.yw", text);
            yw::graph::cli(CommandLine( "yw graph " + sourceFilePath ));
        }
    }


    //YW_TEST(WorkflowGraphCLI, SimulateDataCollection)
    //{
    //    yw::graph::cli(CommandLine(
    //        "yw graph C:/Users/tmcphill/GitRepos/yw-prototypes/examples/simulate_data_collection/simulate_data_collection.py"
    //    ));

    //    Assert::EmptyString(stderrRecorder.str());
    //    Assert::AreEqual(trimmargins(R"(

    //        digraph w {
    //        subgraph cluster_workflow_box_outer { label=""; color=black; penwidth=2
    //        subgraph cluster_workflow_box_inner { label=""; penwidth=0
    //        node[shape=box style=filled fillcolor="#CCFFCC" peripheries=1 fontname=Helvetica]
    //        b1
    //        b2
    //        node[shape=box style="rounded,filled" fillcolor="#FFFFCC" peripheries=1 fontname=Helvetica]
    //        d1
    //        d1 -> b2
    //        b1 -> d1
    //        }}
    //        }

    //        )"), stdoutRecorder.str());
    //}
YW_TEST_END
