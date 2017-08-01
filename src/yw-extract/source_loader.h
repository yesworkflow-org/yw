#pragma once

#include "yw_db.h"
#include "YWBaseListener.h"

namespace yw {
    namespace extract {

        class SourceLoader {

            yw::db::YesWorkflowDB& ywdb;
            yw::sqlite::row_id sourceId;

        public:

            SourceLoader(
                yw::db::YesWorkflowDB& ywdb, 
                yw::sqlite::row_id sourceId
            ) : ywdb(ywdb), sourceId(sourceId) 
            {}

            void loadFromString(const std::string& sourceString);
        };
    }
}