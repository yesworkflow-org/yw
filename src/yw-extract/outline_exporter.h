#pragma once

#include "yesworkflow_db.h"

namespace yw {
	namespace extract {
		class OutlineExporter {
		
			yw::db::YesWorkflowDB& ywdb;

		public:
		
			OutlineExporter(yw::db::YesWorkflowDB& ywdb) : ywdb(ywdb) {}

			std::string getOutline(yw::sqlite::row_id rootAnnotation);

		};
	}
}
