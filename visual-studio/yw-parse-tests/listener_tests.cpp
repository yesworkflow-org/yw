#include "stdafx.h"
#include "CppUnitTest.h"

#include "YWLexer.h"
#include "YWListener.h"
#include "YWParser.h"
#include "YWBaseListener.h"

#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::stringstream;

namespace yw_parse_tests
{
	class YWListenerForTests : public YWBaseListener {
	private:
		stringstream _log;
	public:
		inline std::string log() { return _log.str(); }
		void enterBegin(YWParser::BeginContext *context) override {
			_log << "entered begin";
		}
	};

	TEST_CLASS(ListenerTests)
	{
	public:
		
		TEST_METHOD(TestEnterBegin)
		{
			stringstream ss("@begin foo");

			antlr4::ANTLRInputStream input(ss);
			YWLexer lexer(&input);
			antlr4::CommonTokenStream tokens(&lexer);
			YWParser parser(&tokens);

			antlr4::tree::ParseTree *tree = parser.begin();
			YWListenerForTests listener;
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

			Assert::AreEqual(std::string("entered begin"), listener.log());
		}
	};
}