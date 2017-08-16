#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct BlockRow : yw::sqlite::TableRow {

            const yw::sqlite::nullable_row_id id;
            const yw::sqlite::row_id modelId;
            const yw::sqlite::nullable_row_id containerId;
            const yw::sqlite::nullable_row_id annotationId;
            const std::string name;

            BlockRow(
                const yw::sqlite::nullable_row_id& id,
                const yw::sqlite::row_id& modelId,
                const yw::sqlite::nullable_row_id containerId,
                const yw::sqlite::nullable_row_id annotationId,
                const std::string& name
            ) : id(id), modelId(modelId), containerId(containerId), annotationId(annotationId), name(name)
            {}
        };
    }
}