#pragma once

#include "ywdb.h"
#include "flow.h"

namespace yw {
    namespace db {

        struct WorkflowPort : sqlite::TableRow {

            const nullable_row_id workflowId;
            const std::string workflowName;
            const row_id workflowPortId;
            const std::string workflowPortName;
            const row_id workflowDataBlockId;
            const std::string workflowDataBlockName;
            const row_id programDataBlockId;
            const std::string programDataBlockName;
            const row_id programPortId;
            const std::string programPortName;
            const row_id programBlockId;
            const std::string programBlockName;
            const Flow::Direction direction;

            WorkflowPort(
                const nullable_row_id& workflowId,
                const std::string& workflowName,
                const row_id& workflowPortId,
                const std::string& workflowPortName,
                const row_id& workflowDataBlockId,
                const std::string& workflowDataBlockName,
                const row_id&  programDataBlockId,
                const std::string& programDataBlockName,
                const row_id& programPortId,
                const std::string& programPortName,
                const row_id& programBlockId,
                const std::string& programBlockName,
                const Flow::Direction direction
            ) : workflowId(workflowId), workflowName(workflowName),
                workflowPortId(workflowPortId), workflowPortName(workflowPortName),
                workflowDataBlockId(workflowDataBlockId), workflowDataBlockName(workflowDataBlockName),
                programDataBlockId(programDataBlockId), programDataBlockName(programDataBlockName),
                programPortId(programPortId), programPortName(programPortName),
                programBlockId(programBlockId), programBlockName(programBlockName),
                direction(direction)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        workflowId.str()
                    << "|" << workflowName
                    << "|" << workflowPortId
                    << "|" << workflowPortName
                    << "|" << workflowDataBlockId
                    << "|" << workflowDataBlockName
                    << "|" << programDataBlockId
                    << "|" << programDataBlockName
                    << "|" << programPortId
                    << "|" << programPortName
                    << "|" << programBlockId
                    << "|" << programBlockName
                    << "|" << Flow::to_string(direction);
                return ss.str();
            }
        };
    }
}