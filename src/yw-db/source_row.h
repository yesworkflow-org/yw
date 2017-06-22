#pragma once

#include "yesworkflow_db.h"

namespace yw_db {

    struct SourceRow {

        SourceRow(long id, const std::string& path) :
            id(id),
            path(path)
        {};

        const long id;
        const std::string path;
    };
}