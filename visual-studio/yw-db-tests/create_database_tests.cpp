#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace yw::db;

namespace yw {
    namespace db {

        TEST_CLASS(CreateDatabaseTests)
        {
        public:

            TEST_METHOD(TestConstructor_InMemoryDatabase)
            {
                YesWorkflowDB ywdb;
            }
        };
    }
}