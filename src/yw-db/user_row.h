#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct UserRow {

			UserRow(long id, const std::string& name) : 
				id(id), name(name) {};

			UserRow(const std::string& name) : 
				UserRow(yw::sqlite::NULL_ROW_ID, name) {};

			const long id;
			const std::string name;
		};
    }
}