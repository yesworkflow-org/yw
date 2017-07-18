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
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, In_Desc)
    {
        YWParserBuilder parser_builder("@in p @desc a single input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port attribute"        "\n"
            "entered desc tag"              "\n"
            "entered description"           "\n"
            "exited description"            "\n"
            "exited desc tag"               "\n"
            "exited port attribute"         "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, In_As_SingleWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port attribute"        "\n"
            "entered alias tag"             "\n"
            "entered data name"             "\n"
            "exited data name"              "\n"
            "exited alias tag"              "\n"
            "exited port attribute"         "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, In_As_MultiWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as first input port");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port attribute"        "\n"
            "entered alias tag"             "\n"
            "entered data name"             "\n"
            "exited data name"              "\n"
            "exited alias tag"              "\n"
            "exited port attribute"         "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, Param)
    {
        YWParserBuilder parser_builder("@param p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, Out)
    {
        YWParserBuilder parser_builder("@out p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered output port keyword"   "\n"
            "exited output port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, Return)
    {
        YWParserBuilder parser_builder("@return p");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered output port keyword"   "\n"
            "exited output port keyword"    "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, In_WithTwoPortsNamed)
    {
        YWParserBuilder parser_builder("@in p q");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

    YW_TEST(PortListener, In_WithTwoPortsNamed_FirstWithOneWordAlias)
    {
        YWParserBuilder parser_builder("@in p q @as d");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->port());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered port tag"              "\n"
            "entered input port keyword"    "\n"
            "exited input port keyword"     "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port name"             "\n"
            "exited port name"              "\n"
            "entered port attribute"        "\n"
            "entered alias tag"             "\n"
            "entered data name"             "\n"
            "exited data name"              "\n"
            "exited alias tag"              "\n"
            "exited port attribute"         "\n"
            "exited port tag"               "\n"
        , listener.log());
    }

YW_TEST_END