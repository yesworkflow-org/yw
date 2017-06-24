#pragma once

#include "yesworkflow_db.h"

namespace yw_db {

    struct FileRow {

        FileRow(long id, const std::string& name, long owner) :
            id(id),
            name(name),
            owner(owner)
        {};

        const long id;
        const std::string name;
        const long owner;
    };
}