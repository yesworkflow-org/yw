#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"
#include "annotation.h"
#include "data_block.h"
#include "extraction.h"
#include "file.h"
#include "line.h"
#include "model.h"
#include "port.h"
#include "portal_view.h"
#include "program_block.h"
#include "source.h"
#include "flow.h"
#include "flow_view.h"
#include "user.h"

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

            void createSourceTable();
            row_id insert(const Source& source);
            Source selectSourceById(const row_id& id);

            void createFlowTable();
            row_id insert(const Flow& flow);
            Flow selectFlowById(const row_id& id);
            std::vector<Flow> selectFlowsByWorkflowId(const row_id& workflowId);

            std::vector<FlowView> selectFlowViewsByWorkflowId(const row_id& workflowId);
            std::vector<PortalView> selectPortalViewsByWorkflowId(const row_id& workflowId);

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