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
            Assert::AreEqual((size_t)0, context->portName().size());
        }

        TEST_METHOD(TestPortContext_In_TwoPortNamesOneWordAlias)
        {
            YWParserBuilder parser_builder("@in p q @as data_name");
            YWParser::PortContext* context = parser_builder.parser()->port();
            YW::Assert::AreEqual("@in", context->inputPortKeyword()->getText());
            Assert::IsNull(context->outputPortKeyword());
            Assert::AreEqual((size_t)2, context->portName().size());
            YW::Assert::AreEqual("p", context->portName()[0]->getText());
            YW::Assert::AreEqual("q", context->portName()[1]->getText());
            Assert::AreEqual((size_t)1, context->portAttribute().size());
            YW::Assert::AreEqual("data_name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
        }

        TEST_METHOD(TestPortContext_In_OnePortNameTwoWordAlias)
        {
            YWParserBuilder parser_builder("@in p @as data name");
            YWParser::PortContext* context = parser_builder.parser()->port();
            YW::Assert::AreEqual("@in", context->inputPortKeyword()->getText());
            Assert::IsNull(context->outputPortKeyword());
            Assert::AreEqual((size_t)1, context->portName().size());
            YW::Assert::AreEqual("p", context->portName()[0]->getText());
            Assert::AreEqual((size_t)1, context->portAttribute().size());
            YW::Assert::AreEqual("data name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
        }

    };
}