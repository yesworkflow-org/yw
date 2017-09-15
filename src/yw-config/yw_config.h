#pragma once

#include "yw_types.h"

#include <map>

namespace yw {
    namespace config {

        struct Setting {

            enum class SettingSource {
                UNSPECIFIED = 0,
                YW_DEFAULTS = 1,
                USER_DEFAULTS = 2,
                CASCADING_FILE = 3,
                LOCAL_FILE = 4,
                NAMED_FILE = 5,
                ENVIRONMENT = 6,
                COMMAND_LINE = 7
            };

            const std::string key;
            const nullable_string value;
            const SettingSource source;
            const std::string resource;

            Setting(
                const std::string& key, 
                const nullable_string& value, 
                const SettingSource source = SettingSource::UNSPECIFIED,
                const std::string& resource = NO_RESOURCE
            ) : key(key), value(value), source(source), resource(resource) {}

            static const Setting NO_SETTING;
            static const std::string NO_RESOURCE;
        };

        struct SoftwareSetting : public Setting {

            enum class Visibility {
                BASIC = 0,
                INTERMEDIATE = 1,
                EXPERT = 2,
                DEVELOPER = 3,
                HIDDEN = 4
            };

            const std::string description;
            const std::vector<std::string> allowedValues;
            const Visibility visibility;

            SoftwareSetting(
                const std::string& key,
                const nullable_string& defaultValue,
                const std::string& description = std::string{ "" },
                const std::vector<std::string> allowedValues = {},
                Visibility visibility = Visibility::BASIC
            ) : Setting(key, defaultValue, SettingSource::YW_DEFAULTS, NO_RESOURCE), 
                description(description), allowedValues(allowedValues), visibility(visibility)
            {}
        };

        class Configuration {
            std::map<std::string, Setting> settings;
        public:
            Configuration() {}
            bool contains(const std::string& key);
            const Setting& getSetting(const std::string& key);
            int getIntValue(const std::string& key);
            double getDoubleValue(const std::string& key);
            size_t getSizeValue(const std::string& key);
            std::string getStringValue(const std::string& key);
            void insert(const Setting& setting);
            void insertAll(const Configuration& settings);
            size_t size() { return settings.size(); }
        };
    }
}
