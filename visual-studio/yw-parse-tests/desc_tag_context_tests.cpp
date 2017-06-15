#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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