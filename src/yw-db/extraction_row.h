#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct ExtractionRow {

            const yw::sqlite::nullable_row_id id;
            const yw::sqlite::row_id userId;
            const std::string created;

            ExtractionRow(
                const yw::sqlite::nullable_row_id& id,
                const yw::sqlite::row_id& userId,
                const std::string& created
            ) : id(id), userId(userId), created(created)
            {}
        };
    }
}