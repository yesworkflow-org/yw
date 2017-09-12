#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct FlowView : sqlite::TableRow {

            const nullable_row_id flowId;
            const nullable_row_id workflowId;
            const row_id programBlockId;
            const std::string programBlockName;
            const row_id portId;
            const std::string portName;
            const row_id dataBlockId;
            const std::string dataBlockName;
            const Flow::Direction direction;
            const nullable_long minRate;
            const nullable_long maxRate;

            FlowView(
                const nullable_row_id& flowId,
                const nullable_row_id& workflowId,
                const row_id& programBlockId,
                const std::string& programBlockName,
                const row_id& portId,
                const std::string& portName,
                const row_id& dataBlockId,
                const std::string& dataBlockName,
                const Flow::Direction direction,
                const nullable_long& minRate,
                const nullable_long& maxRate
            ) : flowId(flowId), workflowId(workflowId), 
                programBlockId(programBlockId), programBlockName(programBlockName),
                portId(portId), portName(portName), 
                dataBlockId(dataBlockId), dataBlockName(dataBlockName), 
                direction(direction), minRate(minRate), maxRate(maxRate)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        flowId.str()
                    << "|" << workflowId.str()
                    << "|" << programBlockId
                    << "|" << programBlockName
                    << "|" << portId
                    << "|" << portName
                    << "|" << dataBlockId
                    << "|" << dataBlockName
                    << "|" << Flow::to_string(direction)
                    << "|" << minRate.str()
                    << "|" << maxRate.str();
                return ss.str();
            }
        };
    }
}