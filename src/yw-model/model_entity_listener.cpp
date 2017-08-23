#include "model_entity_listener.h"

using namespace yw::sqlite;
using namespace yw::db;

using Direction = yw::db::Flow::Direction;

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

        void ModelEntityListener::enterIo(YWParser::IoContext *io) {
            AnnotationListener::enterIo(io);
            portAlias = "";
            aliasedPortIndex = -1;
            for (auto attribute : io->portAttribute()) {
                if (attribute->alias() != nullptr) {
                    portAlias = attribute->alias()->dataName()->getText();
                    aliasedPortIndex = io->port()->portName().size() - 1;
                    break;
                }
            }
        }

        void ModelEntityListener::enterPort(YWParser::PortContext *context) {
            AnnotationListener::enterPort(context);
            portNameIndex = 0;
        }

        void ModelEntityListener::enterPortName(YWParser::PortNameContext *context) 
        {
            AnnotationListener::enterPortName(context);
            auto port = Port{ auto_id, currentProgramBlock->id.getValue(),
                 lastPortAnnotation->id, portName.getValue() };
            ywdb.insert(port);

            auto dataName = (portNameIndex == aliasedPortIndex) ? portAlias : portName.getValue();
            auto dataBlock = DataBlock(auto_id, modelId, null_id, dataName);
            ywdb.insert(dataBlock);

            auto flow = Flow(auto_id, port.id.getValue(), dataBlock.id.getValue(), 
                portDirection, 1, 1);
            ywdb.insert(flow);

            portNameIndex++;
        }
    }
}