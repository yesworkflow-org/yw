#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;
using std::endl;

namespace yw_parse_tests
{
    class YWListenerForTests : public YWBaseListener {
    private:
        stringstream _log;
    public:
        std::string log() { return _log.str(); }
        void enterScript(YWParser::ScriptContext *context) override { _log << "entered script" << endl;  }
        void exitScript(YWParser::ScriptContext *context) override { _log << "exited script" << endl; }
        void enterBlock(YWParser::BlockContext *context) override { _log << "entered block" << endl; }
        void exitBlock(YWParser::BlockContext *context) override { _log << "exited block" << endl; }
        void enterBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "entered block attribute" << endl; }
        void exitBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "exited block attribute" << endl; }
        void enterPortAttribute(YWParser::PortAttributeContext *context) override { _log << "entered port attribute" << endl; }
        void exitPortAttribute(YWParser::PortAttributeContext *context) override { _log << "exited port attribute" << endl; }

        void enterBeginTag(YWParser::BeginTagContext *context) override { _log << "entered begin tag" << endl; }
        void exitBeginTag(YWParser::BeginTagContext *context) override { _log << "exited begin tag" << endl; }
        void enterEndTag(YWParser::EndTagContext *context) override { _log << "entered end tag" << endl; }
        void exitEndTag(YWParser::EndTagContext *context) override { _log << "exited end tag" << endl; }
        void enterDescTag(YWParser::DescTagContext *context) override { _log << "entered desc tag" << endl; }
        void exitDescTag(YWParser::DescTagContext *context) override { _log << "exited desc tag" << endl; }
        void enterPortTag(YWParser::PortTagContext *context) override { _log << "entered port tag" << endl; }
        void exitPortTag(YWParser::PortTagContext *context) override { _log << "exited port tag" << endl; }
        void enterAliasTag(YWParser::AliasTagContext *context) override { _log << "entered alias tag" << endl; }
        void exitAliasTag(YWParser::AliasTagContext *context) override { _log << "exited alias tag" << endl; }
        void enterCallTag(YWParser::CallTagContext *context) override { _log << "entered call tag" << endl; }
        void exitCallTag(YWParser::CallTagContext *context) override { _log << "exited call tag" << endl; }
        void enterUriTag(YWParser::UriTagContext *context) override { _log << "entered uri tag" << endl; }
        void exitUriTag(YWParser::UriTagContext *context) override { _log << "exited uri tag" << endl; }
        void enterFileTag(YWParser::FileTagContext *context) override { _log << "entered file tag" << endl; }
        void exitFileTag(YWParser::FileTagContext *context) override { _log << "exited file tag" << endl; }
        void enterResourceTag(YWParser::ResourceTagContext *context) override { _log << "entered resource tag" << endl; }
        void exitResourceTag(YWParser::ResourceTagContext *context) override { _log << "exited resource tag" << endl; }

        void enterInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "entered input port keyword" << endl; }
        void exitInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "exited input port keyword" << endl; }
        void enterOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "entered output port keyword" << endl; }
        void exitOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "exited output port keyword" << endl; }

        void enterBlockName(YWParser::BlockNameContext *context) override { _log << "entered block name" << endl; }
        void exitBlockName(YWParser::BlockNameContext *context) override { _log << "exited block name" << endl; }
        void enterPortName(YWParser::PortNameContext *context) override { _log << "entered port name" << endl; }
        void exitPortName(YWParser::PortNameContext *context) override { _log << "exited port name" << endl; }
        void enterDataName(YWParser::DataNameContext *context) override { _log << "entered data name" << endl; }
        void exitDataName(YWParser::DataNameContext *context) override { _log << "exited data name" << endl; }
        void enterDescription(YWParser::DescriptionContext *context) override { _log << "entered description" << endl; }
        void exitDescription(YWParser::DescriptionContext *context) override { _log << "exited description" << endl; }
    };

    TEST_CLASS(ListenerSequenceTests)
    {
    private:
        
        YWListenerForTests listener;
        stringstream* textStream;
        antlr4::ANTLRInputStream* input;
        YWLexer* lexer;
        antlr4::CommonTokenStream* tokens;

        YWParser* parse(const char * text) {
            textStream = new stringstream(text);
            input = new antlr4::ANTLRInputStream(*textStream);
            lexer = new YWLexer(input);
            tokens = new antlr4::CommonTokenStream(lexer);
            return new YWParser(tokens);
        }

    public:

        TEST_METHOD(TestListenerEventSequence_Begin_End_WithFinalBlockName)
        {
            YWParser* parser = parse("@begin b @end b");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->script());

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
            YWParser* parser = parse("@begin b @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->script());

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
            YWParser* parser = parse("@begin b @desc a simple block @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->script());

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
            YWParser* parser = parse("@begin b @in p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

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
            YWParser* parser = parse("@begin b @out p @end");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

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
            YWParser* parser = parse("@in p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@in p @desc foo");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@param p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@out p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@return p");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@in p q");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@in p @as d");
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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
            YWParser* parser = parse("@in p @as d q" );
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

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