#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct DataBlock : sqlite::TableRow {

            const nullable_row_id id;
            const row_id modelId;
            const nullable_row_id structureId;
            const std::string name;

            DataBlock(
                const nullable_row_id& id,
                const row_id& modelId,
                const nullable_row_id& structureId,
                const std::string& name
            ) : id(id), modelId(modelId), structureId(structureId), name(name)
            {}
        };
    }
}