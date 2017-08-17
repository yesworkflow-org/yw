#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct TransceiverRow : yw::sqlite::TableRow {

            enum class Direction {
                IN = 1,
                OUT = 2
            };

            const yw::nullable_row_id id;
            const yw::row_id portId;
            const yw::row_id dataId;
            const Direction direction;
            const yw::nullable_long minRate;
            const yw::nullable_long maxRate;

            TransceiverRow(
                const yw::nullable_row_id& id,
                const yw::row_id& portId,
                const yw::row_id& dataId,
                Direction direction,
                const yw::nullable_long& minRate,
                const yw::nullable_long& maxRate
            ) : id(id), portId(portId), dataId(dataId), direction(direction), minRate(minRate), maxRate(maxRate)
            {}

            static std::string to_string(Direction direction) {
                static const std::vector<std::string> names{
                    "IN", "OUT"
                };
                return names[static_cast<int>(direction) - 1];
            }
        };
    }
}