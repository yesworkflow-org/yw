#pragma once

#include "ywdb.h"
#include <sstream>

namespace yw {
    namespace db {

        struct File : sqlite::TableRow {

            const nullable_row_id id;
            const std::string name;

            File(
                const nullable_row_id& rowId,
                const std::string& name
            ) : id(rowId), name(name) 
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << name;
                return ss.str();
            }
        };
    }
}