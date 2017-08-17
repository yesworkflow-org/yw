#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct ModelRow : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id userId;
            const nullable_row_id extractionId;
            const std::string created;

            ModelRow(
                const nullable_row_id& id,
                const nullable_row_id& userId,
                const nullable_row_id& extractionId,
                const std::string& created
            ) : id(id), userId(userId), extractionId(extractionId), created(created)
            {}
        };
    }
}