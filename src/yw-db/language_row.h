#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct LanguageRow {

            LanguageRow(long id, const std::string& name) :
                id(id),
                name(name)
            {};

            const long id;
            const std::string name;
        };
    }
}