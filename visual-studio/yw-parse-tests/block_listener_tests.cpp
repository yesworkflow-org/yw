#include "common_includes.h"

using namespace yw::test;

namespace yw {
    namespace parse {

        TEST_CLASS(BlockListenerTests)
        {
        public:

            TEST_METHOD(TestBlockListener_Begin_In_End)
            {
                StubYWListener listener;
                YWParserBuilder parser_builder("@begin b @in p @end");
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->block());

                Assert::AreEqual(
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
                , listener.log());
            }

            TEST_METHOD(TestBlockListener_Begin_Out_End)
            {
                StubYWListener listener;
                YWParserBuilder parser_builder("@begin b @out p @end");
                antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->block());

                Assert::AreEqual(
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
                , listener.log());
            }
        };
    }
}