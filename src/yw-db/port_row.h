#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct PortRow : sqlite::TableRow {

            const nullable_row_id id;
            const row_id blockId;
            const nullable_row_id annotationId;
            const std::string name;

            PortRow(
                const nullable_row_id& id,
                const row_id& blockId,
                const nullable_row_id annotationId,
                const std::string& name
            ) : id(id), blockId(blockId), annotationId(annotationId), name(name)
            {}
        };
    }
}