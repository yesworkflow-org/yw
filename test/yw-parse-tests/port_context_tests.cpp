#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(PortContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(PortContext, In)
    {
        YWParserBuilder parser_builder("@in");
        YWParser::PortContext* context = parser_builder.parse()->port();
        Expect::AreEqual("line 1:3 mismatched input '<EOF>' expecting SPACE" "\n", stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(0, context->portName().size());
    }

    YW_TEST(PortContext, In_TwoPortNamesOneWordAlias)
    {
        YWParserBuilder parser_builder("@in p q @as data_name");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(2, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual("q", context->portName()[1]->getText());
        Assert::AreEqual(1, context->portAttribute().size());
        Assert::AreEqual("data_name", context->portAttribute()[0]->alias()->dataName()->getText());
    }

    YW_TEST(PortContext, In_OnePortNameTwoWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as data name");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(1, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual(1, context->portAttribute().size());
        Assert::AreEqual("data name", context->portAttribute()[0]->alias()->dataName()->getText());
        Assert::IsNull(context->portAttribute()[0]->desc());
        Assert::IsNull(context->portAttribute()[0]->resource());
    }

    YW_TEST(PortContext, In_OnePortWithDescription)
    {
        YWParserBuilder parser_builder("@in p @desc with this description");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(1, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual(1, context->portAttribute().size());
        Assert::AreEqual("with this description", context->portAttribute()[0]->desc()->description()->getText());
    }

    YW_TEST(PortContext, In_OnePortWithDescriptionThenAlias)
    {
        YWParserBuilder parser_builder("@in p @desc with this description @as data name");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(1, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual(2, context->portAttribute().size());
        Assert::AreEqual("with this description", context->portAttribute()[0]->desc()->description()->getText());
        Assert::AreEqual("data name", context->portAttribute()[1]->alias()->dataName()->getText());
    }

    YW_TEST(PortContext, In_ThreePortsWithAliasThenDescription)
    {
        YWParserBuilder parser_builder("@in p q r @as data name @desc with this description");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(3, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual("q", context->portName()[1]->getText());
        Assert::AreEqual("r", context->portName()[2]->getText());
        Assert::AreEqual(2, context->portAttribute().size());
        Assert::AreEqual("data name", context->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", context->portAttribute()[1]->desc()->description()->getText());
    }

    YW_TEST(PortContext, In_ThreePortsWithAliasThenDescriptionOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@in p q r @as data name"               "\n"
            "          @desc with this description" "\n");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(3, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual("q", context->portName()[1]->getText());
        Assert::AreEqual("r", context->portName()[2]->getText());
        Assert::AreEqual(2, context->portAttribute().size());
        Assert::AreEqual("data name", context->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", context->portAttribute()[1]->desc()->description()->getText());
    }

    YW_TEST(PortContext, In_ThreePortsWithAliasThenDescriptionOnNextTwoLines)
    {
        YWParserBuilder parser_builder(
            "@in p q r"                       "\n"
            "    @as data name"               "\n"
            "    @desc with this description" "\n");
        YWParser::PortContext* context = parser_builder.parse()->port();
		Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", context->inputKeyword()->getText());
        Assert::IsNull(context->outputKeyword());
        Assert::AreEqual(3, context->portName().size());
        Assert::AreEqual("p", context->portName()[0]->getText());
        Assert::AreEqual("q", context->portName()[1]->getText());
        Assert::AreEqual("r", context->portName()[2]->getText());
        Assert::AreEqual(2, context->portAttribute().size());
        Assert::AreEqual("data name", context->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", context->portAttribute()[1]->desc()->description()->getText());
    }

YW_TEST_END