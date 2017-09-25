#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct AdjacentProgramBlocks : sqlite::TableRow {

            const nullable_row_id workflowId;
            const row_id upstreamProgramBlockId;
            const std::string upstreamProgramBlockName;
            const row_id upstreamPortId;
            const std::string upstreamPortName;
            const row_id dataBlockId;
            const std::string dataBlockName;
            const row_id downstreamPortId;
            const std::string downstreamPortName;
            const row_id downstreamProgramBlockId;
            const std::string downstreamProgramBlockName;

            AdjacentProgramBlocks(
                const nullable_row_id& workflowId,
                const row_id& upstreamProgramBlockId,
                const std::string& upstreamProgramBlockName,
                const row_id& upstreamPortId,
                const std::string& upstreamPortName,
                const row_id& dataBlockId,
                const std::string& dataBlockName,
                const row_id& downstreamPortId,
                const std::string& downstreamPortName,
                const row_id& downstreamProgramBlockId,
                const std::string& downstreamProgramBlockName
            ) : workflowId(workflowId),
                upstreamProgramBlockId(upstreamProgramBlockId), upstreamProgramBlockName(upstreamProgramBlockName),
                upstreamPortId(upstreamPortId), upstreamPortName(upstreamPortName),
                dataBlockId(dataBlockId), dataBlockName(dataBlockName),
                downstreamPortId(downstreamPortId), downstreamPortName(downstreamPortName),
                downstreamProgramBlockId(downstreamProgramBlockId), downstreamProgramBlockName(downstreamProgramBlockName)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss << workflowId.str()
                    << "|" << upstreamProgramBlockId
                    << "|" << upstreamProgramBlockName
                    << "|" << upstreamPortId
                    << "|" << upstreamPortName
                    << "|" << dataBlockId
                    << "|" << dataBlockName
                    << "|" << downstreamPortId
                    << "|" << downstreamPortName
                    << "|" << downstreamProgramBlockId
                    << "|" << downstreamProgramBlockName;
                return ss.str();
            }
        };

        struct ProgramDataProgramEdge {
            const std::string upstreamProgramBlockName;
            const std::string dataBlockName;
            const std::string downstreamProgramBlockName;
        };

        struct ProgramProgramEdge {
            const std::string upstreamProgramBlockName;
            const std::string downstreamProgramBlockName;
        };

    }
}