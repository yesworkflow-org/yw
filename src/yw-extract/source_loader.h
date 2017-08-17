#pragma once

#include "yw_db.h"
#include "YWBaseListener.h"

namespace yw {
    namespace extract {

        class SourceLoader {

            yw::db::YesWorkflowDB& ywdb;

        public:

            SourceLoader(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            void insertSourceLinesFromString(const row_id& sourceId, const std::string& sourceString);            
            std::string insertSourceLinesFromFile(const row_id& sourceId, const std::string& filePath);
        };
    }
}