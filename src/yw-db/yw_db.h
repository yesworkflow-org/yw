#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"
#include "annotation_row.h"
#include "block_row.h"
#include "extraction_row.h"
#include "file_row.h"
#include "line_row.h"
#include "model_row.h"
#include "port_row.h"
#include "source_row.h"
#include "user_row.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB(bool createTables = true);

            void createAnnotationTable();
            yw::sqlite::row_id insert(const AnnotationRow& row);
            AnnotationRow selectAnnotationById(const yw::sqlite::row_id& requested_id);
            std::vector<AnnotationRow> selectTopLevelAnnotations();
            std::vector<AnnotationRow> selectAnnotationTree(const yw::sqlite::nullable_row_id& rootAnnotationId);

            void createBlockTable();
            yw::sqlite::row_id insert(const BlockRow& model);
            BlockRow selectBlockById(const yw::sqlite::row_id& id);

            void createFileTable();
            yw::sqlite::row_id insert(const FileRow& file);
            FileRow selectFileById(const yw::sqlite::row_id& requested_id);

            void createLineTable();
            yw::sqlite::row_id insert(const LineRow& line);
            LineRow selectLineById(const yw::sqlite::row_id& requested_id);
            yw::sqlite::row_id selectLineIdBySourceAndLineNumber(const yw::sqlite::row_id& sourceId, long number);

            void createExtractionTable();
            yw::sqlite::row_id insert(const ExtractionRow& extraction);
            ExtractionRow selectExtractionById(const yw::sqlite::row_id& id);

            void createModelTable();
            yw::sqlite::row_id insert(const ModelRow& model);
            ModelRow selectModelById(const yw::sqlite::row_id& id);

            void createPortTable();
            yw::sqlite::row_id insert(const PortRow& model);
            PortRow selectPortById(const yw::sqlite::row_id& id);

            void createSourceTable();
            yw::sqlite::row_id insert(const SourceRow& source);
            SourceRow selectSourceById(const yw::sqlite::row_id& id);

            void createUserTable();
            yw::sqlite::row_id insert(const UserRow& user);
            UserRow selectUserById(const yw::sqlite::row_id& id);

            void createAllTables();
            size_t getRowCount(const std::string& tableName);

        private:

            static const std::string create_tables_sql;
            std::shared_ptr<yw::sqlite::SQLiteDB> db;
        };
    }
}