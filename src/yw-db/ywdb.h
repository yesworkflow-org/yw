#pragma once

#include <memory>
#include <vector>

#include "sqlite_db.h"
#include "annotation.h"
#include "block.h"
#include "data.h"
#include "extraction.h"
#include "file.h"
#include "line.h"
#include "model.h"
#include "port.h"
#include "source.h"
#include "transceiver.h"
#include "user.h"

namespace yw {
    namespace db {

        class YesWorkflowDB {
        public:

            YesWorkflowDB(bool createTables = true);

            void createAnnotationTable();
            row_id insert(const Annotation& annotation);
            Annotation selectAnnotationById(const row_id& requested_id);
            std::vector<Annotation> selectTopLevelAnnotations();
            std::vector<Annotation> selectAnnotationTree(const nullable_row_id& rootAnnotationId);

            void createBlockTable();
            row_id insert(const Block& model);
            Block selectBlockById(const row_id& id);

            void createDataTable();
            row_id insert(const Data& model);
            Data selectDataById(const row_id& id);

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
            row_id insert(const Port& model);
            Port selectPortById(const row_id& id);

            void createSourceTable();
            row_id insert(const Source& source);
            Source selectSourceById(const row_id& id);

            void createTransceiverTable();
            row_id insert(const Transceiver& model);
            Transceiver selectTransceiverById(const row_id& id);

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