#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct DataRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::nullable_row_id partOfId;
            const std::string name;

            DataRow(
                const yw::nullable_row_id& id,
                const yw::nullable_row_id& partOfId,
                const std::string& name
            ) : id(id), partOfId(partOfId), name(name)
            {}
        };
    }
}