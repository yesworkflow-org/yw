#pragma once

#include "yw_types.h"
#include <map>

namespace yw {
    namespace config {

        enum class SettingSource {
            UNKNOWN = 0,
            YW_DEFAULTS = 1,
            USER_DEFAULTS = 2,
            CASCADING_FILE = 3,
            LOCAL_FILE = 4,
            NAMED_FILE = 5,
            ENVIRONMENT = 6,
            COMMAND_LINE = 7
        };

        struct Setting {

            const std::string key;
            const std::string value;
            const SettingSource source;
            const std::string resource;

            Setting(
                const std::string& key, 
                const std::string& value, 
                const SettingSource source = SettingSource::UNKNOWN,
                const std::string& resource = NO_RESOURCE
            ) : key(key), value(value), source(source), resource(resource) {}

            static const Setting NO_SETTING;
            static const std::string NO_RESOURCE;
        };

        class Configuration {
            std::map<std::string, Setting> settings;
        public:
            Configuration() {}
            void insert(const Setting& setting);
            bool contains(const std::string& key);
            size_t size() { return settings.size(); }
            const Setting& get(const std::string& key);
        };
    }
}
