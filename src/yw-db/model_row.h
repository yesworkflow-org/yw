#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct ModelRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::nullable_row_id userId;
            const yw::nullable_row_id extractionId;
            const std::string created;

            ModelRow(
                const yw::nullable_row_id& id,
                const yw::nullable_row_id& userId,
                const yw::nullable_row_id& extractionId,
                const std::string& created
            ) : id(id), userId(userId), extractionId(extractionId), created(created)
            {}
        };
    }
}