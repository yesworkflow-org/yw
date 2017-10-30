#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(IoListener)

    StubYWListener listener;
    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(IoListener, In)
    {
        YWParserBuilder parser_builder("@in p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, In_Desc)
    {
        YWParserBuilder parser_builder("@in p @desc a single input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "entered port attribute"        EOL
            "entered port desc"             EOL
            "entered description"           EOL
            "exited description"            EOL
            "exited port desc"              EOL
            "exited port attribute"         EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, In_As_SingleWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "entered port attribute"        EOL
            "entered alias"                 EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias"                  EOL
            "exited port attribute"         EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, In_As_MultiWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as first input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "entered port attribute"        EOL
            "entered alias"                 EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias"                  EOL
            "exited port attribute"         EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, Param)
    {
        YWParserBuilder parser_builder("@param p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, Out)
    {
        YWParserBuilder parser_builder("@out p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered output port keyword"   EOL
            "exited output port keyword"    EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, In_WithTwoPortsNamed)
    {
        YWParserBuilder parser_builder("@in p q");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "exited io"						EOL
            , listener.log());
    }

    YW_TEST(IoListener, In_WithTwoPortsNamed_FirstWithOneWordAlias)
    {
        YWParserBuilder parser_builder("@in p q @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->io());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered io"					EOL
            "entered port"                  EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"                   EOL
            "entered port attribute"        EOL
            "entered alias"                 EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias"                  EOL
            "exited port attribute"         EOL
            "exited io"					EOL
            , listener.log());
    }

YW_TEST_END