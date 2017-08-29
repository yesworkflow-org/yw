#pragma once

#include "ywdb.h"
#include <sstream>

namespace yw {
    namespace db {

        struct Line : sqlite::TableRow {

            const nullable_row_id id;
            const row_id sourceId;
            const long number;
            const nullable_string text;

            Line(
                const nullable_row_id& id,
                const row_id& sourceId,
                long number,
                const nullable_string& text
            ) : id(id), sourceId(sourceId), number(number), text(text)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << sourceId
                    << "|" << number
                    << "|" << text.str();
                return ss.str();
            }
        };
    }
}