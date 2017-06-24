#pragma once

#include "yesworkflow_db.h"

namespace yw_db {

    struct ModelRow {

        ModelRow(long id, long creator, std::string create_date) :
            id(id), creator(creator), create_date(create_date)
        {};

        const long id;
        const long creator;
        std::string create_date;
    };
}