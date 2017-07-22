#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(ScriptListener)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(ScriptListener, Begin_End_WithFinalBlockName)
    {
        StubYWListener listener;
        YWParserBuilder parser_builder("@begin b @end b");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered script"        EOL
            "entered block"         EOL
            "entered begin tag"     EOL
            "entered block name"    EOL
            "exited block name"     EOL
            "exited begin tag"      EOL
            "entered end tag"       EOL
            "entered block name"    EOL
            "exited block name"     EOL
            "exited end tag"        EOL
            "exited block"          EOL
            "exited script"         EOL
        , listener.log());
    }

    YW_TEST(ScriptListener, Begin_End_NoFinalBlockName)
    {
        StubYWListener listener;
        YWParserBuilder parser_builder("@begin b @end");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered script"        EOL
            "entered block"         EOL
            "entered begin tag"     EOL
            "entered block name"    EOL
            "exited block name"     EOL
            "exited begin tag"      EOL
            "entered end tag"       EOL
            "exited end tag"        EOL
            "exited block"          EOL
            "exited script"         EOL
        , listener.log());
    }

    YW_TEST(ScriptListener, Begin_Desc_End)
    {
        StubYWListener listener;
        YWParserBuilder parser_builder("@begin b @desc a simple block @end");
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "entered script"            EOL
            "entered block"             EOL
            "entered begin tag"         EOL
            "entered block name"        EOL
            "exited block name"         EOL
            "exited begin tag"          EOL
            "entered block attribute"   EOL
            "entered desc tag"          EOL
            "entered description"       EOL
            "exited description"        EOL
            "exited desc tag"           EOL
            "exited block attribute"    EOL
            "entered end tag"           EOL
            "exited end tag"            EOL
            "exited block"              EOL
            "exited script"             EOL
        , listener.log());
    }

YW_TEST_END