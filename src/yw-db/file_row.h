#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FileRow {

            const yw::sqlite::nullable_row_id id;
            const std::string name;
			
			FileRow(yw::sqlite::nullable_row_id rowId, const std::string& name) :
                id(rowId), name(name) {};
        };
    }
}