#include "setting.h"
#include "yw_text.h"
#include <iomanip>

namespace yw {
    namespace config {

        const std::string Setting::NO_RESOURCE = "yw::config::Setting::NO_RESOURCE";
        const Setting Setting::NO_SETTING = Setting{ "", "" };

        Setting::Setting(
            const std::string& key,
            const nullable_string& valueText,
            const SettingSource source,
            const std::string& resource
        ) :key(yw::tolower(key)),
            valueText(valueText),
            source(source), resource(resource),
            description(""), allowedValues({}), visibility(Visibility::BASIC)
        {
            if (valueText.hasValue()) {
                valueVector = std::vector<std::string>{ valueText.getValue() };
            }
        }

        Setting::Setting(
            const std::string& key,
            const nullable_string& valueText,
            const std::vector<std::string> valueVector,
            const SettingSource source,
            const std::string& resource
        ) : key(yw::tolower(key)),
            valueText(valueText),
            source(source), resource(resource),
            description(""), allowedValues({}), visibility(Visibility::BASIC),
            valueVector{ valueVector }
        {   }

        Setting::Setting(
            const std::string& key,
            const nullable_string& defaultValue,
            const std::string& description,
            const std::vector<std::string> allowed,
            Visibility visibility
        ) : key(yw::tolower(key)), valueText(defaultValue), source(SettingSource::YW_DEFAULTS),
            resource(NO_RESOURCE), description(description),
            visibility(visibility)
        {
            for (auto value : allowed) {
                allowedValues.push_back(yw::toupper(value));
            }

            if (allowedValues.size() > 0 && defaultValue.hasValue()) {
                auto assignedDefault = yw::toupper(defaultValue.getValue());
                for (size_t i = 0; i < allowedValues.size(); ++i) {
                    if (allowedValues[i] == assignedDefault) {
                        defaultIndex = i;
                        break;
                    }
                }
                if (defaultIndex == std::numeric_limits<size_t>::max()) {
                    throw std::runtime_error(
                        "Default value of " + assignedDefault + " " +
                        "is not of the allowed values: " + allowedValuesStr() + ".");
                }
            }
        }

        std::string Setting::allowedValueStr(size_t index) const {
            if (index == defaultIndex) {
                return allowedValues[index] + "*";
            } else {
                return allowedValues[index];
            }
        }

        std::string Setting::allowedValuesStr() const {

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

        std::string Setting::str(size_t nameColumnWidth) const {
            std::stringstream ss;
            if (description.length() == 0 && allowedValues.size() == 0) {
                ss << key;
            }
            else {
                ss << std::left << std::setw(nameColumnWidth) << key << std::setw(0) << description;
                auto avs = allowedValuesStr();
                if (avs.length() > 0) {
                    ss << " (" << allowedValuesStr() << ")";
                }
            }
            return ss.str();
        }
    }
}
