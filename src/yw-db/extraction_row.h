#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct ExtractionRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::nullable_row_id userId;
            const std::string created;

            ExtractionRow(
                const yw::nullable_row_id& id,
                const yw::nullable_row_id& userId,
                const std::string& created
            ) : id(id), userId(userId), created(created)
            {}
        };
    }
}