#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BeginContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(BeginContext, BeginWithNoArgumentYieldsNullBlockName)
    {
        YWParserBuilder parser_builder("@begin");
        YWParser::BeginContext* context = parser_builder.parse()->begin();
        Expect::AreEqual("line 1:6 mismatched input '<EOF>' expecting SPACE" "\n", stderrRecorder.str());
        Assert::IsNull(context->blockName());
    }

    YW_TEST(BeginContext, BeginWithSingleArgumentOnSameLineYieldsArgumentAsBlockName)
    {
        YWParserBuilder parser_builder("@begin block");
        YWParser::BeginContext* context = parser_builder.parse()->begin();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("block", context->blockName()->getText());
    }

    YW_TEST(BeginContext, BeginWithMultipleArgumentsOnSameLineYieldsArgumentsAsBlockName)
    {
        YWParserBuilder parser_builder("@begin b l o c k");
        YWParser::BeginContext* context = parser_builder.parse()->begin();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("b l o c k", context->blockName()->getText());
    }

    YW_TEST(BeginContext, BeginWithMultipleArgumentsOnTwoLinesYieldsArgumentsOnFirstLineAsBlockName)
    {
        YWParserBuilder parser_builder(
            "@begin b l o "  "\n"
            "c k"           "\n");
        YWParser::BeginContext* context = parser_builder.parse()->begin();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("b l o", context->blockName()->getText());
    }

    YW_TEST(BeginContext, BeginWithArgumentOnNextLineYieldsNullBlockName)
    {
        YWParserBuilder parser_builder(
            "@begin"    "\n"
            "b"         "\n");
        YWParser::BeginContext* context = parser_builder.parse()->begin();
		Expect::AreEqual("line 1:6 mismatched input '\\n' expecting SPACE" "\n", stderrRecorder.str());
        Assert::AreEqual("@begin", context->BeginKeyword()->getText());
        Assert::IsNull(context->blockName());
    }

YW_TEST_END
