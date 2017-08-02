#pragma once

#include "yw_db.h"
#include "YWBaseListener.h"

namespace yw {
    namespace extract {

        class SourceLoader {

            yw::db::YesWorkflowDB& ywdb;

        public:

            SourceLoader(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            void loadFromString(const std::string& sourceString);
            void SourceLoader::loadFromString(const yw::sqlite::row_id& sourceId, const std::string& sourceString);
            
            std::string loadFromFile(const yw::sqlite::row_id& sourceId, const std::string& filePath);
        };
    }
}