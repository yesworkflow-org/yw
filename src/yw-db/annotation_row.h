#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct AnnotationRow {

			AnnotationRow(long id, long qualifies, long line, long start, long end,
				const std::string& tag, const std::string& value) :
				id(id), qualifies(qualifies), line(line), start(start), end(end), tag(tag), value(value) {};

			AnnotationRow(long qualifies, long line, long start, long end,
				const std::string& tag, const std::string& value) : 
				AnnotationRow(yw::sqlite::NULL_ROW_ID, qualifies, line, start, end, tag, value) {};

			const long id;
			const long qualifies;
			const long line;
			const long start;
			const long end;
			const std::string tag;
			const std::string value;
		};
    }
}