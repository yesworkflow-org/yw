#pragma once

#include "yw_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FileRow {

            const yw::sqlite::nullable_row_id id;
            const std::string name;

            FileRow(
                const yw::sqlite::nullable_row_id& rowId,
                const std::string& name
            ) : id(rowId), name(name) 
            {}
        };
    }
}