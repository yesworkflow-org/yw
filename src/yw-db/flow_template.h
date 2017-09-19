#pragma once

#include "ywdb.h"
#include <sstream>

namespace yw {
    namespace db {

        struct FlowTemplate : sqlite::TableRow {

            const nullable_row_id id;
            const row_id flow;
            const nullable_string scheme;
            const std::string path;

            FlowTemplate(
                const nullable_row_id& id,
                const row_id& flow,
                const nullable_string& scheme,
                const std::string& path
            ) : id(id), flow(flow), scheme(scheme), path(path)
            {}

            std::string fieldValues() const override {
                std::stringstream ss;
                    ss << id.str()
                    << "|" << flow
                    << "|" << scheme.str()
                    << "|" << path;
                return ss.str();
            }
        };
    }
}