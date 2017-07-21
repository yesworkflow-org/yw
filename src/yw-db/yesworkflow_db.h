#pragma once

#include <memory>
#include "sqlite_db.h"

#include "annotation_row.h"
#include "file_row.h"
#include "language_row.h"
#include "line_row.h"
#include "model_row.h"
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
			
			void createFileTable();
			long insert(const FileRow& file);
            FileRow selectFileById(long requested_id);

			void createLanguageTable();
			long insert(const LanguageRow& language);
            LanguageRow selectLanguageById(long requested_id);

			void createLineTable();
			long insert(const LineRow& line);
			LineRow selectLineById(long requested_id);

			void createModelTable();
			long insert(const ModelRow& model);
            ModelRow selectModelById(long requested_id);

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