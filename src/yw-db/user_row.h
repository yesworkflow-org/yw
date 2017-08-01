#pragma once

#include "yw_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct UserRow : yw::sqlite::TableRow {

            const yw::sqlite::nullable_row_id id;
            const yw::sqlite::nullable_string name;

            UserRow(
                const yw::sqlite::nullable_row_id& id,
                const yw::sqlite::nullable_string& name
            ) : id(id), name(name)
            {}
        };
    }
}