#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;


static void AreEqual(const char* expected, std::string actual, bool ignoreCase = false, const wchar_t* message = NULL, const __LineInfo* pLineInfo = NULL)
{
    Assert::AreEqual(expected, actual.c_str(), ignoreCase, message, pLineInfo);
}

namespace yw_parse_tests
{
    TEST_CLASS(ParserContextTests)
    {
        stringstream* textStream;
        antlr4::ANTLRInputStream* input;
        YWLexer* lexer;
        antlr4::CommonTokenStream* tokens;

        YWParser* parse(const char * text) {
            textStream = new stringstream(text);
            input = new antlr4::ANTLRInputStream(*textStream);
            lexer = new YWLexer(input);
            tokens = new antlr4::CommonTokenStream(lexer);
            return new YWParser(tokens);
        }

    public:

        TEST_METHOD(TestBlockContext_Begin_End_WithFinalBlockName)
        {
            YWParser* parser = parse("@begin b @end b");
            YWParser::BlockContext* context = parser->block();

            AreEqual("@begin b @end b", context->getText());
            AreEqual("@begin",          context->beginTag()->beginKeyword()->getText());
            AreEqual("b",               context->beginTag()->blockName()->getText());
            AreEqual("@end",            context->endTag()->endKeyword()->getText());
            AreEqual("b",               context->endTag()->blockName()->getText());

            Assert::AreEqual((size_t)0, context->blockAttribute().size());
            Assert::AreEqual((size_t)0, context->block().size());

        }

        TEST_METHOD(TestBlockContext_Begin_End_WithNoFinalBlockName)
        {
            YWParser* parser = parse("@begin b @end");
            YWParser::BlockContext* context = parser->block();

            AreEqual("@begin b @end", context->getText());
            AreEqual("@begin", context->beginTag()->beginKeyword()->getText());
            AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)0, context->blockAttribute().size());
            Assert::AreEqual((size_t)0, context->block().size());
            AreEqual("@end", context->endTag()->endKeyword()->getText());
            Assert::IsNull(context->endTag()->blockName());
        }

        TEST_METHOD(TestBlockContext_Begin_Desc_End)
        {
            YWParser* parser = parse("@begin b @desc one_token_description @end");
            YWParser::BlockContext* context = parser->block();

            AreEqual("@begin b @desc one_token_description @end", context->getText());
            AreEqual("@begin", context->beginTag()->beginKeyword()->getText());
            AreEqual("b", context->beginTag()->blockName()->getText());
            Assert::AreEqual((size_t)1, context->blockAttribute().size());
            AreEqual("@desc", context->blockAttribute()[0]->descTag()->descKeyword()->getText());
            AreEqual("one_token_description", context->blockAttribute()[0]->descTag()->description()->getText());
            AreEqual("@end", context->endTag()->endKeyword()->getText());
            Assert::AreEqual((size_t)0, context->block().size());
            Assert::IsNull(context->endTag()->blockName());
        }



    };
}