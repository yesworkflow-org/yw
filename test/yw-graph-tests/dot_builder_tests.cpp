
#include "yw_graph_tests.h"

using namespace yw;
using namespace yw::config;
using namespace yw::graph;
using namespace yw::test;

YW_TEST_FIXTURE(DotBuilder)

    Configuration configuration;

    YW_TEST_SETUP(DotBuilder) {
    }

YW_TEST_SET

    YW_TEST(DotBuilder, EmptyDotBuilderReturnsEmptyString)
    {
        DotBuilder dotBuilder;
        
        Assert::EmptyString(dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphByDefaultStartsADigraphNamedWorkflow)
    {
        DotBuilder dotBuilder;
        dotBuilder.beginGraph();
        
        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {

        )")) , dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphUsesNondefaultLayoutAsRankdir)
    {
        configuration.insert({ Setting{ "graph.layout", "LR", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {
            rankdir=LR

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphDisplaysTitleAtTopIfTitleNotNullAndTitlePositionIsDefault)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {
            fontname=Helvetica; fontsize=18; labelloc=t
            label="Title of my graph"

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphDisplaysTitleAtBottomIfTitleNotNullAndTitlePositionIsConfiguredAsBottom)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.titleposition", "BOTTOM", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {
            fontname=Helvetica; fontsize=18; labelloc=b
            label="Title of my graph"

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphHidesTitleIfTitleNotNullButTitlePositionIsHide)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.titleposition", "HIDE", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, CommentIsHiddenIfDisabled)
    {
        configuration.insert({ Setting{ "graph.comments", "OFF", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.comment("A comment that should be hidden");

        Assert::EmptyString(dotBuilder.str());
    }

    YW_TEST(DotBuilder, CommentIsShownByDefault)
    {
        DotBuilder dotBuilder;
        dotBuilder.comment("A comment that should be shown");

        Assert::AreEqual(

            ""                                      EOL  
            "/* A comment that should be shown */"  EOL

            , dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphIncludesCommentIfTitleNotNullAndCommentsEnabled)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual((trimmargins(R"(

            digraph Workflow {
            
            /* Title for graph */
            fontname=Helvetica; fontsize=18; labelloc=t
            label="Title of my graph"

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, EndGraphAppendsClosingBraceAndNewline)
    {
        DotBuilder dotBuilder;
        dotBuilder.endGraph();

        Assert::AreEqual((trimmargins(R"(

            }

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, NodeIncludesLabelWhenItDiffersFromName) 
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the_node_name", "the_node_label");

        Assert::AreEqual((trimmargins(R"(

            the_node_name [label=the_node_label]

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, NodeDoesNotIncludeLabelWhenItIsSameAsName)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the_node_name", "the_node_name");

        Assert::AreEqual((trimmargins(R"(

            the_node_name

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, NodeNameIsQuotedWhenItIncludesSpaces)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the node name", "the_node_label");

        Assert::AreEqual((trimmargins(R"(

            "the node name" [label=the_node_label]

            , dotBuilder.str());

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, NodeNameIsQuotedWhenItIncludesDoubleQuoteSymbol)
    {
        DotBuilder dotBuilder;
        dotBuilder.node(R"(the "node" name)", "the_node_label");

        Assert::AreEqual((trimmargins(R"(

            "the \"node\" name" [label=the_node_label]

        )")) , dotBuilder.str());
    }


    YW_TEST(DotBuilder, NodeLabelIsQuotedWhenItIncludesSpaces)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the_node_name", "the node label");

        Assert::AreEqual((trimmargins(R"(

            the_node_name [label="the node label"]

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, NodeLabelIsQuotedWhenItIncludeDoubleQUoteSymbol)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the_node_name", R"(the "node" label)");

        Assert::AreEqual((trimmargins(R"(

            the_node_name [label="the \"node\" label"]

        )")) , dotBuilder.str());
    }

    YW_TEST(DotBuilder, SingleArgumentNodeYieldsUnquotedNameWhenItIncludesNoSpaces)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the_node_name");

        Assert::AreEqual((trimmargins(R"(

            the_node_name

        )")), dotBuilder.str());
    }

    YW_TEST(DotBuilder, SingleArgumentNodeYieldsQuotedNameWhenItIncludesSpaces)
    {
        DotBuilder dotBuilder;
        dotBuilder.node("the node name");

        Assert::AreEqual((trimmargins(R"(

            "the node name"

        )")), dotBuilder.str());
    }

YW_TEST_END
