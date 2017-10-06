#include "setting.h"
#include <iomanip>

namespace yw {
    namespace config {

        const std::string Setting::NO_RESOURCE = "yw::config::Setting::NO_RESOURCE";
        const Setting Setting::NO_SETTING = Setting{ "", "" };

        Setting::Setting(
            const std::string& key,
            const nullable_string& defaultValue,
            const std::string& description,
            const std::vector<std::string> allowedValues,
            Visibility visibility
        ) : key(key), value(defaultValue), source(SettingSource::YW_DEFAULTS),
            resource(NO_RESOURCE), description(description),
            allowedValues(allowedValues), visibility(visibility)
        {
            if (defaultValue.hasValue()) {
                for (int i = 0; i < allowedValues.size(); ++i) {
                    if (allowedValues[i] == defaultValue.getValue()) {
                        defaultIndex = i;
                        break;
                    }
                }
            }
        }

        std::string Setting::allowedValueStr(size_t index) {
            if (index == defaultIndex) {
                return allowedValues[index] + "*";
            } else {
                return allowedValues[index];
            }
        }

        std::string Setting::allowedValuesStr() {

            std::stringstream ss;

            auto count = allowedValues.size();
            switch (count) {

            case 0: 
                break;

            case 1:
                ss << allowedValueStr(0); 
                break;

            case 2:
                ss << allowedValueStr(0) << " or " << allowedValueStr(1);
                break;

            default:
                size_t i;
                for (i = 0; i < count - 1; ++i) {
                    ss << allowedValueStr(i) << ", ";
                }
                ss << "or " << allowedValueStr(i);
            }

            return ss.str();
        }

        std::string Setting::str() {
            std::stringstream ss;
            ss << std::left << std::setw(27) << key << std::setw(0) << description;
            auto avs = allowedValuesStr();
            if (avs.length() > 0) {
                ss << " (" << allowedValuesStr() << ")";
            }
            return ss.str();
        }
    }
}
