#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct Source : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id fileId;
            const nullable_string language;

            Source(
                const nullable_row_id& id,
                const nullable_row_id& fileId,
                const nullable_string& language
            ) : id(id), fileId(fileId), language(language) 
            {}
        };
    }
}