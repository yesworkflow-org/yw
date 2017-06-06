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
		void reset() {
			_log.clear();
		}
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
			antlr4::tree::ParseTree *tree = parser.begin();
			antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
		}

	public:
		
		TEST_METHOD_INITIALIZE(InitializeListenerTest) {
			listener.reset();
		}

		TEST_METHOD(TestEnterBegin)
		{
			parse("@begin foo");
			Assert::AreEqual(std::string("entered begin"), listener.log());
		}

	};
}