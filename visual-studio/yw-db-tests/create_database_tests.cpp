#include "common_includes.h"

using namespace yw::test;
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