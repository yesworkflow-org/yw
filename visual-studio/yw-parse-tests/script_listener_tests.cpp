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
    TEST_CLASS(ScriptListenerTests)
    {
        YWListenerForTests listener;

    public:

        TEST_METHOD(TestScriptListener_Begin_End_WithFinalBlockName)
        {
            YWParserBuilder parser_builder("@begin b @end b");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->script());

            Assert::AreEqual(std::string(
                "entered script"        "\n"
                "entered block"         "\n"
                "entered begin tag"     "\n"
                "entered block name"    "\n"
                "exited block name"     "\n"
                "exited begin tag"      "\n"
                "entered end tag"       "\n"
                "entered block name"    "\n"
                "exited block name"     "\n"
                "exited end tag"        "\n"
                "exited block"          "\n"
                "exited script"         "\n"
            ), listener.log());
        }

        TEST_METHOD(TestScriptListener_Begin_End_NoFinalBlockName)
        {
            YWParserBuilder parser_builder("@begin b @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->script());

            Assert::AreEqual(std::string(
                "entered script"        "\n"
                "entered block"         "\n"
                "entered begin tag"     "\n"
                "entered block name"    "\n"
                "exited block name"     "\n"
                "exited begin tag"      "\n"
                "entered end tag"       "\n"
                "exited end tag"        "\n"
                "exited block"          "\n"
                "exited script"         "\n"
            ), listener.log());
        }

        TEST_METHOD(TestScriptListener_Begin_Desc_End)
        {
            YWParserBuilder parser_builder("@begin b @desc a simple block @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->script());

            Assert::AreEqual(std::string(
                "entered script"            "\n"
                "entered block"             "\n"
                "entered begin tag"         "\n"
                "entered block name"        "\n"
                "exited block name"         "\n"
                "exited begin tag"          "\n"
                "entered block attribute"   "\n"
                "entered desc tag"          "\n"
                "entered description"       "\n"
                "exited description"        "\n"
                "exited desc tag"           "\n"
                "exited block attribute"    "\n"
                "entered end tag"           "\n"
                "exited end tag"            "\n"
                "exited block"              "\n"
                "exited script"             "\n"
            ), listener.log());
        }
    };
}