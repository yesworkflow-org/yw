#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct SourceRow {

            SourceRow(yw::sqlite::nullable_row_id id, yw::sqlite::row_id modelId, 
					  yw::sqlite::row_id languageId, yw::sqlite::nullable_row_id fileId) :
                id(id), modelId(modelId), languageId(languageId), fileId(fileId) {};

			const yw::sqlite::nullable_row_id id;
			const yw::sqlite::row_id modelId;
			const yw::sqlite::row_id languageId;
			const yw::sqlite::nullable_row_id  fileId;
        };
    }
}