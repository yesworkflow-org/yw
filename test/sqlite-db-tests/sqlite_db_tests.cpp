#include "sqlite_db_tests.h"

using namespace yw::test;

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