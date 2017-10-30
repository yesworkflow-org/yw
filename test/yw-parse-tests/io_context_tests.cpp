#include "yw_parse_tests.h"

using namespace yw;
using namespace yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(IoContext)

    StderrRecorder stderrRecorder;

YW_TEST_SET

    YW_TEST(IoContext, In)
    {
        YWParserBuilder parser_builder("@in");
        YWParser::IoContext* io;
        try {
            io = parser_builder.parse()->io();
        }
        catch (yw::parse::ParsingException e) {
            Expect::AreEqual("A problem occurred parsing YW annotations.", e.getMessage());
        }
        
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(0, io->port()->portName().size());
    }

    YW_TEST(IoContext, In_TwoPortNamesOneWordAlias)
    {
        YWParserBuilder parser_builder("@in p q @as data_name");
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(2, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual("q", io->port()->portName()[1]->getText());
        Assert::AreEqual(1, io->portAttribute().size());
        Assert::AreEqual("data_name", io->portAttribute()[0]->alias()->dataName()->getText());
    }

    YW_TEST(IoContext, In_OnePortNameTwoWordAlias)
    {
        YWParserBuilder parser_builder("@in p @as data name");
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(1, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual(1, io->portAttribute().size());
        Assert::AreEqual("data name", io->portAttribute()[0]->alias()->dataName()->getText());
        Assert::IsNull(io->portAttribute()[0]->portDesc());
        Assert::IsNull(io->portAttribute()[0]->resource());
    }

    YW_TEST(IoContext, In_OnePortWithDescription)
    {
        YWParserBuilder parser_builder("@in p @desc with this description");
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(1, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual(1, io->portAttribute().size());
        Assert::AreEqual("with this description", io->portAttribute()[0]->portDesc()->description()->getText());
    }

    YW_TEST(IoContext, In_OnePortWithDescriptionThenAlias)
    {
        YWParserBuilder parser_builder("@in p @desc with this description @as data name");
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(1, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual(2, io->portAttribute().size());
        Assert::AreEqual("with this description", io->portAttribute()[0]->portDesc()->description()->getText());
        Assert::AreEqual("data name", io->portAttribute()[1]->alias()->dataName()->getText());
    }

    YW_TEST(IoContext, In_ThreePortsWithAliasThenDescription)
    {
        YWParserBuilder parser_builder("@in p q r @as data name @desc with this description");
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(3, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual("q", io->port()->portName()[1]->getText());
        Assert::AreEqual("r", io->port()->portName()[2]->getText());
        Assert::AreEqual(2, io->portAttribute().size());
        Assert::AreEqual("data name", io->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", io->portAttribute()[1]->portDesc()->description()->getText());
    }

    YW_TEST(IoContext, In_ThreePortsWithAliasThenDescriptionOnNextLine)
    {
        YWParserBuilder parser_builder(
            "@in p q r @as data name"               EOL
            "          @desc with this description" EOL);
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(3, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual("q", io->port()->portName()[1]->getText());
        Assert::AreEqual("r", io->port()->portName()[2]->getText());
        Assert::AreEqual(2, io->portAttribute().size());
        Assert::AreEqual("data name", io->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", io->portAttribute()[1]->portDesc()->description()->getText());
    }

    YW_TEST(IoContext, In_ThreePortsWithAliasThenDescriptionOnNextTwoLines)
    {
        YWParserBuilder parser_builder(
            "@in p q r"                       EOL
            "    @as data name"               EOL
            "    @desc with this description" EOL);
        YWParser::IoContext* io = parser_builder.parse()->io();
        Expect::EmptyString(stderrRecorder.str());
        Assert::AreEqual("@in", io->port()->inputKeyword()->getText());
        Assert::IsNull(io->port()->outputKeyword());
        Assert::AreEqual(3, io->port()->portName().size());
        Assert::AreEqual("p", io->port()->portName()[0]->getText());
        Assert::AreEqual("q", io->port()->portName()[1]->getText());
        Assert::AreEqual("r", io->port()->portName()[2]->getText());
        Assert::AreEqual(2, io->portAttribute().size());
        Assert::AreEqual("data name", io->portAttribute()[0]->alias()->dataName()->getText());
        Assert::AreEqual("with this description", io->portAttribute()[1]->portDesc()->description()->getText());
    }

YW_TEST_END