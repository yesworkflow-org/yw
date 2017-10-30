#include "model_entity_listener.h"
#include "missing_argument_exception.h"
using namespace yw::sqlite;
using namespace yw::db;

using Direction = yw::db::Flow::Direction;

namespace yw {
    namespace model {

        void ModelEntityListener::enterBlock(YWParser::BlockContext *block) {
            auto rangeInLine = getRangeInLine(block);
            blockDescription = null_string;
            for (auto attribute : block->blockAttribute()) {
                auto desc = attribute->blockDesc();
                if (desc != nullptr) {
                    auto descText = desc->DescKeyword()->getText();
                    std::string blockDescriptionText;
                    try {
                        blockDescriptionText = safelyDescriptionTextFromBlockDescContext(desc);
                    }
                    catch (std::exception) {
                        throw yw::parse::MissingArgumentException(
                            descText,
                            "block description",
                            rangeInLine.start + 1,
                            currentLineNumber
                        );
                    }
                    blockDescription = blockDescriptionText;
                    break;
                }
            }
        }

        void ModelEntityListener::enterBegin(YWParser::BeginContext *begin)
        {
            AnnotationListener::enterBegin(begin);
            auto beginAnnotation = currentPrimaryAnnotation;
            programBlockStack.push(currentProgramBlock);
            auto programBlock = std::make_shared<ProgramBlock>(
                auto_id, modelId,
                (currentProgramBlock != nullptr ? currentProgramBlock->id : null_id),
                beginAnnotation->id, beginAnnotation->value.str(), blockDescription);
            ywdb.insert(*programBlock);
            currentProgramBlock = programBlock;
        }

        void ModelEntityListener::enterNestedBlocks(YWParser::NestedBlocksContext *nestedBlocks) {
            dataIdsStack.push(currentDataIds);
            currentDataIds = std::make_shared<std::map<std::string, row_id>>();
        }

        void ModelEntityListener::exitNestedBlocks(YWParser::NestedBlocksContext *nestedBlocks) {
            currentDataIds = dataIdsStack.top();
            dataIdsStack.pop();
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
                auto alias = attribute->alias();
                if (alias != nullptr) {
                    try {
                        portAlias = safelyGetAliasNameFromAliasContext(attribute->alias());
                    }
                    catch (std::exception) {
                        auto rangeInLine = getRangeInLine(alias);
                        throw yw::parse::MissingArgumentException(
                            alias->AsKeyword()->getText(),
                            "data name",
                            rangeInLine.start + 1,
                            currentLineNumber + 1
                        );
                    }
                    aliasedPortIndex = static_cast<int>(io->port()->portName().size()) - 1;
                    break;
                }
                else if (attribute->resource() != nullptr) {

                }
            }
        }

        void ModelEntityListener::enterPort(YWParser::PortContext *context) {
            AnnotationListener::enterPort(context);
            portNameIndex = 0;
        }


        nullable_row_id ModelEntityListener::currentWorkflowId() {
            return programBlockStack.size() > 1 ? programBlockStack.top()->id : null_id;
        }

        row_id ModelEntityListener::getIdForDataBlock(std::string dataName) {
            auto it = currentDataIds->find(dataName);
            row_id dataId;
            if (it == currentDataIds->end()) {
                dataId = ywdb.insert(DataBlock{ auto_id, modelId, currentWorkflowId(), null_id, dataName });
                (*currentDataIds)[dataName] = dataId;
            } else {
                dataId = it->second;
            }
            return dataId;
        }

        void ModelEntityListener::enterResource(YWParser::ResourceContext *context) {
            if (context->file() != nullptr) {
                flowTemplateScheme = null_string;
                flowTemplatePath = context->file()->pathTemplate()->getText();
            }
            else if (context->uri() != nullptr) {
                flowTemplateScheme = context->uri()->uriTemplate()->scheme()->getText();
                flowTemplatePath = context->uri()->uriTemplate()->pathTemplate()->getText();
            }
            else {
                flowTemplateScheme = null_string;
                flowTemplatePath = null_string;
            }
        }

        void ModelEntityListener::enterPortName(YWParser::PortNameContext *context) 
        {
            AnnotationListener::enterPortName(context);
            auto port = Port{ auto_id, currentProgramBlock->id.getValue(),
                 lastPortAnnotation->id, portName.getValue() };
            ywdb.insert(port);

            auto dataName = (portNameIndex == aliasedPortIndex) ? portAlias : portName.getValue();
            auto dataId = getIdForDataBlock(dataName);

            auto flow = Flow(auto_id, port.id.getValue(), dataId, portDirection, 1, 1);
            lastFlowId = ywdb.insert(flow);

            portNameIndex++;
        }

        void ModelEntityListener::exitIo(YWParser::IoContext *context) {
            if (flowTemplatePath.hasValue()) {
                auto flowTemplate = FlowTemplate{ auto_id, lastFlowId, flowTemplateScheme, flowTemplatePath.getValue() };
                ywdb.insert(flowTemplate);
                flowTemplateScheme = null_string;
                flowTemplatePath = null_string;
            }
            AnnotationListener::exitIo(context);
        }
    }
}