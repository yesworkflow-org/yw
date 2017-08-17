#pragma once

#include "yw_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct UserRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::nullable_string name;

            UserRow(
                const yw::nullable_row_id& id,
                const yw::nullable_string& name
            ) : id(id), name(name)
            {}
        };
    }
}