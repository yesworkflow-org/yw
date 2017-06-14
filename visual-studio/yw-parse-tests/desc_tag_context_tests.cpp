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
    TEST_CLASS(DescTagContextTests)
    {
    public:

        TEST_METHOD(TestDescTagContext_NoDescription)
        {
            ParserBuilder parserBuilder("@desc");
            YWParser::DescTagContext* context = parserBuilder.parser()->descTag();
            Assert::IsNull(context->description());
        }

        TEST_METHOD(TestDescTagContext_OneWordDescription)
        {
            ParserBuilder parserBuilder("@desc word");
            YWParser::DescTagContext* context = parserBuilder.parser()->descTag();
            YW::Assert::AreEqual("word", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription)
        {
            ParserBuilder parserBuilder("@desc a multiple word description");
            YWParser::DescTagContext* context = parserBuilder.parser()->descTag();
            YW::Assert::AreEqual("a multiple word description", context->description()->getText());
        }

        TEST_METHOD(TestDescTagContext_MultiWordDescription_IgnoresTextOnNextLine)
        {
            ParserBuilder parserBuilder(
                "@desc a multiple word description"  "\n"
                "with more text on next line"        "\n" );
            YWParser::DescTagContext* context = parserBuilder.parser()->descTag();
            YW::Assert::AreEqual("a multiple word description", context->description()->getText());
        }

    };
}