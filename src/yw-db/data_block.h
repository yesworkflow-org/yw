#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct DataBlock : sqlite::TableRow {

            nullable_row_id id;
            const row_id modelId;
            const nullable_row_id workflowId;
            const nullable_row_id structureId;
            const std::string name;

            DataBlock(
                const nullable_row_id& id,
                const row_id& modelId,
                const nullable_row_id& workflowId,
                const nullable_row_id& structureId,
                const std::string& name
            ) : id(id), modelId(modelId), workflowId(workflowId), structureId(structureId), name(name)
            {}

            std::string elements() const override {
                std::stringstream ss;
                ss << id.str()
                    << "|" << modelId
                    << "|" << workflowId.str()
                    << "|" << structureId.str()
                    << "|" << name;
                return ss.str();
            }
        };
    }
}