#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace yw_parse_tests
{
    TEST_CLASS(PortListenerTests)
    {
    public:

        TEST_METHOD(TestPortListener_In)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_In_Desc)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @desc a single input port");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port attribute"        "\n"
                "entered desc tag"              "\n"
                "entered description"           "\n"
                "exited description"            "\n"
                "exited desc tag"               "\n"
                "exited port attribute"         "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_In_As_SingleWordAlias)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @as d");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port attribute"        "\n"
                "entered alias tag"             "\n"
                "entered data name"             "\n"
                "exited data name"              "\n"
                "exited alias tag"              "\n"
                "exited port attribute"         "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_In_As_MultiWordAlias)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @as first input port");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port attribute"        "\n"
                "entered alias tag"             "\n"
                "entered data name"             "\n"
                "exited data name"              "\n"
                "exited alias tag"              "\n"
                "exited port attribute"         "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_Param)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@param p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_Out)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@out p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered output port keyword"   "\n"
                "exited output port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_Return)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@return p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered output port keyword"   "\n"
                "exited output port keyword"    "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port"                   "\n"
            ), listener.log());
        }


        TEST_METHOD(TestPortListener_In_WithTwoPortsNamed)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p q");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port"                   "\n"
            ), listener.log());
        }

        TEST_METHOD(TestPortListener_In_WithTwoPortsNamed_FirstWithOneWordAlias)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p q @as d");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->port());

            Assert::AreEqual(std::string(
                "entered port"                  "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port attribute"        "\n"
                "entered alias tag"             "\n"
                "entered data name"             "\n"
                "exited data name"              "\n"
                "exited alias tag"              "\n"
                "exited port attribute"         "\n"
                "exited port"                   "\n"
            ), listener.log());
        }
    };
}