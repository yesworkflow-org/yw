#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct PortRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::row_id blockId;
            const yw::nullable_row_id annotationId;
            const std::string name;

            PortRow(
                const yw::nullable_row_id& id,
                const yw::row_id& blockId,
                const yw::nullable_row_id annotationId,
                const std::string& name
            ) : id(id), blockId(blockId), annotationId(annotationId), name(name)
            {}
        };
    }
}