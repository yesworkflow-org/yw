#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BlockContext)

YW_TEST_SET

    YW_TEST(BlockContext, Begin_End)
    {
        YWParserBuilder parser_builder("@begin b @end b");
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual("@begin b @end b", context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::AreEqual("b", context->endTag()->blockName()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());

        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
    }

    YW_TEST(BlockContext, Begin_End_TagsOnDifferentLines)
    {
        YWParserBuilder parser_builder(
            "@begin b"  "\n"
            "@end b"    "\n"
        );
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual(
            "@begin b"  "\n"
            "@end b"
            , context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::AreEqual("b", context->endTag()->blockName()->getText());

        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
    }

    YW_TEST(BlockContext, NameOnNextLineNotFound)
    {
        YWParserBuilder parser_builder(
            "@begin"    "\n"
            "block"     "\n");
        YWParser::BlockContext* blockContext = parser_builder.parse()->block();
        Assert::AreEqual("@begin", blockContext->beginTag()->BeginKeyword()->getText());
        Assert::IsNull(blockContext->beginTag()->blockName());
    }

    YW_TEST(BlockContext, Begin_End_WithNoFinalBlockName)
    {
        YWParserBuilder parser_builder("@begin b @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual("@begin b @end", context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());
        Assert::AreEqual(0, context->blockAttribute().size());
        Assert::AreEqual(0, context->block().size());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::IsNull(context->endTag()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_OneWordDescription)
    {
        YWParserBuilder parser_builder("@begin b @desc word @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual("@begin b @desc word @end", context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
        Assert::AreEqual("word", context->blockAttribute()[0]->descTag()->description()->getText());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->endTag()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_MultipleWordDescriptionOnSameLine)
    {
        YWParserBuilder parser_builder("@begin b @desc a multiple word description @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual("@begin b @desc a multiple word description @end", context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
        Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->descTag()->description()->getText());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->endTag()->blockName());
    }

    YW_TEST(BlockContext, Begin_Desc_End_MultipleWordDescriptionOnNextLine)
    {
        YWParserBuilder parser_builder("@begin b\n@desc a multiple word description @end");
        YWParser::BlockContext* context = parser_builder.parse()->block();

        Assert::AreEqual("@begin b\n@desc a multiple word description @end", context->getText());
        Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
        Assert::AreEqual("b", context->beginTag()->blockName()->getText());
        Assert::AreEqual(1, context->blockAttribute().size());
        Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
        Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->descTag()->description()->getText());
        Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
        Assert::AreEqual(0, context->block().size());
        Assert::IsNull(context->endTag()->blockName());
    }

YW_TEST_END