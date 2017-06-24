#pragma once

#include "yesworkflow_db.h"

namespace yw_db {

    struct LanguageRow {

        LanguageRow(long id, const std::string& name) :
            id(id),
            name(name)
        {};

        const long id;
        const std::string name;
    };
}