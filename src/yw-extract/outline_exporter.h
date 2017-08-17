#pragma once

#include "ywdb.h"
#include <stack>

namespace yw {
    namespace extract {
        class OutlineExporter {

            yw::db::YesWorkflowDB& ywdb;
            size_t blockIndentSize;
            int qualifierIndentSize;
            bool qualifiersOnSameLine;
            std::stack<yw::db::Annotation> blockStack;
            std::stringstream outline;

            void append(const std::string& keyword, const std::string& value);
            void appendOnNewLine(const std::string& keyword, const std::string& value, const size_t extraIndent = 0);
            void appendOnSameLine(const std::string& keyword, const std::string& value);

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
            std::string getOutline(const nullable_row_id& rootAnnotation);
        };
    }
}
