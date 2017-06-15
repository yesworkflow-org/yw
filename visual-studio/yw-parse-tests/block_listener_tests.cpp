#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"
#include "listener_for_tests.h"
#include "yw_parser_builder.h"
#include "test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;

namespace yw_parse_tests
{
    TEST_CLASS(BlockListenerTests)
    {
        YWListenerForTests listener;

    public:

        TEST_METHOD(TestBlockListener_Begin_In_End)
        {
            YWParserBuilder parser_builder("@begin b @in p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->block());

            Assert::AreEqual(std::string(
                "entered block"                 "\n"
                "entered begin tag"             "\n"
                "entered block name"            "\n"
                "exited block name"             "\n"
                "exited begin tag"              "\n"
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
                "entered end tag"               "\n"
                "exited end tag"                "\n"
                "exited block"                  "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockListener_Begin_Out_End)
        {
            YWParserBuilder parser_builder("@begin b @out p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->block());

            Assert::AreEqual(std::string(
                "entered block"                 "\n"
                "entered begin tag"             "\n"
                "entered block name"            "\n"
                "exited block name"             "\n"
                "exited begin tag"              "\n"
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered output port keyword"   "\n"
                "exited output port keyword"    "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
                "entered end tag"               "\n"
                "exited end tag"                "\n"
                "exited block"                  "\n"
            ), listener.log());
        }
    };
}