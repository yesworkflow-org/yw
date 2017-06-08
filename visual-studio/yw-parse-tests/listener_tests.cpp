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
		void enterBlockName(YWParser::BlockNameContext *context) override { _log << "entered block name" << endl; }
		void exitBlockName(YWParser::BlockNameContext *context) override { _log << "exited block name" << endl; }
		void enterBegin(YWParser::BeginContext *context) override { _log << "entered begin" << endl; }
		void exitBegin(YWParser::BeginContext *context) override { _log << "exited begin" << endl; }
		void enterBeginKeyword(YWParser::BeginKeywordContext *context) override { _log << "entered begin keyword" << endl; }
		void exitBeginKeyword(YWParser::BeginKeywordContext *context) override { _log << "exited begin keyword" << endl; }
		void enterEnd(YWParser::EndContext *context) override { _log << "entered end" << endl; }
		void exitEnd(YWParser::EndContext *context) override { _log << "exited end" << endl; }
		void enterEndKeyword(YWParser::EndKeywordContext *context) override { _log << "entered end keyword" << endl; }
		void exitEndKeyword(YWParser::EndKeywordContext *context) override { _log << "exited end keyword" << endl; }
		void enterBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "entered block attribute" << endl; }
		void exitBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "exited block attribute" << endl; }
		void enterPort(YWParser::PortContext *context) override { _log << "entered port" << endl; }
		void exitPort(YWParser::PortContext *context) override { _log << "exited port" << endl; }
		void enterInputPort(YWParser::InputPortContext *context) override { _log << "entered input port" << endl; }
		void exitInputPort(YWParser::InputPortContext *context) override { _log << "exited input port" << endl; }
		void enterOutputPort(YWParser::OutputPortContext *context) override { _log << "entered output port" << endl; }
		void exitOutputPort(YWParser::OutputPortContext *context) override { _log << "exited output port" << endl; }
		void enterIn(YWParser::InContext *context) override { _log << "entered in" << endl; }
		void exitIn(YWParser::InContext *context) override { _log << "exited in" << endl; }
		void enterParam(YWParser::ParamContext *context) override { _log << "entered param" << endl; }
		void exitParam(YWParser::ParamContext *context) override { _log << "exited param" << endl; }
		void enterOut(YWParser::OutContext *context) override { _log << "entered out" << endl; }
		void exitOut(YWParser::OutContext *context) override { _log << "exited out" << endl; }
		void enterRet(YWParser::RetContext *context) override { _log << "entered ret" << endl; }
		void exitRet(YWParser::RetContext *context) override { _log << "exited ret" << endl; }
		void enterPortName(YWParser::PortNameContext *context) override { _log << "entered port name" << endl; }
		void exitPortName(YWParser::PortNameContext *context) override { _log << "entered port name" << endl; }
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

		TEST_METHOD(TestListenerEventSequence_Begin_End)
		{
			YWParser* parser = parse("@begin b @end b");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->script());

			Assert::AreEqual(std::string(
				"entered script"		"\n"
				"entered block"			"\n"
				"entered begin"			"\n"
				"entered begin keyword"	"\n"
				"exited begin keyword"	"\n"
				"entered block name"	"\n"
				"exited block name"		"\n"
				"exited begin"			"\n"
				"entered end"			"\n"
				"entered end keyword"	"\n"
				"exited end keyword"	"\n"
				"entered block name"	"\n"
				"exited block name"		"\n"
				"exited end"			"\n"
				"exited block"			"\n"
				"exited script"			"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Begin_In_End)
		{
			YWParser* parser = parse("@begin b @in p @end b");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

			Assert::AreEqual(std::string(
				"entered block"				"\n"
				"entered begin"				"\n"
				"entered begin keyword"		"\n"
				"exited begin keyword"		"\n"
				"entered block name"		"\n"
				"exited block name"			"\n"
				"exited begin"				"\n"
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered input port"		"\n"
				"entered in"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited in"					"\n"
				"exited input port"			"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
				"entered end"				"\n"
				"entered end keyword"		"\n"
				"exited end keyword"		"\n"
				"entered block name"		"\n"
				"exited block name"			"\n"
				"exited end"				"\n"
				"exited block"				"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Begin_Out_End)
		{
			YWParser* parser = parse("@begin b @out p @end b");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->block());

			Assert::AreEqual(std::string(
				"entered block"				"\n"
				"entered begin"				"\n"
				"entered begin keyword"		"\n"
				"exited begin keyword"		"\n"
				"entered block name"		"\n"
				"exited block name"			"\n"
				"exited begin"				"\n"
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered output port"		"\n"
				"entered out"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited out"				"\n"
				"exited output port"		"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
				"entered end"				"\n"
				"entered end keyword"		"\n"
				"exited end keyword"		"\n"
				"entered block name"		"\n"
				"exited block name"			"\n"
				"exited end"				"\n"
				"exited block"				"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_In)
		{
			YWParser* parser = parse("@in p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered input port"		"\n"
				"entered in"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited in"					"\n"
				"exited input port"			"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Param)
		{
			YWParser* parser = parse("@param p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered input port"		"\n"
				"entered param"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited param"				"\n"
				"exited input port"			"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Out)
		{
			YWParser* parser = parse("@out p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(				
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered output port"		"\n"
				"entered out"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited out"				"\n"
				"exited output port"		"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
			), listener.log());
		}

		TEST_METHOD(TestListenerEventSequence_Return)
		{
			YWParser* parser = parse("@return p");
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser->blockAttribute());

			Assert::AreEqual(std::string(
				"entered block attribute"	"\n"
				"entered port"				"\n"
				"entered output port"		"\n"
				"entered ret"				"\n"
				"entered port name"			"\n"
				"entered port name"			"\n"
				"exited ret"				"\n"
				"exited output port"		"\n"
				"exited port"				"\n"
				"exited block attribute"	"\n"
			), listener.log());
		}
	};
}