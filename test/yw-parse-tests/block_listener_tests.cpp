#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BlockListener)

    StubYWListener listener;
    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(BlockListener, Begin_In_End)
    {
        YWParserBuilder parser_builder("@begin b @in p @end");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->block());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered block"                 EOL
            "entered begin"					EOL
            "entered block name"            EOL
            "exited block name"             EOL
            "exited begin"					EOL
            "entered block attribute"       EOL
            "entered io"					EOL
            "entered port"					EOL
            "entered input port keyword"    EOL
            "exited input port keyword"     EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"					EOL
            "exited io"						EOL
            "exited block attribute"        EOL
            "entered end"					EOL
            "exited end"					EOL
            "exited block"                  EOL
            , listener.log());
    }

    YW_TEST(BlockListener, Begin_Out_End)
    {
        YWParserBuilder parser_builder("@begin b @out p @end");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->block());
        Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered block"                 EOL
            "entered begin"					EOL
            "entered block name"            EOL
            "exited block name"             EOL
            "exited begin"					EOL
            "entered block attribute"       EOL
            "entered io"					EOL
            "entered port"					EOL
            "entered output port keyword"   EOL
            "exited output port keyword"    EOL
            "entered port name"             EOL
            "exited port name"              EOL
            "exited port"					EOL
            "exited io"						EOL
            "exited block attribute"        EOL
            "entered end"					EOL
            "exited end"					EOL
            "exited block"                  EOL
            , listener.log());
    }

YW_TEST_END