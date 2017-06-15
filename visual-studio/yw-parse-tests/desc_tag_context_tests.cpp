#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"
#include "yw_parser_builder.h"
#include "test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;

namespace yw_parse_tests
{
    TEST_CLASS(DescTagContextTests)
    {
    public:

        TEST_METHOD(TestDescTagContext_NoDescription)
        {
            YWParserBuilder parser_builder("@desc");
            YWParser::DescTagContext* context = parser_builder.parser()->descTag();
            Assert::IsNull(context->description());
        }

        TEST_METHOD(TestDescTagContext_OneWordDescription)
        {
            YWParserBuilder parser_builder("@desc word");
            YWParser::DescTagContext* context = parser_builder.parser()->descTag();
            YW::Assert::AreEqual("word", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription)
        {
            YWParserBuilder parser_builder("@desc a multiple word description");
            YWParser::DescTagContext* context = parser_builder.parser()->descTag();
            YW::Assert::AreEqual("a multiple word description", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription_IgnoresTextOnNextLine)
        {
            YWParserBuilder parser_builder(
                "@desc a multiple word description"  "\n"
                "with more text on next line"        "\n" );
            YWParser::DescTagContext* context = parser_builder.parser()->descTag();
            YW::Assert::AreEqual("a multiple word description", context->description()->getText());
        }

    };
}