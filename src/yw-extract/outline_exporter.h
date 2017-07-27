#pragma once

#include "yesworkflow_db.h"

namespace yw {
	namespace extract {
		class OutlineExporter {
		
			yw::db::YesWorkflowDB& ywdb;

		public:
		
			OutlineExporter(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

			std::string getOutline();
			std::string getOutline(yw::sqlite::nullable_row_id rootAnnotation);

		};
	}
}
