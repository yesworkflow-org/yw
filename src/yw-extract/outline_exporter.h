#pragma once

#include "yw_db.h"

namespace yw {
    namespace extract {
        class OutlineExporter {

            yw::db::YesWorkflowDB& ywdb;
            size_t blockIndentSize;
            size_t nesting = 0;
            std::stringstream outline;

            void append(const yw::db::AnnotationRow& annotation);
            void appendOnNewLine(const yw::db::AnnotationRow& annotation);
            void appendOnSameLine(const yw::db::AnnotationRow& annotation);

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
