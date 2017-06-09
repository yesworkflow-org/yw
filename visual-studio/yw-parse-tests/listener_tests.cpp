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
		void enterBeginKeyword(YWParser::BeginKeywordContext *context) override { _log << "entered begin keyword" << endl; }
		void exitBeginKeyword(YWParser::BeginKeywordContext *context) override { _log << "exited begin keyword" << endl; }
		void enterBlockName(YWParser::BlockNameContext *context) override { _log << "entered block name" << endl; }
		void exitBlockName(YWParser::BlockNameContext *context) override { _log << "exited block name" << endl; }
		void enterBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "entered block attribute" << endl; }
		void exitBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "exited block attribute" << endl; }
		void enterEndKeyword(YWParser::EndKeywordContext *context) override { _log << "entered end keyword" << endl; }
		void exitEndKeyword(YWParser::EndKeywordContext *context) override { _log << "exited end keyword" << endl; }
		void enterPort(YWParser::PortContext *context) override { _log << "entered port" << endl; }
		void exitPort(YWParser::PortContext *context) override { _log << "exited port" << endl; }
		void enterCall(YWParser::CallContext *context) override { _log << "entered call" << endl; }
		void exitCall(YWParser::CallContext *context) override { _log << "exited call" << endl; }
		void enterInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "entered input port keyword" << endl; }
		void exitInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "exited input port keyword" << endl; }
		void enterOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "entered output port keyword" << endl; }
		void exitOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "exited output port keyword" << endl; }
		void enterPortAttribute(YWParser::PortAttributeContext *context) override { _log << "entered port attribute" << endl; }
		void exitPortAttribute(YWParser::PortAttributeContext *context) override { _log << "exited port attribute" << endl; }
		void enterPortAlias(YWParser::PortAliasContext *context) override { _log << "entered port alias" << endl; }
		void exitPortAlias(YWParser::PortAliasContext *context) override { _log << "exited port alias" << endl; }
		void enterInKeyword(YWParser::InKeywordContext *context) override { _log << "entered in keyword" << endl; }
		void exitInKeyword(YWParser::InKeywordContext *context) override { _log << "exited in keyword" << endl; }
		void enterParamKeyword(YWParser::ParamKeywordContext *context) override { _log << "entered param keyword" << endl; }
		void exitParamKeyword(YWParser::ParamKeywordContext *context) override { _log << "exited param keyword" << endl; }
		void enterOutKeyword(YWParser::OutKeywordContext *context) override { _log << "entered out keyword" << endl; }
		void exitOutKeyword(YWParser::OutKeywordContext *context) override { _log << "exited out keyword" << endl; }
		void enterReturnKeyword(YWParser::ReturnKeywordContext *context) override { _log << "entered return keyword" << endl; }
		void exitReturnKeyword(YWParser::ReturnKeywordContext *context) override { _log << "exited return keyword" << endl; }
		void enterPortName(YWParser::PortNameContext *context) override { _log << "entered port name" << endl; }
		void exitPortName(YWParser::PortNameContext *context) override { _log << "exited port name" << endl; }
		void enterAsKeyword(YWParser::AsKeywordContext *context) override { _log << "entered as keyword" << endl; }
		void exitAsKeyword(YWParser::AsKeywordContext *context) override { _log << "exited as keyword" << endl; }
		void enterDataName(YWParser::DataNameContext *context) override { _log << "entered data name" << endl; }
		void exitDataName(YWParser::DataNameContext *context) override { _log << "exited data name" << endl; }
	};

	TEST_CLASS(ListenerTests)
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
				"entered script"		"\n"
				"entered block"			"\n"
				"entered begin keyword"	"\n"
				"exited begin keyword"	"\n"
				"entered block name"	"\n"
				"exited block name"		"\n"
				"entered end keyword"	"\n"
				"exited end keyword"	"\n"
				"entered block name"	"\n"
				"exited block name"		"\n"
				"exited block"			"\n"
				"exited script"			"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Begin_End_NoFinalBlockName)
		{
			YWParser* parser = parse("@begin b @end");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->script());

			Assert::AreEqual(std::string(
				"entered script"		"\n"
				"entered block"			"\n"
				"entered begin keyword"	"\n"
				"exited begin keyword"	"\n"
				"entered block name"	"\n"
				"exited block name"		"\n"
				"entered end keyword"	"\n"
				"exited end keyword"	"\n"
				"exited block"			"\n"
				"exited script"			"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Begin_In_End)
		{
			YWParser* parser = parse("@begin b @in p @end");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

			Assert::AreEqual(std::string(
				"entered block"					"\n"
				"entered begin keyword"			"\n"
				"exited begin keyword"			"\n"
				"entered block name"			"\n"
				"exited block name"				"\n"
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered in keyword"			"\n"
				"exited in keyword"				"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
				"entered end keyword"			"\n"
				"exited end keyword"			"\n"
				"exited block"					"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Begin_Out_End)
		{
			YWParser* parser = parse("@begin b @out p @end");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

			Assert::AreEqual(std::string(
				"entered block"					"\n"
				"entered begin keyword"			"\n"
				"exited begin keyword"			"\n"
				"entered block name"			"\n"
				"exited block name"				"\n"
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered output port keyword"	"\n"
				"entered out keyword"			"\n"
				"exited out keyword"			"\n"
				"exited output port keyword"	"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
				"entered end keyword"			"\n"
				"exited end keyword"			"\n"
				"exited block"					"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_In)
		{
			YWParser* parser = parse("@in p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered in keyword"			"\n"
				"exited in keyword"				"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Param)
		{
			YWParser* parser = parse("@param p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered param keyword"			"\n"
				"exited param keyword"			"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Out)
		{
			YWParser* parser = parse("@out p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(				
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered output port keyword"	"\n"
				"entered out keyword"			"\n"
				"exited out keyword"			"\n"
				"exited output port keyword"	"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Return)
		{
			YWParser* parser = parse("@return p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered output port keyword"	"\n"
				"entered return keyword"		"\n"
				"exited return keyword"			"\n"
				"exited output port keyword"	"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}


		TEST_METHOD(TestListenerEventSequence_In_WithTwoPortsNamed)
		{
			YWParser* parser = parse("@in p q");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered in keyword"			"\n"
				"exited in keyword"				"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_In_WithAlias)
		{
			YWParser* parser = parse("@in p @as d");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered in keyword"			"\n"
				"exited in keyword"				"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"entered port attribute"		"\n"
				"entered port alias"			"\n"
				"entered as keyword"			"\n"
				"exited as keyword"				"\n"
				"entered data name"				"\n"
				"exited data name"				"\n"
				"exited port alias"				"\n"	
				"exited port attribute"			"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_In_WithTwoPortsNamed_OneWithAlias)
		{
			YWParser* parser = parse("@in p @as d q" );
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"		"\n"
				"entered port"					"\n"
				"entered input port keyword"	"\n"
				"entered in keyword"			"\n"
				"exited in keyword"				"\n"
				"exited input port keyword"		"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"entered port attribute"		"\n"
				"entered port alias"			"\n"
				"entered as keyword"			"\n"
				"exited as keyword"				"\n"
				"entered data name"				"\n"
				"exited data name"				"\n"
				"exited port alias"				"\n"
				"exited port attribute"			"\n"
				"entered port name"				"\n"
				"exited port name"				"\n"
				"exited port"					"\n"
				"exited block attribute"		"\n"
			), listener.log());
		}
	};
}