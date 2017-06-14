#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"
#include "ParserBuilder.h"
#include "test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;

namespace yw_parse_tests
{
    TEST_CLASS(BlockContextTests)
    {
    public:

        TEST_METHOD(TestBlockContext_Begin_End)
        {
            ParserBuilder parserBuilder("@begin b @end b");
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual("@begin b @end b", context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            YW::Assert::AreEqual("b", context->endTag()->blockName()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());

            Assert::AreEqual((size_t)0, context->blockAttribute().size());
            Assert::AreEqual((size_t)0, context->block().size());
        }

        TEST_METHOD(TestBlockContext_Begin_End_TagsOnDifferentLines)
        {
            ParserBuilder parserBuilder(
                "@begin b"  "\n"
                "@end b"    "\n"
            );
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual(
                "@begin b"  "\n"
                "@end b"
                , context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            YW::Assert::AreEqual("b", context->endTag()->blockName()->getText());

            Assert::AreEqual((size_t)0, context->blockAttribute().size());
            Assert::AreEqual((size_t)0, context->block().size());
        }

        TEST_METHOD(TestBlockContext_Begin_End_WithNoFinalBlockName)
        {
            ParserBuilder parserBuilder("@begin b @end");
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual("@begin b @end", context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)0, context->blockAttribute().size());
            Assert::AreEqual((size_t)0, context->block().size());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            Assert::IsNull(context->endTag()->blockName());
        }

        TEST_METHOD(TestBlockContext_Begin_Desc_End_OneWordDescription)
        {
            ParserBuilder parserBuilder("@begin b @desc word @end");
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual("@begin b @desc word @end", context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)1, context->blockAttribute().size());
            YW::Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
            YW::Assert::AreEqual("word", context->blockAttribute()[0]->descTag()->description()->getText());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            Assert::AreEqual((size_t)0, context->block().size());
            Assert::IsNull(context->endTag()->blockName());
        }

        TEST_METHOD(TestBlockContext_Begin_Desc_End_MultipleWordDescriptionOnSameLine)
        {
            ParserBuilder parserBuilder("@begin b @desc a multiple word description @end");
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual("@begin b @desc a multiple word description @end", context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)1, context->blockAttribute().size());
            YW::Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
            YW::Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->descTag()->description()->getText());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            Assert::AreEqual((size_t)0, context->block().size());
            Assert::IsNull(context->endTag()->blockName());
        }


        TEST_METHOD(TestBlockContext_Begin_Desc_End_MultipleWordDescriptionOnNextLine)
        {
            ParserBuilder parserBuilder("@begin b\n@desc a multiple word description @end");
            YWParser::BlockContext* context = parserBuilder.parser()->block();

            YW::Assert::AreEqual("@begin b\n@desc a multiple word description @end", context->getText());
            YW::Assert::AreEqual("@begin", context->beginTag()->BeginKeyword()->getText());
            YW::Assert::AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)1, context->blockAttribute().size());
            YW::Assert::AreEqual("@desc", context->blockAttribute()[0]->descTag()->DescKeyword()->getText());
            YW::Assert::AreEqual("a multiple word description", context->blockAttribute()[0]->descTag()->description()->getText());
            YW::Assert::AreEqual("@end", context->endTag()->EndKeyword()->getText());
            Assert::AreEqual((size_t)0, context->block().size());
            Assert::IsNull(context->endTag()->blockName());
        }

    };
}