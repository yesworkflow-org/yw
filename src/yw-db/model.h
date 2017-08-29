#pragma once

#include "ywdb.h"

namespace yw {
    namespace db {

        struct Model : sqlite::TableRow {

            const nullable_row_id id;
            const nullable_row_id userId;
            const nullable_row_id extractionId;
            const std::string created;

            Model(
                const nullable_row_id& id,
                const nullable_row_id& userId,
                const nullable_row_id& extractionId,
                const std::string& created
            ) : id(id), userId(userId), extractionId(extractionId), created(created)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                ss  <<        id.str()
                    << "|" << userId.str()
                    << "|" << extractionId.str()
                    << "|" << created;
                return ss.str();
            }
        };
    }
}