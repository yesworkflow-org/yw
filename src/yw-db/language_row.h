#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct LanguageRow {

            LanguageRow(long id, const std::string& name) :
                id(id), name(name) {};

			LanguageRow(const std::string& name) : 
				LanguageRow(yw::sqlite::NULL_ROW_ID, name) {};

            const long id;
            const std::string name;
        };
    }
}