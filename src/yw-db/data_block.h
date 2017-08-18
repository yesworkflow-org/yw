#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct DataBlock : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id partOfId;
            const std::string name;

            DataBlock(
                const nullable_row_id& id,
                const nullable_row_id& partOfId,
                const std::string& name
            ) : id(id), partOfId(partOfId), name(name)
            {}
        };
    }
}