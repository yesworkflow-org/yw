#pragma once

#include "yw_db.h"

namespace yw {
    namespace extract {
        class OutlineExporter {

            yw::db::YesWorkflowDB& ywdb;
            size_t blockIndentSize;
            size_t currentIndent;
            std::stringstream outline;

            void printAnnotation(const yw::db::AnnotationRow& annotation);
 
        public:

            OutlineExporter(
                yw::db::YesWorkflowDB& ywdb,
                size_t blockIndentSize = 0
            ) : ywdb(ywdb), blockIndentSize(blockIndentSize) {}

            std::string getOutline();
            std::string getOutline(const yw::sqlite::nullable_row_id& rootAnnotation);
        };
    }
}
