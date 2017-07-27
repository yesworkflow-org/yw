#pragma once

#include "yesworkflow_db.h"
#include <string>
#include <sstream>
#include <ostream>
#include <map>

namespace yw {
    namespace db {

		struct AnnotationRow : yw::sqlite::TableRow {

			enum class Tag {
				BEGIN	= 1,
				END		= 2,
				DESC	= 3,
				IN		= 4,
				OUT		= 5,
				PARAM	= 6,
				RETURN	= 7,
				AS		= 8
			};

			AnnotationRow(
				yw::sqlite::nullable_row_id id, Tag tag, yw::sqlite::nullable_row_id qualifiesId, 
				long lineId, long rankOnLine, long start, long end, const std::string& keyword, 
				const yw::sqlite::nullable_string& value) 
				:
				id(id), tag(tag), qualifiesId(qualifiesId), lineId(lineId), rankOnLine(rankOnLine),
				start(start), end(end), keyword(keyword), value(value) 
			{};

			const yw::sqlite::nullable_row_id id;
			const Tag tag;
			const yw::sqlite::nullable_row_id qualifiesId;
			const yw::sqlite::row_id lineId;
			const long rankOnLine;
			const long start;
			const long end;
			const std::string keyword;
			const yw::sqlite::nullable_string value;

			std::string elements() const override {
				std::stringstream ss;
				ss  << id.str()
					<< "|" << to_string(tag)
					<< "|" << qualifiesId.str()
					<< "|" << lineId
					<< "|" << rankOnLine
					<< "|" << start
					<< "|" << end
					<< "|" << keyword
					<< "|" << value.str();
				return ss.str();
			}

			static std::string to_string(Tag tag) {
				static const std::vector<std::string> names { 
					"BEGIN", "END", "DESC", "IN", "OUT", "PARAM", "RETURN", "AS" 
				};
				return names[static_cast<int>(tag) - 1];
			}
		};
	}
}