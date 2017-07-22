#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(DescContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(DescContext, NoDescription)
    {
        YWParserBuilder parser_builder("@desc");
        YWParser::DescContext* context = parser_builder.parse()->desc();
		Expect::AreEqual("line 1:5 mismatched input '<EOF>' expecting SPACE" EOL, stderrRecorder.str());
        Assert::IsNull(context->description());
    }

    YW_TEST(DescContext, OneWordDescription)
    {
        YWParserBuilder parser_builder("@desc word");
        YWParser::DescContext* context = parser_builder.parse()->desc();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("word", context->description()->getText());
    }

    YW_TEST(DescContext, MultiWordDescription)
    {
        YWParserBuilder parser_builder("@desc a multiple word description");
        YWParser::DescContext* context = parser_builder.parse()->desc();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

    YW_TEST(DescContext, MultiWordDescription_IgnoresTextOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@desc a multiple word description"  EOL
            "with more text on next line"        EOL);
        YWParser::DescContext* context = parser_builder.parse()->desc();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

YW_TEST_END