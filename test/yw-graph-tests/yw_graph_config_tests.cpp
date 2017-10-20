
#include "yw_graph_tests.h"

using namespace yw;
using namespace yw::cli;
using namespace yw::test;

YW_TEST_FIXTURE(WorkflowGraphConfig)

    StderrRecorder stderrRecorder;
    StdoutRecorder stdoutRecorder;

YW_TEST_SET

    YW_TEST(WorkflowGraphConfig, LocalConfigFileCanOverrideDefaultGraphCommentSetting)
    {
        auto configFilePath = writeTempFile("yw.properties", R"(

                graph.comments = OFF

            )");

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
            "yw graph " + sourceFilePath + " yw.config=" + configFilePath
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


    YW_TEST(WorkflowGraphConfig, LocalConfigFileCanSpecifyTheSource)
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

        auto configFilePath = writeTempFile("yw.properties", "extract.sources = " + sourceFilePath);
        yw::graph::cli(CommandLine("yw graph graph.comments=OFF yw.config=" + configFilePath));

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


    YW_TEST(WorkflowGraphConfig, LocalConfigFileCanSpecifyTwoSources)
    {
        auto sourceFilePath1 = writeTempFile("sample.yw.1", R"(

                    @begin b3
                    @end b3

                )");
        
        auto sourceFilePath2 = writeTempFile("sample.yw.2", R"(
        
                    @begin w
                        @begin b1
                        @out d1
                        @end b1

                        @begin b2
                        @in d1
                        @end b2                    
                    @end w

                )");

        auto configFilePath = writeTempFile(
            "yw.properties", 
            "extract.sources = " + sourceFilePath1 + ",  " + sourceFilePath2);
        yw::graph::cli(CommandLine("yw graph graph.comments=OFF graph.workflow=w yw.config=" + configFilePath));

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
