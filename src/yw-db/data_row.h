#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct DataRow : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id partOfId;
            const std::string name;

            DataRow(
                const nullable_row_id& id,
                const nullable_row_id& partOfId,
                const std::string& name
            ) : id(id), partOfId(partOfId), name(name)
            {}
        };
    }
}