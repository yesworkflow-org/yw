#pragma once

#include "yesworkflow_db.h"

namespace yw {
    namespace db {

        struct SourceRow {

            SourceRow(long id, long model, long language, long file) :
                id(id), model(model), language(language), file(file)
            {};

            const long id;
            const long model;
            const long language;
            const long file;
        };
    }
}