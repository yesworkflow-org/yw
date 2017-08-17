#pragma once

#include "yw_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FileRow : sqlite::TableRow {

            const nullable_row_id id;
            const std::string name;

            FileRow(
                const nullable_row_id& rowId,
                const std::string& name
            ) : id(rowId), name(name) 
            {}
        };
    }
}