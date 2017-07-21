#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct LineRow : yw::sqlite::TableRow {

			LineRow(
				yw::sqlite::nullable_row_id id, yw::sqlite::row_id sourceId, 
				long number, const std::string& text) 
				:
				id(id), sourceId(sourceId), number(number), text(text) 
			{};

			const yw::sqlite::nullable_row_id id;
			const yw::sqlite::row_id sourceId;
			const long number;
			const std::string text;

			std::string elements() const override {
				std::stringstream ss;
				ss << id.str()
					<< "|" << sourceId
					<< "|" << number
					<< "|" << text;
				return ss.str();
			}
		};
    }
}