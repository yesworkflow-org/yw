#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct SourceRow {

            SourceRow(long id, long model, long language, long file) :
                id(id), model(model), language(language), file(file) {};

			SourceRow(long model, long language, long file) :
				SourceRow(yw::sqlite::NULL_ROW_ID, model, language, file) {};

            const long id;
            const long model;
            const long language;
            const long file;
        };
    }
}