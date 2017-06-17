#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw_db;

namespace yw_db_tests
{		
	TEST_CLASS(CreateDatabaseTests)
	{
	public:
		
		TEST_METHOD(TestConstructor_InMemoryDatabase)
		{
            YesWorkflowDB ywdb;
		}
	};
}