#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct AnnotationRow {

			AnnotationRow(long id, long qualifiesId, long lineId, long start, long end,
				const std::string& tag, const std::string& value) :
				id(id), qualifiesId(qualifiesId), lineId(lineId), start(start), end(end), tag(tag), value(value) {};

			AnnotationRow(long qualifiesId, long lineId, long start, long end,
				const std::string& tag, const std::string& value) : 
				AnnotationRow(yw::sqlite::NULL_ROW_ID, qualifiesId, lineId, start, end, tag, value) {};

			const long id;
			const long qualifiesId;
			const long lineId;
			const long start;
			const long end;
			const std::string tag;
			const std::string value;
		};
    }
}