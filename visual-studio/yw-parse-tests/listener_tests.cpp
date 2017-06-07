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

		inline std::string log() { return _log.str(); }

		void enterScript(YWParser::ScriptContext *context) override { _log << "entered script" << endl;  }
		void exitScript(YWParser::ScriptContext *context) override { _log << "exited script" << endl; }
		void enterBlock(YWParser::BlockContext *context) override { _log << "entered block" << endl; }
		void exitBlock(YWParser::BlockContext *context) override { _log << "exited block" << endl; }
		void enterBegin(YWParser::BeginContext *context) override { _log << "entered begin" << endl; }
		void exitBegin(YWParser::BeginContext *context) override { _log << "exited begin" << endl; }
		void enterEnd(YWParser::EndContext *context) override { _log << "entered end" << endl; }
		void exitEnd(YWParser::EndContext *context) override { _log << "exited end" << endl; }
	};

	TEST_CLASS(ListenerTests)
	{
	private:
		
		YWListenerForTests listener;

		void parse(const char * text) {
			stringstream textStream(text);
			antlr4::ANTLRInputStream input(textStream);
			YWLexer lexer(&input);
			antlr4::CommonTokenStream tokens(&lexer);
			YWParser parser(&tokens);
			antlr4::tree::ParseTree *tree = parser.script();
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
		}

	public:

		TEST_METHOD(TestEnterBegin)
		{
			parse("@begin foo");
			
			Assert::AreEqual(std::string(
				"entered script"	"\n"
				"entered block"		"\n"
				"entered begin"		"\n"
				"exited begin"		"\n"
				"exited block"		"\n"
				"exited script"		"\n"
			), listener.log());
		}

		TEST_METHOD(TestEnterEnd)
		{
			parse("@begin bar @end bar");

			Assert::AreEqual(std::string(
				"entered script"	"\n"
				"entered block"		"\n"
				"entered begin"		"\n"
				"exited begin"		"\n"
				"entered end"		"\n"
				"exited end"		"\n"
				"exited block"		"\n"
				"exited script"		"\n"
			), listener.log());
		}
	};
}