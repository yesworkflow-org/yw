#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"
#include "annotation_row.h"
#include "block_row.h"
#include "data_row.h"
#include "extraction_row.h"
#include "file_row.h"
#include "line_row.h"
#include "model_row.h"
#include "port_row.h"
#include "source_row.h"
#include "transceiver_row.h"
#include "user_row.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB(bool createTables = true);

            void createAnnotationTable();
            row_id insert(const AnnotationRow& row);
            AnnotationRow selectAnnotationById(const row_id& requested_id);
            std::vector<AnnotationRow> selectTopLevelAnnotations();
            std::vector<AnnotationRow> selectAnnotationTree(const nullable_row_id& rootAnnotationId);

            void createBlockTable();
            row_id insert(const BlockRow& model);
            BlockRow selectBlockById(const row_id& id);

            void createDataTable();
            row_id insert(const DataRow& model);
            DataRow selectDataById(const row_id& id);

            void createFileTable();
            row_id insert(const FileRow& file);
            FileRow selectFileById(const row_id& requested_id);

            void createLineTable();
            row_id insert(const LineRow& line);
            LineRow selectLineById(const row_id& requested_id);
            row_id selectLineIdBySourceAndLineNumber(const row_id& sourceId, long number);

            void createExtractionTable();
            row_id insert(const ExtractionRow& extraction);
            ExtractionRow selectExtractionById(const row_id& id);

            void createModelTable();
            row_id insert(const ModelRow& model);
            ModelRow selectModelById(const row_id& id);

            void createPortTable();
            row_id insert(const PortRow& model);
            PortRow selectPortById(const row_id& id);

            void createSourceTable();
            row_id insert(const SourceRow& source);
            SourceRow selectSourceById(const row_id& id);

            void createTransceiverTable();
            row_id insert(const TransceiverRow& model);
            TransceiverRow selectTransceiverById(const row_id& id);

            void createUserTable();
            row_id insert(const UserRow& user);
            UserRow selectUserById(const row_id& id);

            void createAllTables();
            size_t getRowCount(const std::string& tableName);

        private:

            static const std::string create_tables_sql;
            std::shared_ptr<sqlite::SQLiteDB> db;
        };
    }
}