#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FileRow {

            const long id;
            const std::string name;
			
			FileRow(long rowId, const std::string& name) :
                id(rowId), name(name) {};

			FileRow(const std::string& name) : 
				FileRow(yw::sqlite::NULL_ROW_ID, name) {}

            std::string str() const { 
                std::stringstream s;
                s << "|" << id << "|" << name << "|";
                return s.str();
            }

            operator std::string() { return str(); }
        };
    }
}