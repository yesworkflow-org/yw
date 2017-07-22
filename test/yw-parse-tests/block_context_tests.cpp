#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BlockContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(BlockContext, Begin_End)
    {
        YWParserBuilder parser_builder("@begin b @end b");
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual("@begin b @end b", context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::AreEqual("b", context->end()->blockName()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());

        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
    }

    YW_TEST(BlockContext, Begin_End_sOnDifferentLines)
    {
        YWParserBuilder parser_builder(
            "@begin b"  EOL
            "@end b"    EOL
        );
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual(
            "@begin b"  EOL
            "@end b"
            , context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::AreEqual("b", context->end()->blockName()->getText());

        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
    }

    YW_TEST(BlockContext, NameOnNextLineNotFound)
    {
        YWParserBuilder parser_builder(
            "@begin"    EOL
            "block"     EOL);
        YWParser::BlockContext* blockContext = parser_builder.parse()->block();
		Expect::AreEqual("line 1:6 mismatched input '\\n' expecting SPACE" EOL, stderrRecorder.str());

        Assert::AreEqual("@begin", blockContext->begin()->BeginKeyword()->getText());
        Assert::IsNull(blockContext->begin()->blockName());
    }

    YW_TEST(BlockContext, Begin_End_WithNoFinalBlockName)
    {
        YWParserBuilder parser_builder("@begin b @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual("@begin b @end", context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());
        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::IsNull(context->end()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_OneWordDescription)
    {
        YWParserBuilder parser_builder("@begin b @desc word @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual("@begin b @desc word @end", context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->desc()->DescKeyword()->getText());
        Assert::AreEqual("word", context->blockAttribute()[0]->desc()->description()->getText());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->end()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_MultipleWordDescriptionOnSameLine)
    {
        YWParserBuilder parser_builder("@begin b @desc a multiple word description @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual("@begin b @desc a multiple word description @end", context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->desc()->DescKeyword()->getText());
        Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->desc()->description()->getText());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->end()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_MultipleWordDescriptionOnNextLine)
    {
        YWParserBuilder parser_builder("@begin b\n@desc a multiple word description @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();
		Expect::EmptyString(stderrRecorder.str());

        Assert::AreEqual("@begin b\n@desc a multiple word description @end", context->getText());
        Assert::AreEqual("@begin", context->begin()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->begin()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->desc()->DescKeyword()->getText());
        Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->desc()->description()->getText());
        Assert::AreEqual("@end", context->end()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->end()->blockName());
    }

YW_TEST_END