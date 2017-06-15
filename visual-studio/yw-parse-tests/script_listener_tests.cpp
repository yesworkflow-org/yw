#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace yw_parse_tests
{
    TEST_CLASS(ScriptListenerTests)
    {
    public:

        TEST_METHOD(TestScriptListener_Begin_End_WithFinalBlockName)
        {
            YWListenerForTests listener;
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
            YWListenerForTests listener;
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
            YWListenerForTests listener;
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