#pragma once

#include "sqlite3.h"

class YesWorkflowDB {

    sqlite3* db;

    YesWorkflowDB() {
        int rc = sqlite3_open(":memory:", &db);
    }

};