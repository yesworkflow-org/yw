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
            const nullable_string description;

            ProgramBlock(
                const nullable_row_id& id,
                const row_id& modelId,
                const nullable_row_id& workflowId,
                const nullable_row_id& annotationId,
                const std::string& name,
                const nullable_string& description
            ) : id(id), modelId(modelId), workflowId(workflowId), 
                annotationId(annotationId), name(name), description(description)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss   << id.str()
                    << "|" << modelId
                    << "|" << workflowId.str()
                    << "|" << annotationId.str()
                    << "|" << name
                    << "|" << description.str();
                return ss.str();
            }
        };
    }
}