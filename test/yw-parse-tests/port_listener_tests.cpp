#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(PortListener)

	StubYWListener listener;
	StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(PortListener, In)
    {
        YWParserBuilder parser_builder("@in p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, In_Desc)
    {
        YWParserBuilder parser_builder("@in p @desc a single input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port attribute"        EOL
            "entered desc tag"              EOL
            "entered description"           EOL
            "exited description"            EOL
            "exited desc tag"               EOL
            "exited port attribute"         EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, In_As_SingleWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port attribute"        EOL
            "entered alias tag"             EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias tag"              EOL
            "exited port attribute"         EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, In_As_MultiWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as first input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port attribute"        EOL
            "entered alias tag"             EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias tag"              EOL
            "exited port attribute"         EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, Param)
    {
        YWParserBuilder parser_builder("@param p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, Out)
    {
        YWParserBuilder parser_builder("@out p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered output port keyword"   EOL
            "exited output port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, Return)
    {
        YWParserBuilder parser_builder("@return p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered output port keyword"   EOL
            "exited output port keyword"    EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, In_WithTwoPortsNamed)
    {
        YWParserBuilder parser_builder("@in p q");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port tag"               EOL
        , listener.log());
    }

    YW_TEST(PortListener, In_WithTwoPortsNamed_FirstWithOneWordAlias)
    {
        YWParserBuilder parser_builder("@in p q @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "entered port attribute"        EOL
            "entered alias tag"             EOL
            "entered data name"             EOL
            "exited data name"              EOL
            "exited alias tag"              EOL
            "exited port attribute"         EOL
            "exited port tag"               EOL
        , listener.log());
    }

YW_TEST_END