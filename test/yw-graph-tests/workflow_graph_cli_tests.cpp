
#include "yw_graph_tests.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(WorkflowGraphCLI)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

YW_TEST_SET

    YW_TEST(WorkflowGraphCLI, RunningWithNoCommandYieldsErrorMessage)
    {
        yw::graph::cli(CommandLine(
            "yw"
        ));

        Assert::AreEqual("Error: No command given." EOL, stderrRecorder.str());
        Assert::AreEqual("Usage: yw graph <path-to-script>" EOL, stdoutRecorder.str());
    }

    YW_TEST(WorkflowGraphCLI, RunningWithNoArgumentsYieldsErrorMessage)
    {
        yw::graph::cli(CommandLine(
            "yw graph"
        ));

        Assert::AreEqual("Error: No file names given as arguments." EOL, stderrRecorder.str());
        Assert::AreEqual("Usage: yw graph <path-to-script>" EOL, stdoutRecorder.str());
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


YW_TEST_END
