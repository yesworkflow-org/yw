#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct ModelRow {

            ModelRow(long id, long userId, std::string creationDate) :
                id(id), userId(userId), creationDate(creationDate) {};

			ModelRow(long userId, std::string creationDate) :
				ModelRow(yw::sqlite::NULL_ROW_ID, userId, creationDate) {};
			
			const long id;
            const long userId;
            std::string creationDate;
        };
    }
}