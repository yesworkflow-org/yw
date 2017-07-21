#pragma once

#include "yesworkflow_db.h"
#include <sstream>
#include <ostream>

namespace yw {
    namespace db {

		struct AnnotationRow : yw::sqlite::TableRow {

			AnnotationRow(
				yw::sqlite::nullable_row_id id, yw::sqlite::nullable_row_id qualifiesId, 
				long lineId, long start, long end, const std::string& tag, 
				const yw::sqlite::nullable_string& value) 
				:
				id(id), qualifiesId(qualifiesId), lineId(lineId), 
				start(start), end(end), tag(tag), value(value) 
			{};

			const yw::sqlite::nullable_row_id id;
			const yw::sqlite::nullable_row_id qualifiesId;
			const yw::sqlite::row_id lineId;
			const long start;
			const long end;
			const std::string tag;
			const yw::sqlite::nullable_string value;

			std::string elements() const override {
				std::stringstream ss;
				ss  << id.str()
					<< "|" << qualifiesId.str()
					<< "|" << lineId
					<< "|" << start
					<< "|" << end
					<< "|" << tag
					<< "|" << value.str();
				return ss.str();
			}
		};
	}
}