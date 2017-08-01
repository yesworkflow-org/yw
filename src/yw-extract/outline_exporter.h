#pragma once

#include "yw_db.h"

namespace yw {
    namespace extract {
        class OutlineExporter {

            yw::db::YesWorkflowDB& ywdb;
            size_t blockIndentSize;
            int qualifierIndentSize;
            bool qualifiersOnSameLine;
            size_t nesting;
            std::stringstream outline;

            void append(const yw::db::AnnotationRow& annotation);
            void appendOnNewLine(const yw::db::AnnotationRow& annotation, const size_t extraIndent = 0);
            void appendOnSameLine(const yw::db::AnnotationRow& annotation);

        public:

            OutlineExporter(
                yw::db::YesWorkflowDB& ywdb,
                size_t blockIndentSize = 0,
                int qualifierIndentSize = -1
            ) : ywdb(ywdb), blockIndentSize(blockIndentSize), 
                qualifierIndentSize(qualifierIndentSize),
                qualifiersOnSameLine(qualifierIndentSize < 0) 
            {}

            std::string getOutline();
            std::string getOutline(const yw::sqlite::nullable_row_id& rootAnnotation);
        };
    }
}
