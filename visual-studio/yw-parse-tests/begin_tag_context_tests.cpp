#include "stdafx.h"

using namespace yw::test;

namespace yw {
    namespace parse {

        TEST_CLASS(BeginTagContextTests)
        {
        public:

            TEST_METHOD(TestBeginTagContext_NoName)
            {
                YWParserBuilder parser_builder("@begin");
                YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
                Assert::IsNull(context->blockName());
            }

            TEST_METHOD(TestBeginTagContext_NameWithoutSpaces)
            {
                YWParserBuilder parser_builder("@begin block");
                YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
                Assert::AreEqual("block", context->blockName()->getText());
            }

            TEST_METHOD(TestBeginTagContext_NameWithSpaces)
            {
                YWParserBuilder parser_builder("@begin b l o c k");
                YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
                Assert::AreEqual("b l o c k", context->blockName()->getText());
            }

            TEST_METHOD(TestBeginTagContext_NameWithSpacesTerminatedByNewline)
            {
                YWParserBuilder parser_builder(
                    "@begin b l o "  "\n"
                    "c k"           "\n");
                YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();
                Assert::AreEqual("b l o", context->blockName()->getText());
            }

            TEST_METHOD(TestBeginTagContext_BlockNameOnNextLineIsNotFound)
            {
                YWParserBuilder parser_builder(
                    "@begin"    "\n"
                    "b"         "\n");
                YWParser::BeginTagContext* context = parser_builder.parse()->beginTag();

                Assert::AreEqual("@begin", context->BeginKeyword()->getText());
                Assert::IsNull(context->blockName());
            }
        };
    }
}