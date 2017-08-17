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
            yw::row_id insert(const AnnotationRow& row);
            AnnotationRow selectAnnotationById(const yw::row_id& requested_id);
            std::vector<AnnotationRow> selectTopLevelAnnotations();
            std::vector<AnnotationRow> selectAnnotationTree(const yw::nullable_row_id& rootAnnotationId);

            void createBlockTable();
            yw::row_id insert(const BlockRow& model);
            BlockRow selectBlockById(const yw::row_id& id);

            void createDataTable();
            yw::row_id insert(const DataRow& model);
            DataRow selectDataById(const yw::row_id& id);

            void createFileTable();
            yw::row_id insert(const FileRow& file);
            FileRow selectFileById(const yw::row_id& requested_id);

            void createLineTable();
            yw::row_id insert(const LineRow& line);
            LineRow selectLineById(const yw::row_id& requested_id);
            yw::row_id selectLineIdBySourceAndLineNumber(const yw::row_id& sourceId, long number);

            void createExtractionTable();
            yw::row_id insert(const ExtractionRow& extraction);
            ExtractionRow selectExtractionById(const yw::row_id& id);

            void createModelTable();
            yw::row_id insert(const ModelRow& model);
            ModelRow selectModelById(const yw::row_id& id);

            void createPortTable();
            yw::row_id insert(const PortRow& model);
            PortRow selectPortById(const yw::row_id& id);

            void createSourceTable();
            yw::row_id insert(const SourceRow& source);
            SourceRow selectSourceById(const yw::row_id& id);

            void createTransceiverTable();
            yw::row_id insert(const TransceiverRow& model);
            TransceiverRow selectTransceiverById(const yw::row_id& id);

            void createUserTable();
            yw::row_id insert(const UserRow& user);
            UserRow selectUserById(const yw::row_id& id);

            void createAllTables();
            size_t getRowCount(const std::string& tableName);

        private:

            static const std::string create_tables_sql;
            std::shared_ptr<yw::sqlite::SQLiteDB> db;
        };
    }
}