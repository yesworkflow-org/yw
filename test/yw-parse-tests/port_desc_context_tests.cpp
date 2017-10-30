#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(PortDescContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(PortDescContext, NoDescription)
    {
        YWParserBuilder parser_builder("@desc");
        YWParser::PortDescContext* context = parser_builder.parse()->portDesc();
        Expect::AreEqual("line 1:5 mismatched input '<EOF>' expecting SPACE" EOL, stderrRecorder.str());
        Assert::IsNull(context->description());
    }

    YW_TEST(PortDescContext, OneWordDescription)
    {
        YWParserBuilder parser_builder("@desc word");
        YWParser::PortDescContext* context = parser_builder.parse()->portDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("word", context->description()->getText());
    }

    YW_TEST(PortDescContext, MultiWordDescription)
    {
        YWParserBuilder parser_builder("@desc a multiple word description");
        YWParser::PortDescContext* context = parser_builder.parse()->portDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

    YW_TEST(PortDescContext, MultiWordDescription_IgnoresTextOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@desc a multiple word description"  EOL
            "with more text on next line"        EOL);
        YWParser::PortDescContext* context = parser_builder.parse()->portDesc();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("a multiple word description", context->description()->getText());
    }

YW_TEST_END