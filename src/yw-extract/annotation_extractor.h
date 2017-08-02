#pragma once

#include "yw_db.h"
#include "YWBaseListener.h"

namespace yw {
    namespace extract {

        class AnnotationExtractor {

            yw::db::YesWorkflowDB& ywdb;

        public:

            AnnotationExtractor(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            void extractAnnotationsFromString(const yw::sqlite::row_id& sourceId, const std::string& sourceString);
            void extractAnnotationsFromFile(const std::string& filePath);
        };
    }
}