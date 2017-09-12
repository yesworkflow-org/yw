#pragma once

#include "ywdb.h"

namespace yw {
    namespace model {

        class ModelBuilder {

            yw::db::YesWorkflowDB& ywdb;

        public:

            ModelBuilder(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            void buildModelFromString(const std::string& sourceText);            
            void buildModelFromFile(const std::string& filePath);
            void buildModelFromFiles(const std::vector<std::string>& filePath);

        private:

            void buildModelFromString(
                const row_id& modelId,
                const row_id& extractionId,
                const row_id& sourceId,
                const std::string& sourceString
            );

            void buildModelFromFile(
                const row_id& modelId,
                const row_id& extractionId,
                const std::string& filePath
            );
        };
    }
}