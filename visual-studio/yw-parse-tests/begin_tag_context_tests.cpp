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
    TEST_CLASS(BeginTagContextTests)
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

        TEST_METHOD(TestBeginTagContext_NoName)
        {
            YWParser* parser = parse("@begin");
            YWParser::BeginTagContext* context = parser->beginTag();
            Assert::IsNull(context->blockName());
        }

        TEST_METHOD(TestBeginTagContext_NameOnNextLineNotFound)
        {
            YWParser* parser = parse(
                "@begin "   "\n"
                "block"     "\n" );
            YWParser::BeginTagContext* context = parser->beginTag();
            Assert::IsNull(context->blockName());
        }

        TEST_METHOD(TestBeginTagContext_NameWithoutSpaces)
        {
            YWParser* parser = parse("@begin block");
            YWParser::BeginTagContext* context = parser->beginTag();
            AreEqual("block", context->blockName()->getText());
        }

        TEST_METHOD(TestBeginTagContext_NameWithSpaces)
        {
            YWParser* parser = parse("@begin b l o c k");
            YWParser::BeginTagContext* context = parser->beginTag();
            AreEqual("b l o c k", context->blockName()->getText());
        }

        TEST_METHOD(TestBeginTagContext_NameWithSpacesTerminatedByNewline)
        {
            YWParser* parser = parse(
                "@begin b l o "  "\n"
                "c k"           "\n" );
            YWParser::BeginTagContext* context = parser->beginTag();
            AreEqual("b l o", context->blockName()->getText());
        }

        TEST_METHOD(TestBeginTagContext_BlockNameOnNextLineIsNotFound)
        {
            YWParser* parser = parse(
                "@begin"    "\n"
                "b"         "\n");
            YWParser::BeginTagContext* context = parser->beginTag();
 
            AreEqual("@begin", context->BeginKeyword()->getText());
            Assert::IsNull(context->blockName());
        }
    };
}