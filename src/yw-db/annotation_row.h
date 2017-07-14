#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct AnnotationRow {

			AnnotationRow(yw::sqlite::nullable_id id, yw::sqlite::nullable_id qualifiesId, long lineId, long start, long end,
				const std::string& tag, const std::string& value) :
				id(id), qualifiesId(qualifiesId), lineId(lineId), start(start), end(end), tag(tag), value(value) {};

			AnnotationRow(yw::sqlite::nullable_id qualifiesId, long lineId, long start, long end,
				const std::string& tag, const std::string& value) : 
				AnnotationRow(yw::sqlite::nullable<long>{}, qualifiesId, lineId, start, end, tag, value) {};

			const yw::sqlite::nullable_id id;
			const yw::sqlite::nullable_id qualifiesId;
			const long lineId;
			const long start;
			const long end;
			const std::string tag;
			const std::string value;
		};
    }
}