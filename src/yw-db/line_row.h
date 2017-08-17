#pragma once

#include "yw_db.h"
#include <sstream>

namespace yw {
    namespace db {

        struct LineRow : yw::sqlite::TableRow {

            const yw::nullable_row_id id;
            const yw::row_id sourceId;
            const long number;
            const std::string text;

            LineRow(
                const yw::nullable_row_id& id,
                const yw::row_id& sourceId,
                long number,
                const std::string& text
            ) : id(id), sourceId(sourceId), number(number), text(text)
            {}

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