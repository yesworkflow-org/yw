#include "yw_config.h"
#include <iomanip>

namespace yw {
    namespace config {

        const std::string Setting::NO_RESOURCE = "yw::config::Setting::NO_RESOURCE";
        const Setting Setting::NO_SETTING = Setting{ "", "" };

        void Configuration::insert(const Setting& setting) {
            auto it = settings.find(setting.key);
            if (it == settings.end()) {
                settings.emplace(setting.key, setting);
            }
            else {
                auto priorityOfCurrentSetting = it->second.source;
                auto priorityOfNewSetting = setting.source;
                if (priorityOfNewSetting >= priorityOfCurrentSetting) {
                    settings.erase(setting.key);
                    settings.emplace(setting.key, setting);
                }
            }
        }

        void Configuration::insertAll(const Configuration& other) {
            for (auto setting : other.settings) {
                insert(setting.second);
            }
        }

        bool Configuration::contains(const std::string& key) {
            return settings.find(key) != settings.end();
        }

        const Setting& Configuration::getSetting(const std::string& key) {
            auto it = settings.find(key);
            if (it != settings.end()) {
                return it->second;
            }
            else {
                return Setting::NO_SETTING;
            }
        }

        std::string Configuration::getStringValue(const std::string& key) {
            auto setting = getSetting(key);
            if (!setting.value.hasValue()) {
                throw std::domain_error("Option '" + key + "' requires a value.");
            }
            return setting.value.getValue();
        }

        int Configuration::getIntValue(const std::string& key) {
            auto stringValue = getStringValue(key);
            try {
                return std::stoi(stringValue);
            }
            catch (std::exception e) {
                throw std::domain_error(
                    "Value '" + stringValue + "' assigned to option '" + key + 
                    "' cannot be converted to an integer."
                );
            }
        }

        double Configuration::getDoubleValue(const std::string& key) {
            auto stringValue = getStringValue(key);
            try {
                return std::stod(stringValue);
            }
            catch (std::exception e) {
                throw std::domain_error(
                    "Value '" + stringValue + "' assigned to option '" + key +
                    "' cannot be converted to a double."
                );
            }
        }

        size_t Configuration::getSizeValue(const std::string& key) {
            int intValue = getIntValue(key);
            if (intValue < 0) {
                std::stringstream message;
                message << "Invalid value '" << intValue
                        << "' assigned to option '" << key << "'. "
                        << "Value may not be negative.";
                throw std::domain_error(message.str());
            }
            return static_cast<size_t>(intValue);
        }

        std::string Configuration::str(Setting::Visibility settingVisibility) {

            std::stringstream help;

            for (auto settingEntry : settings) {
                auto setting = settingEntry.second;
                if (setting.visibility <= settingVisibility) {
                    help << std::left << std::setw(27) << setting.key;
                    help << std::setw(40) << setting.description << std::endl;
                    //help << setting.value.str() << std::endl;
                }
            }

            return help.str();
        }
    }
}
