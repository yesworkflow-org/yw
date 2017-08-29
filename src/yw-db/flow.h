#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Flow : sqlite::TableRow {

            enum class Direction {
                NONE    = 0,
                IN      = 1,
                OUT     = 2
            };

            const nullable_row_id id;
            const row_id portId;
            const row_id dataBlockId;
            const Direction direction;
            const nullable_long minRate;
            const nullable_long maxRate;

            Flow(
                const nullable_row_id& id,
                const row_id& portId,
                const row_id& dataBlockId,
                Direction direction,
                const nullable_long& minRate,
                const nullable_long& maxRate
            ) : id(id), portId(portId), dataBlockId(dataBlockId), direction(direction), minRate(minRate), maxRate(maxRate)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << portId
                    << "|" << dataBlockId
                    << "|" << to_string(direction)
                    << "|" << minRate.str()
                    << "|" << maxRate.str();
                return ss.str();
            }

            static std::string to_string(Direction direction) {
                static const std::vector<std::string> names{
                    "NONE", "IN", "OUT"
                };
                return names[static_cast<int>(direction)];
            }
        };
    }
}