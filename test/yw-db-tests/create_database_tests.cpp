#include "yw_db_tests.h"

using namespace yw::test;
using namespace yw::db;

YW_TEST_FIXTURE(YesWorkflowDB)

YW_TEST_SET

    YW_TEST(YesWorkflowDB, CreatInMemoryDatabase)
    {
        YesWorkflowDB ywdb;
    }

YW_TEST_END