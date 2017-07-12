#pragma once

#include "yesworkflow_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FileRow {

            const long id;
            const std::string name;
            const long owner;
			
			FileRow(long rowId, const std::string& name, long owner) :
                id(rowId), name(name), owner(owner) {};

			FileRow(const std::string& name, long owner) : 
				FileRow(yw::sqlite::NULL_ROW_ID, name, owner) {}

            std::string str() const { 
                std::stringstream s;
                s << "|" << id << "|" << name << "|" << "owner" << "|";
                return s.str();
            }

            operator std::string() { return str(); }
        };
    }
}