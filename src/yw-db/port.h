#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Port : sqlite::TableRow {

            const nullable_row_id id;
            const row_id blockId;
            const nullable_row_id annotationId;
            const std::string name;

            Port(
                const nullable_row_id& id,
                const row_id& blockId,
                const nullable_row_id annotationId,
                const std::string& name
            ) : id(id), blockId(blockId), annotationId(annotationId), name(name)
            {}
        };
    }
}