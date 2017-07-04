#include "sqlite_db_tests.h"

using namespace yw::test;
using namespace yw::sqlite;

YW_TEST_FIXTURE(SQLiteDB)

YW_TEST_SET

    YW_TEST(SQLiteDB, InMemoryDatabase)
    {
        SQLiteDB db;
    }

YW_TEST_END