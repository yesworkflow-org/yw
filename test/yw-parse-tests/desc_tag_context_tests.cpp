#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(DescTagContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(DescTagContext, NoDescription)
    {
        YWParserBuilder parser_builder("@desc");
        YWParser::DescTagContext* context = parser_builder.parse()->descTag();
		Expect::AreEqual("line 1:5 mismatched input '<EOF>' expecting SPACE" "\n", stderrRecorder.str());
        Assert::IsNull(context->description());
    }

    YW_TEST(DescTagContext, OneWordDescription)
    {
        YWParserBuilder parser_builder("@desc word");
        YWParser::DescTagContext* context = parser_builder.parse()->descTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("word", context->description()->getText());
    }

    YW_TEST(DescTagContext, MultiWordDescription)
    {
        YWParserBuilder parser_builder("@desc a multiple word description");
        YWParser::DescTagContext* context = parser_builder.parse()->descTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

    YW_TEST(DescTagContext, MultiWordDescription_IgnoresTextOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@desc a multiple word description"  "\n"
            "with more text on next line"        "\n");
        YWParser::DescTagContext* context = parser_builder.parse()->descTag();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

YW_TEST_END