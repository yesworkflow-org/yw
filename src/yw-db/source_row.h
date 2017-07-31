#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct SourceRow {

            const yw::sqlite::nullable_row_id id;
            const yw::sqlite::nullable_row_id fileId;
            const yw::sqlite::nullable_string language;

            SourceRow(
                const yw::sqlite::nullable_row_id& id,
                const yw::sqlite::nullable_row_id& fileId,
                const yw::sqlite::nullable_string& language
            ) : id(id), fileId(fileId), language(language) 
            {}
        };
    }
}