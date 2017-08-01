#pragma once

#include "yw_db.h"

namespace yw {
    namespace extract {
        class OutlineExporter {

            yw::db::YesWorkflowDB& ywdb;

        public:

            OutlineExporter(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

            std::string getOutline();
            std::string getOutline(const yw::sqlite::nullable_row_id& rootAnnotation);
        };
    }
}
