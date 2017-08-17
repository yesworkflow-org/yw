#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct SourceRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::nullable_row_id fileId;
            const yw::nullable_string language;

            SourceRow(
                const yw::nullable_row_id& id,
                const yw::nullable_row_id& fileId,
                const yw::nullable_string& language
            ) : id(id), fileId(fileId), language(language) 
            {}
        };
    }
}