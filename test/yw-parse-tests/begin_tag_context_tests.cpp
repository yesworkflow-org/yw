#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BeginTagContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(BeginTagContext, BeginTagWithNoArgumentYieldsNullBlockName)
    {
        YWParserBuilder parser_builder("@begin");
        YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
        Expect::AreEqual("line 1:6 mismatched input '<EOF>' expecting SPACE" "\n", stderrRecorder.str());
        Assert::IsNull(context->blockName());
    }

    YW_TEST(BeginTagContext, BeginTagWithSingleArgumentOnSameLineYieldsArgumentAsBlockName)
    {
        YWParserBuilder parser_builder("@begin block");
        YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("block", context->blockName()->getText());
    }

    YW_TEST(BeginTagContext, BeginTagWithMultipleArgumentsOnSameLineYieldsArgumentsAsBlockName)
    {
        YWParserBuilder parser_builder("@begin b l o c k");
        YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("b l o c k", context->blockName()->getText());
    }

    YW_TEST(BeginTagContext, BeginTagWithMultipleArgumentsOnTwoLinesYieldsArgumentsOnFirstLineAsBlockName)
    {
        YWParserBuilder parser_builder(
            "@begin b l o "  "\n"
            "c k"           "\n");
        YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("b l o", context->blockName()->getText());
    }

    YW_TEST(BeginTagContext, BeginTagWithArgumentOnNextLineYieldsNullBlockName)
    {
        YWParserBuilder parser_builder(
            "@begin"    "\n"
            "b"         "\n");
        YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
		Expect::AreEqual("line 1:6 mismatched input '\\n' expecting SPACE" "\n", stderrRecorder.str());
        Assert::AreEqual("@begin", context->BeginKeyword()->getText());
        Assert::IsNull(context->blockName());
    }

YW_TEST_END
