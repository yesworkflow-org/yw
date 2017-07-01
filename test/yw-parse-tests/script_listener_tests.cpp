#include "yw_parse_tests.h"

using namespace yw::test;

namespace yw {
    namespace parse {

        TEST_CLASS(ScriptListenerTests)
        {
        public:

            TEST_METHOD(TestScriptListener_Begin_End_WithFinalBlockName)
            {
                StubYWListener listener;
                YWParserBuilder parser_builder("@begin b @end b");
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());

                Assert::AreEqual(
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
                , listener.log());
            }

            TEST_METHOD(TestScriptListener_Begin_End_NoFinalBlockName)
            {
                StubYWListener listener;
                YWParserBuilder parser_builder("@begin b @end");
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());

                Assert::AreEqual(
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
                , listener.log());
            }

            TEST_METHOD(TestScriptListener_Begin_Desc_End)
            {
                StubYWListener listener;
                YWParserBuilder parser_builder("@begin b @desc a simple block @end");
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());

                Assert::AreEqual(
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
                , listener.log());
            }
        };
    }
}