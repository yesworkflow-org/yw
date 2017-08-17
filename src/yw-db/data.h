#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Data : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id partOfId;
            const std::string name;

            Data(
                const nullable_row_id& id,
                const nullable_row_id& partOfId,
                const std::string& name
            ) : id(id), partOfId(partOfId), name(name)
            {}
        };
    }
}