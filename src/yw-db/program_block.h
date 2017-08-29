#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct ProgramBlock : sqlite::TableRow {

            nullable_row_id id;
            
            const row_id modelId;
            const nullable_row_id workflowId;
            const nullable_row_id annotationId;
            const std::string name;

            ProgramBlock(
                const nullable_row_id& id,
                const row_id& modelId,
                const nullable_row_id& workflowId,
                const nullable_row_id& annotationId,
                const std::string& name
            ) : id(id), modelId(modelId), workflowId(workflowId), annotationId(annotationId), name(name)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << modelId
                    << "|" << workflowId.str()
                    << "|" << annotationId.str()
                    << "|" << name;
                return ss.str();
            }
        };
    }
}