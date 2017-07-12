#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct SourceRow {

            SourceRow(long id, long modelId, long languageId, long fileId) :
                id(id), modelId(modelId), languageId(languageId), fileId(fileId) {};

			SourceRow(long modelId, long languageId, long fileId) :
				SourceRow(yw::sqlite::NULL_ROW_ID, modelId, languageId, fileId) {};

            const long id;
            const long modelId;
            const long languageId;
            const long fileId;
        };
    }
}