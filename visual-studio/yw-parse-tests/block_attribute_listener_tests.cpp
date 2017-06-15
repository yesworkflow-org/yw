#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace yw_parse_tests
{
    TEST_CLASS(BlockAttributeListenerTests)
    {
    public:

        TEST_METHOD(TestBlockAttributeListener_In)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_In_Desc)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @desc a single input port");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
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
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_Param)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@param p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_Out)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@out p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered output port keyword"   "\n"
                "exited output port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_Return)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@return p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered output port keyword"   "\n"
                "exited output port keyword"    "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }


        TEST_METHOD(TestBlockAttributeListener_In_WithTwoPortsNamed)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p q");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
                "entered input port keyword"    "\n"
                "exited input port keyword"     "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_In_WithAlias)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @as d");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
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
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }

        TEST_METHOD(TestBlockAttributeListener_In_WithTwoPortsNamed_OneWithAlias)
        {
            StubYWListener listener;
            YWParserBuilder parser_builder("@in p @as d q");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parser()->blockAttribute());

            Assert::AreEqual(std::string(
                "entered block attribute"       "\n"
                "entered port tag"              "\n"
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
                "entered port name"             "\n"
                "exited port name"              "\n"
                "exited port tag"               "\n"
                "exited block attribute"        "\n"
            ), listener.log());
        }
    };
}