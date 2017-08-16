#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct ModelRow : yw::sqlite::TableRow {

            const yw::sqlite::nullable_row_id id;
            const yw::sqlite::nullable_row_id userId;
            const yw::sqlite::nullable_row_id extractionId;
            const std::string created;

            ModelRow(
                const yw::sqlite::nullable_row_id& id,
                const yw::sqlite::nullable_row_id& userId,
                const yw::sqlite::nullable_row_id& extractionId,
                const std::string& created
            ) : id(id), userId(userId), extractionId(extractionId), created(created)
            {}
        };
    }
}