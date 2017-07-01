#include "yw_parse_tests.h"

using namespace yw::test;

namespace yw {
    namespace parse {

        TEST_CLASS(PortTagContextTests)
        {
        public:

            TEST_METHOD(TestPortTagContext_In)
            {
                YWParserBuilder parser_builder("@in");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(0, context->portName().size());
            }

            TEST_METHOD(TestPortTagContext_In_TwoPortNamesOneWordAlias)
            {
                YWParserBuilder parser_builder("@in p q @as data_name");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(2, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual("q", context->portName()[1]->getText());
                Assert::AreEqual(1, context->portAttribute().size());
                Assert::AreEqual("data_name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
            }

            TEST_METHOD(TestPortTagContext_In_OnePortNameTwoWordAlias)
            {
                YWParserBuilder parser_builder("@in p @as data name");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(1, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual(1, context->portAttribute().size());
                Assert::AreEqual("data name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
                Assert::IsNull(context->portAttribute()[0]->descTag());
                Assert::IsNull(context->portAttribute()[0]->resourceTag());
            }

            TEST_METHOD(TestPortTagContext_In_OnePortWithDescription)
            {
                YWParserBuilder parser_builder("@in p @desc with this description");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(1, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual(1, context->portAttribute().size());
                Assert::AreEqual("with this description", context->portAttribute()[0]->descTag()->description()->getText());
            }

            TEST_METHOD(TestPortTagContext_In_OnePortWithDescriptionThenAlias)
            {
                YWParserBuilder parser_builder("@in p @desc with this description @as data name");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(1, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual(2, context->portAttribute().size());
                Assert::AreEqual("with this description", context->portAttribute()[0]->descTag()->description()->getText());
                Assert::AreEqual("data name", context->portAttribute()[1]->aliasTag()->dataName()->getText());
            }

            TEST_METHOD(TestPortTagContext_In_ThreePortsWithAliasThenDescription)
            {
                YWParserBuilder parser_builder("@in p q r @as data name @desc with this description");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(3, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual("q", context->portName()[1]->getText());
                Assert::AreEqual("r", context->portName()[2]->getText());
                Assert::AreEqual(2, context->portAttribute().size());
                Assert::AreEqual("data name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
                Assert::AreEqual("with this description", context->portAttribute()[1]->descTag()->description()->getText());
            }


            TEST_METHOD(TestPortTagContext_In_ThreePortsWithAliasThenDescriptionOnNextLine)
            {
                YWParserBuilder parser_builder(
                    "@in p q r @as data name"               "\n"
                    "          @desc with this description" "\n");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(3, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual("q", context->portName()[1]->getText());
                Assert::AreEqual("r", context->portName()[2]->getText());
                Assert::AreEqual(2, context->portAttribute().size());
                Assert::AreEqual("data name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
                Assert::AreEqual("with this description", context->portAttribute()[1]->descTag()->description()->getText());
            }

            TEST_METHOD(TestPortTagContext_In_ThreePortsWithAliasThenDescriptionOnNextTwoLines)
            {
                YWParserBuilder parser_builder(
                    "@in p q r"                       "\n"
                    "    @as data name"               "\n"
                    "    @desc with this description" "\n");
                YWParser::PortTagContext* context = parser_builder.parse()->portTag();
                Assert::AreEqual("@in", context->inputPortKeyword()->getText());
                Assert::IsNull(context->outputPortKeyword());
                Assert::AreEqual(3, context->portName().size());
                Assert::AreEqual("p", context->portName()[0]->getText());
                Assert::AreEqual("q", context->portName()[1]->getText());
                Assert::AreEqual("r", context->portName()[2]->getText());
                Assert::AreEqual(2, context->portAttribute().size());
                Assert::AreEqual("data name", context->portAttribute()[0]->aliasTag()->dataName()->getText());
                Assert::AreEqual("with this description", context->portAttribute()[1]->descTag()->description()->getText());
            }
        };
    }
}