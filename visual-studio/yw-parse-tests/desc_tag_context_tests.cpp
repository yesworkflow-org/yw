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
    TEST_CLASS(DescTagContextTests)
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

        TEST_METHOD(TestDescTagContext_NoDescription)
        {
            YWParser* parser = parse("@desc");
            YWParser::DescTagContext* context = parser->descTag();
            Assert::IsNull(context->description());
        }

        TEST_METHOD(TestDescTagContext_OneWordDescription)
        {
            YWParser* parser = parse("@desc word");
            YWParser::DescTagContext* context = parser->descTag();
            AreEqual("word", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription)
        {
            YWParser* parser = parse("@desc a multiple word description");
            YWParser::DescTagContext* context = parser->descTag();
            AreEqual("a multiple word description", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription_IgnoresTextOnNextLine)
        {
            YWParser* parser = parse(
                "@desc a multiple word description"  "\n"
                "with more text on next line"        "\n" );
            YWParser::DescTagContext* context = parser->descTag();
            AreEqual("a multiple word description", context->description()->getText());
        }

    };
}