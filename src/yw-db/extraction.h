#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Extraction : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id userId;
            const std::string created;

            Extraction(
                const nullable_row_id& id,
                const nullable_row_id& userId,
                const std::string& created
            ) : id(id), userId(userId), created(created)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss <<        id.str()
                   << "|" << userId.str()
                   << "|" << created;
                return ss.str();
            }
        };
    }
}