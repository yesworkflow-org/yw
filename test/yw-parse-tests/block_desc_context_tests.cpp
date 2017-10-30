#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BlockDescContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(BlockDescContext, NoDescription)
    {
        YWParserBuilder parser_builder("@desc");
        YWParser::BlockDescContext* context = parser_builder.parse()->blockDesc();
        Expect::AreEqual("line 1:5 mismatched input '<EOF>' expecting SPACE" EOL, stderrRecorder.str());
        Assert::IsNull(context->description());
    }

    YW_TEST(BlockDescContext, OneWordDescription)
    {
        YWParserBuilder parser_builder("@desc word");
        YWParser::BlockDescContext* context = parser_builder.parse()->blockDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("word", context->description()->getText());
    }

    YW_TEST(BlockDescContext, MultiWordDescription)
    {
        YWParserBuilder parser_builder("@desc a multiple word description");
        YWParser::BlockDescContext* context = parser_builder.parse()->blockDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

    YW_TEST(BlockDescContext, MultiWordDescription_IgnoresTextOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@desc a multiple word description"  EOL
            "with more text on next line"        EOL);
        YWParser::BlockDescContext* context = parser_builder.parse()->blockDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

YW_TEST_END