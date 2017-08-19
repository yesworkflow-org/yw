#include "model_entity_listener.h"

using namespace yw::sqlite;
using namespace yw::db;

using Direction = yw::db::Transceiver::Direction;

namespace yw {
    namespace model {

        void ModelEntityListener::enterBegin(YWParser::BeginContext *begin)
        {
            AnnotationListener::enterBegin(begin);
            auto beginAnnotation = currentPrimaryAnnotation;
            programBlockStack.push(currentProgramBlock);
            auto programBlock = std::make_shared<ProgramBlock>(
                auto_id, modelId, 
                (currentProgramBlock != nullptr ? currentProgramBlock->id : null_id),
                beginAnnotation->id, beginAnnotation->value.str());
            ywdb.insert(*programBlock);
            currentProgramBlock = programBlock;
        }

        void ModelEntityListener::enterEnd(YWParser::EndContext *end)
        {
            AnnotationListener::enterEnd(end);
            currentProgramBlock = programBlockStack.top();
            programBlockStack.pop();
        }
    }
}