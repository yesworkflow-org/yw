#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct AnnotationRow {

			AnnotationRow(yw::sqlite::nullable_row_id id, yw::sqlite::nullable_row_id qualifiesId, long lineId, long start, long end,
				const std::string& tag, const std::string& value) :
				id(id), qualifiesId(qualifiesId), lineId(lineId), start(start), end(end), tag(tag), value(value) {};

			const yw::sqlite::nullable_row_id id;
			const yw::sqlite::nullable_row_id qualifiesId;
			const yw::sqlite::row_id lineId;
			const long start;
			const long end;
			const std::string tag;
			const std::string value;
		};
    }
}