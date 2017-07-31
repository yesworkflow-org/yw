#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"
#include "annotation_row.h"
#include "file_row.h"
#include "line_row.h"
#include "extraction_row.h"
#include "source_row.h"
#include "user_row.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB(bool createTables = true);

			void createAnnotationTable();
			long insert(const AnnotationRow& row);
			AnnotationRow selectAnnotationById(long requested_id);
			std::vector<AnnotationRow> selectTopLevelAnnotations();
			std::vector<AnnotationRow> selectAnnotationTree(yw::sqlite::nullable_row_id rootAnnotationId);

			void createFileTable();
			long insert(const FileRow& file);
            FileRow selectFileById(long requested_id);

			void createLineTable();
			long insert(const LineRow& line);
			LineRow selectLineById(long requested_id);
			yw::sqlite::row_id selectLineIdBySourceAndLineNumber(yw::sqlite::row_id sourceId, long number);

			void createExtractionTable();
			long insert(const ExtractionRow& extraction);
            ExtractionRow selectExtractionById(long requested_id);

			void createSourceTable();
			long insert(const SourceRow& source);
            SourceRow selectSourceById(long id);

			void createAllTables();

			void createUserTable();
			long insert(const UserRow& user);
            UserRow selectUserById(long requested_id);

			size_t getRowCount(const std::string& tableName);

        private:

            static const std::string create_tables_sql;

            std::shared_ptr<yw::sqlite::SQLiteDB> db;

        };
    }
}