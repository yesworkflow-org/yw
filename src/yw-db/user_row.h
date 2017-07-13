#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct UserRow {

			UserRow(long id, const yw::sqlite::NullableString& name) :
				id(id), name(name) {};

			UserRow(const yw::sqlite::NullableString& name) :
				UserRow(yw::sqlite::NULL_ROW_ID, name) {};

			const long id;
			const yw::sqlite::NullableString name;
		};
    }
}