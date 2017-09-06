#pragma once

#include "yw_types.h"
#include <map>

namespace yw {
    namespace config {

        class YWConfiguration {

            struct SettingSource {
                enum class SourceType {
                    UNKNOWN         = 0,
                    YW_DEFAULTS     = 1,
                    USER_DEFAULTS   = 2,
                    CASCADING_FILE  = 3,
                    LOCAL_FILE      = 4,
                    NAMED_FILE      = 5,
                    ENVIRONMENT     = 6,
                    COMMAND_LINE    = 7
                };
                const SourceType type;
                const std::string resource;
                SettingSource(SourceType type, std::string resource)
                    : type(type), resource(resource) {}
            };

            struct Setting {
                const SettingSource source;
                const std::string name;
                const std::string value;
                Setting(SettingSource source, const std::string& name, const std::string& value)
                    : source(source), name(name), value(value) {}
            };

            std::map<std::string, YWConfiguration::Setting> settings;

            YWConfiguration() {}

            void insert(const YWConfiguration::Setting& setting);
        };
    }
}
