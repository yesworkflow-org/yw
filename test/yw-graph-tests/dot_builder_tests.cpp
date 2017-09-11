
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
        
        Assert::AreEqual(
            "digraph Workflow {"    EOL
        , dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphUsesNondefaultLayoutAsRankdir)
    {
        configuration.insert({ Setting{ "graph.layout", "LR", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual(
            "digraph Workflow {"    EOL
            "rankdir=LR"            EOL
            , dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphDisplaysTitleIfTitleNotNull)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual(
            "digraph Workflow {"                            EOL
            "fontname=Helvetica; fontsize=18; labelloc=1"   EOL
            "label=\"Title of my graph\""                   EOL
            , dotBuilder.str());
    }

    YW_TEST(DotBuilder, CommentIsHiddenByDefault)
    {
        DotBuilder dotBuilder;
        dotBuilder.comment("A comment that should be hidden");

        Assert::EmptyString(dotBuilder.str());
    }

    YW_TEST(DotBuilder, CommentIsShownIfCommentsEnabled)
    {
        configuration.insert({ Setting{ "graph.comments", "ON", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.comment("A comment that should be shown");

        Assert::AreEqual(
            ""                                      EOL
            "/* A comment that should be shown */"  EOL
            , dotBuilder.str());
    }

    YW_TEST(DotBuilder, BeginGraphIncludesCommentIfTitleNotNullAndCommentsEnabled)
    {
        configuration.insert({ Setting{ "graph.title", "Title of my graph", Setting::SettingSource::COMMAND_LINE } });
        configuration.insert({ Setting{ "graph.comments", "ON", Setting::SettingSource::COMMAND_LINE } });
        DotBuilder dotBuilder(configuration);
        dotBuilder.beginGraph();

        Assert::AreEqual(
            "digraph Workflow {"                            EOL
            ""                                              EOL
            "/* Title for graph */"                         EOL
            "fontname=Helvetica; fontsize=18; labelloc=1"   EOL
            "label=\"Title of my graph\""                   EOL
            , dotBuilder.str());
    }

    YW_TEST_END
