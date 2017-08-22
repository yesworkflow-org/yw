#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Port : sqlite::TableRow {

            nullable_row_id id;
            const row_id programBlockId;
            const nullable_row_id annotationId;
            const std::string name;

            Port(
                const nullable_row_id& id,
                const row_id& programBlockId,
                const nullable_row_id& annotationId,
                const std::string& name
            ) : id(id), programBlockId(programBlockId), annotationId(annotationId), name(name)
            {}

            std::string elements() const override {
                std::stringstream ss;
                ss << id.str()
                    << "|" << programBlockId
                    << "|" << annotationId.str()
                    << "|" << name;
                return ss.str();
            }
        };
    }
}