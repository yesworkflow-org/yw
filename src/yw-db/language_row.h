#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct LanguageRow {

            LanguageRow(yw::sqlite::nullable_row_id id, const std::string& name) :
                id(id), name(name) {};

            const yw::sqlite::nullable_row_id id;
            const std::string name;
        };
    }
}