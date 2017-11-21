#pragma once

#include "nullable.h"

#include <limits>
#include <map>
#include <vector>

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

            enum class Visibility {
                BASIC = 0,
                INTERMEDIATE = 1,
                EXPERT = 2,
                DEVELOPER = 3,
                HIDDEN = 4
            };

            const std::string key;
            const nullable_string valueText;
            const SettingSource source;
            const std::string resource;
            const std::string description;
            const Visibility visibility;

            Setting(
                const std::string& key,
                const nullable_string& valueText = null_string,
                const SettingSource source = SettingSource::UNSPECIFIED,
                const std::string& resource = NO_RESOURCE
            );

            Setting(
                const std::string& key,
                const nullable_string& valueText,
                const std::vector<std::string> valueVector,
                const SettingSource source = SettingSource::UNSPECIFIED,
                const std::string& resource = NO_RESOURCE
            );

            Setting(
                const std::string& key,
                const nullable_string& defaultValueText,
                const std::string& description,
                const std::vector<std::string> allowedValues = {},
                Visibility visibility = Visibility::BASIC
            );

            const std::vector<std::string> getValueVector() const { return valueVector; }
            std::string allowedValueStr(size_t index) const;
            std::string allowedValuesStr() const;
            std::string str(size_t nameColumnWidth = 27) const;

            static const Setting NO_SETTING;
            static const std::string NO_RESOURCE;

        private:

            std::vector<std::string> allowedValues;
            std::vector<std::string> valueVector;
            size_t defaultIndex{ std::numeric_limits<size_t>::max() };
        };
    }
}
