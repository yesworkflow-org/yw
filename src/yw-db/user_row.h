#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct UserRow {

			UserRow(long id, const yw::sqlite::nullable_string& name) :
				id(id), name(name) {};

			UserRow(const yw::sqlite::nullable_string& name) :
				UserRow(yw::sqlite::NULL_ROW_ID, name) {};

			const long id;
			const yw::sqlite::nullable_string name;
		};
    }
}