#pragma once

#include "yw_db.h"
#include "YWBaseListener.h"

namespace yw {
    namespace extract {

        class AnnotationExtractor {

            yw::db::YesWorkflowDB& ywdb;

        public:

            AnnotationExtractor(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            void extractAnnotationsFromString(
                const std::string& sourceText);
            
            void extractAnnotationsFromFile(
                const std::string& filePath);

            void extractAnnotationsFromFiles(
                const std::vector<std::string>& filePath);

        private:

            void extractAnnotationsFromString(
                const row_id& extractionId,
                const row_id& sourceId,
                const std::string& sourceString);

            void extractAnnotationsFromFile(
                const row_id& extractionId,
                const std::string& filePath);
        };
    }
}