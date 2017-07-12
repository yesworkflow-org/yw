#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

		struct LineRow {

			LineRow(long id, long fileId, long number, const std::string& text) :
				id(id), fileId(fileId), number(number), text(text) {};

			LineRow(long fileId, long number, const std::string& text) :
				LineRow(yw::sqlite::NULL_ROW_ID, fileId, number, text) {};

			const long id;
			const long fileId;
			const long number;
			const std::string text;

			std::string str() const {
				std::stringstream s;
				s << "|" << id << "|" << fileId << "|" << number << "|" << text << "|";
				return s.str();
			}

			operator std::string() { return str(); }
		};
    }
}