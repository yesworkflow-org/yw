#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"

#include "annotation.h"
#include "data_block.h"
#include "extraction.h"
#include "file.h"
#include "flow.h"
#include "flow_template.h"
#include "line.h"
#include "model.h"
#include "port.h"
#include "program_block.h"
#include "source.h"
#include "user.h"

#include "flow_view.h"
#include "program_channel_view.h"
#include "workflow_port_view.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB(bool createTables = true);

            void createAnnotationTable();
            row_id insert(Annotation& annotation);
            row_id insert(const Annotation& annotation);
            Annotation selectAnnotationById(const row_id& requested_id);
            std::vector<Annotation> selectTopLevelAnnotations();
            std::vector<Annotation> selectAnnotationTree(const nullable_row_id& rootAnnotationId);

            void createDataBlockTable();
            row_id insert(DataBlock& model);
            row_id insert(const DataBlock& dataBlock);
            DataBlock selectDataBlockById(const row_id& id);
            std::vector<DataBlock> selectDataBlocksByWorkflowId(const row_id& workflowId);
            bool isInput(const row_id& dataId);
            bool isParamOnly(const row_id& dataId);

            void createFileTable();
            row_id insert(const File& file);
            File selectFileById(const row_id& requested_id);

            void createLineTable();
            row_id insert(const Line& line);
            Line selectLineById(const row_id& requested_id);
            row_id selectLineIdBySourceAndLineNumber(const row_id& sourceId, long number);

            void createExtractionTable();
            row_id insert(const Extraction& extraction);
            Extraction selectExtractionById(const row_id& id);

            void createModelTable();
            row_id insert(const Model& model);
            Model selectModelById(const row_id& id);

            void createFlowTemplateTable();
            row_id insert(const FlowTemplate& pathTemplate);
            FlowTemplate selectFlowTemplateById(const row_id& flowTemplateId);
            std::vector<FlowTemplate> selectFlowTemplatesByDataId(const row_id& dataId);

            void createPortTable();
            row_id insert(Port& model);
            row_id insert(const Port& port);
            Port selectPortById(const row_id& id);

            void createProgramBlockTable();
            row_id insert(ProgramBlock& programBlock);
            row_id insert(const ProgramBlock& programBlock);
            ProgramBlock selectProgramBlockById(const row_id& id);
            ProgramBlock selectProgramBlockByModelIdAndBlockName(const row_id& modelId, const std::string& blockName);
            std::vector<ProgramBlock> selectTopLevelProgramBlocksInModel(const row_id& modelId);
            std::vector<ProgramBlock> selectProgramBlocksInWorkflow(const row_id& workflowId);

            void createProgramChannelView();
            std::vector<ProgramChannel> selectProgramChannelsByWorkflowId(const row_id& workflowId);
            std::vector<DataDataEdge> YesWorkflowDB::selectDataDataEdges(const row_id& workflowId);
            std::vector<DataProgramDataEdge> YesWorkflowDB::selectDataProgramDataEdges(const row_id& workflowId);

            void createSourceTable();
            row_id insert(const Source& source);
            Source selectSourceById(const row_id& id);

            void createFlowTable();
            row_id insert(const Flow& flow);
            Flow selectFlowById(const row_id& id);
            std::vector<Flow> selectFlowsByWorkflowId(const row_id& workflowId);

            std::vector<FlowView> selectFlowViewsByWorkflowId(const row_id& workflowId);

            void createWorkflowPortView();
            std::vector<WorkflowPort> selectWorkflowPortsByWorkflowId(const row_id& workflowId);
            std::vector<std::string> YesWorkflowDB::selectWorkflowIODataNames(const row_id& workflowId, Flow::Direction direction);

            void createUserTable();
            row_id insert(const User& user);
            User selectUserById(const row_id& id);

            void createAllTables();
            size_t getRowCount(const std::string& tableName);

        private:

            static const std::string create_tables_sql;
            std::shared_ptr<sqlite::SQLiteDB> db;
        };
    }
}