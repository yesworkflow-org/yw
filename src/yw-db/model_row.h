#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct ModelRow {

            ModelRow(yw::sqlite::nullable_row_id id, yw::sqlite::row_id userId, std::string creationDate) :
                id(id), userId(userId), creationDate(creationDate) {};

			const yw::sqlite::nullable_row_id id;
			const yw::sqlite::row_id userId;
            std::string creationDate;
        };
    }
}