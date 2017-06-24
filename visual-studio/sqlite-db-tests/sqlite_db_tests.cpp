#include "stdafx.h"
#include "CppUnitTest.h"
#include "sqlite_db.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace yw {
    namespace sqlite {

        TEST_CLASS(SQLiteDBTests)
        {
        public:

            TEST_METHOD(TestConstructor_InMemoryDatabase)
            {
                SQLiteDB db;
            }

        };
    }
}