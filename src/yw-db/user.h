#pragma once

#include "ywdb.h"
#include <sstream>

namespace yw {
    namespace db {

        struct User : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_string name;

            User(
                const nullable_row_id& id,
                const nullable_string& name
            ) : id(id), name(name)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << name.str();
                return ss.str();
            }
        };
    }
}