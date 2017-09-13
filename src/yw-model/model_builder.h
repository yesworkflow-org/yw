#pragma once

#include "ywdb.h"

namespace yw {
    namespace model {

        class ModelBuilder {

            yw::db::YesWorkflowDB& ywdb;
            row_id extractionId;
            row_id modelId;

        public:

            ModelBuilder(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            row_id buildModelFromString(const std::string& sourceText);            
            row_id buildModelFromFile(const std::string& filePath);
            row_id buildModelFromFiles(const std::vector<std::string>& filePath);

        private:

            void buildModelFromString(
                const row_id& sourceId,
                const std::string& sourceString
            );
        };
    }
}