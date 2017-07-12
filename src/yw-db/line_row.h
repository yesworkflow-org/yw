#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct LineRow {

			LineRow(long id, long file, long number, const std::string& text) :
				id(id), file(file), number(number), text(text) {};

			LineRow(long file, long number, const std::string& text) :
				LineRow(yw::sqlite::NULL_ROW_ID, file, number, text) {};

			const long id;
			const long file;
			const long number;
			const std::string text;

			std::string str() const {
				std::stringstream s;
				s << "|" << id << "|" << file << "|" << number << "|" << text << "|";
				return s.str();
			}

			operator std::string() { return str(); }
		};
    }
}