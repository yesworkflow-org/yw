#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct AdjacentDataBlockPair : sqlite::TableRow {

            const nullable_row_id workflowId;
            const row_id inputDataBlockId;
            const std::string inputDataBlockName;
            const row_id inputPortId;
            const std::string inputPortName;
            const row_id programBlockId;
            const std::string programBlockName;
            const row_id outputPortId;
            const std::string outputPortName;
            const row_id outputDataBlockId;
            const std::string outputDataBlockName;

            AdjacentDataBlockPair(
                const nullable_row_id& workflowId,
                const row_id& inputDataBlockId,
                const std::string& inputDataBlockName,
                const row_id& inputPortId,
                const std::string& inputPortName,
                const row_id& programBlockId,
                const std::string& programBlockName,
                const row_id& outputPortId,
                const std::string& outputPortName,
                const row_id& outputDataBlockId,
                const std::string& outputDataBlockName
            ) : workflowId(workflowId),
                inputDataBlockId(inputDataBlockId), inputDataBlockName(inputDataBlockName),
                inputPortId(inputPortId), inputPortName(inputPortName),
                programBlockId(programBlockId), programBlockName(programBlockName),
                outputPortId(outputPortId), outputPortName(outputPortName),
                outputDataBlockId(outputDataBlockId), outputDataBlockName(outputDataBlockName)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss << workflowId.str()
                    << "|" << inputDataBlockId
                    << "|" << inputDataBlockName
                    << "|" << inputPortId
                    << "|" << inputPortName
                    << "|" << programBlockId
                    << "|" << programBlockName
                    << "|" << outputPortId
                    << "|" << outputPortName
                    << "|" << outputDataBlockId
                    << "|" << outputDataBlockName;
                return ss.str();
            }
        };

        struct DataProgramDataEdge {
            const std::string inputDataBlockName;
            const std::string programBlockName;
            const std::string outputDataBlockName;
        };

        struct DataDataEdge {
            const std::string inputDataBlockName;
            const std::string outputDataBlockName;
        };

    }
}