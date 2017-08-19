#pragma once

#include "annotation_listener.h"

namespace yw {
    namespace model {

        class ModelEntityListener : public yw::extract::AnnotationListener{

        private:
            const row_id& modelId;
            std::shared_ptr<yw::db::ProgramBlock> currentProgramBlock = nullptr;
            std::stack<std::shared_ptr<yw::db::ProgramBlock>> programBlockStack;

        public:

            ModelEntityListener(
                yw::db::YesWorkflowDB& ywdb,
                const row_id& modelId,
                const row_id& extractionId,
                const row_id& sourceId
            ) : AnnotationListener(ywdb, extractionId, sourceId), modelId(modelId)
            {}

            void enterBegin(YWParser::BeginContext *begin) override;
            void enterEnd(YWParser::EndContext *context) override;
        };
    }
}

