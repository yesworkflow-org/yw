#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"
#include "listener_for_tests.h"
#include "ParserBuilder.h"
#include "test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;

namespace yw_parse_tests
{
    TEST_CLASS(ListenerSequenceTests)
    {
        YWListenerForTests listener;

    public:

        TEST_METHOD(TestListenerEventSequence_Begin_End_WithFinalBlockName)
        {
            ParserBuilder parserBuilder("@begin b @end b");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->script());

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

        TEST_METHOD(TestListenerEventSequence_Begin_End_NoFinalBlockName)
        {
            ParserBuilder parserBuilder("@begin b @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->script());

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

        TEST_METHOD(TestListenerEventSequence_Begin_Desc_End)
        {
            ParserBuilder parserBuilder("@begin b @desc a simple block @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->script());

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

        TEST_METHOD(TestListenerEventSequence_Begin_In_End)
        {
            ParserBuilder parserBuilder("@begin b @in p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->block());

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

        TEST_METHOD(TestListenerEventSequence_Begin_Out_End)
        {
            ParserBuilder parserBuilder("@begin b @out p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->block());

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

        TEST_METHOD(TestListenerEventSequence_In)
        {
            ParserBuilder parserBuilder("@in p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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


        TEST_METHOD(TestListenerEventSequence_In_Desc)
        {
            ParserBuilder parserBuilder("@in p @desc a single input port");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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

        TEST_METHOD(TestListenerEventSequence_Param)
        {
            ParserBuilder parserBuilder("@param p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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

        TEST_METHOD(TestListenerEventSequence_Out)
        {
            ParserBuilder parserBuilder("@out p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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

        TEST_METHOD(TestListenerEventSequence_Return)
        {
            ParserBuilder parserBuilder("@return p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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


        TEST_METHOD(TestListenerEventSequence_In_WithTwoPortsNamed)
        {
            ParserBuilder parserBuilder("@in p q");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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

        TEST_METHOD(TestListenerEventSequence_In_WithAlias)
        {
            ParserBuilder parserBuilder("@in p @as d");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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

        TEST_METHOD(TestListenerEventSequence_In_WithTwoPortsNamed_OneWithAlias)
        {
            ParserBuilder parserBuilder("@in p @as d q" );
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parserBuilder.parser()->blockAttribute());

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