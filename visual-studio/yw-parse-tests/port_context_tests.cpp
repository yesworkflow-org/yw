#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace yw_parse_tests
{
    TEST_CLASS(PortContextTests)
    {
    public:

        TEST_METHOD(TestPortContext_In)
        {
            YWParserBuilder parser_builder("@in");
            YWParser::PortContext* context = parser_builder.parser()->port();
            YW::Assert::AreEqual("@in", context->inputPortKeyword()->getText());
            Assert::IsNull(context->outputPortKeyword());

        }

    };
}