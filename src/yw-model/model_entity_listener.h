#pragma once

#include "annotation_listener.h"

namespace yw {
    namespace model {

        class ModelEntityListener : public yw::extract::AnnotationListener{

        private:
            const row_id& modelId;
            std::shared_ptr<yw::db::ProgramBlock> currentProgramBlock = nullptr;
            std::stack<std::shared_ptr<yw::db::ProgramBlock>> programBlockStack;
            std::shared_ptr<std::map<std::string, row_id>> currentDataIds;
            std::stack<std::shared_ptr<std::map<std::string, row_id>>> dataIdsStack;
            std::string portAlias;
            int aliasedPortIndex;
            int portNameIndex;

        public:

            ModelEntityListener(
                yw::db::YesWorkflowDB& ywdb,
                const row_id& modelId,
                const row_id& extractionId,
                const row_id& sourceId
            ) : AnnotationListener(ywdb, extractionId, sourceId), modelId(modelId)
            {
                currentDataIds = std::make_shared<std::map<std::string, row_id>>();
            }

            row_id getIdForDataBlock(std::string name);
            nullable_row_id currentWorkflowId();

            void enterBegin(YWParser::BeginContext *begin) override;
            void enterEnd(YWParser::EndContext *end) override;
            void enterIo(YWParser::IoContext *io) override;
            void enterNestedBlocks(YWParser::NestedBlocksContext *nestedBlocks) override;
            void exitNestedBlocks(YWParser::NestedBlocksContext *nestedBlocks) override;
            void enterPort(YWParser::PortContext *context) override;
            void enterPortName(YWParser::PortNameContext *context) override;
        };
    }
}

