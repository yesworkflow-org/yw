#pragma once

#include "yw_db.h"

namespace yw {
    namespace db {

        struct Transceiver : sqlite::TableRow {

            enum class Direction {
                IN = 1,
                OUT = 2
            };

            const nullable_row_id id;
            const row_id portId;
            const row_id dataId;
            const Direction direction;
            const nullable_long minRate;
            const nullable_long maxRate;

            Transceiver(
                const nullable_row_id& id,
                const row_id& portId,
                const row_id& dataId,
                Direction direction,
                const nullable_long& minRate,
                const nullable_long& maxRate
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