#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct LineRow {

			LineRow(long id, long sourceId, long number, const std::string& text) :
				id(id), sourceId(sourceId), number(number), text(text) {};

			LineRow(long sourceId, long number, const std::string& text) :
				LineRow(yw::sqlite::NULL_ROW_ID, sourceId, number, text) {};

			const long id;
			const long sourceId;
			const long number;
			const std::string text;

			std::string str() const {
				std::stringstream s;
				s << "|" << id << "|" << sourceId << "|" << number << "|" << text << "|";
				return s.str();
			}

			operator std::string() { return str(); }
		};
    }
}