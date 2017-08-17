#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct Model : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id userId;
            const nullable_row_id extractionId;
            const std::string created;

            Model(
                const nullable_row_id& id,
                const nullable_row_id& userId,
                const nullable_row_id& extractionId,
                const std::string& created
            ) : id(id), userId(userId), extractionId(extractionId), created(created)
            {}
        };
    }
}