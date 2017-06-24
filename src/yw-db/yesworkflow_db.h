#pragma once

#include "sqlite_db.h"
#include "sqlite_statement.h"

#include "file_row.h"
#include "language_row.h"
#include "model_row.h"
#include "source_row.h"
#include "user_row.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB();

            long insertFile(const std::string& name, long owner);
            FileRow selectFileById(long requested_id);

            long insertLanguage(const std::string& name);
            LanguageRow selectLanguageById(long requested_id);

            long insertModel(long creator, const std::string& create_date);
            ModelRow selectModelById(long requested_id);

            long insertSource(long model, long language, long file);
            SourceRow selectSourceById(long id);

            long insertUser(const std::string& name);
            UserRow selectUserById(long requested_id);

        private:

            static const std::string create_tables_sql;

            yw::sqlite::SQLiteDB db;

            void createTables();
        };
    }
}