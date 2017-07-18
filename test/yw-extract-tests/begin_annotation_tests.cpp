#include "yw_extract_tests.h"

using namespace yw;
using namespace yw::extract;
using namespace  yw::parse;
using namespace yw::test;

YW_TEST_FIXTURE(BeginAnnotation)

	AnnotationListener listener;
	StderrRecorder stderrRecorder;

YW_TEST_SET

	YW_TEST(BeginAnnotation, Begin_End)
	{
		YWParserBuilder parser_builder("@begin b @end b");
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, parser_builder.parse()->script());

		Expect::EmptyString(stderrRecorder.str());
	}

YW_TEST_END
