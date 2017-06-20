#pragma once

#include "yw_db.h"

namespace yw_db {

    struct SourceRow {

        SourceRow(sqlite3_int64 id, const unsigned char* path) :
            id((long)id),
            path(sqlite::textToString(path))
        {};

        const long id;
        const std::string path;
    };
}