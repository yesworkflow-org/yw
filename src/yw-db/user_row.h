#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct UserRow {

			UserRow(const yw::sqlite::nullable_row_id id, const yw::sqlite::nullable_string& name) :
				id(id), name(name) {};

			const yw::sqlite::nullable_row_id  id;
			const yw::sqlite::nullable_string name;
		};
    }
}