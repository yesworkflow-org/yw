#include "configuration.h"
#include "yw_config_parser_builder.h"
#include <iomanip>

namespace yw {
    namespace config {

        void Configuration::insertSettingsFromText(
            const std::string& text, 
            Setting::SettingSource source
        ) {
            YW_CONFIG_ParserBuilder parser_builder(text + '\n');
            YW_CONFIG_Parser::ConfigFileContext* context = parser_builder.parse()->configFile();

            for (auto settingLine : context->settingLine()) {
                auto setting = settingLine->setting();
                auto key = setting->settingName()->getText();
                auto value = setting->settingValue()->unquotedValue()->getText();
                insert(Setting{ key, value, source });
            }
        }

        void Configuration::insertSettingsFromFile(
            const std::string& filePath, 
            Setting::SettingSource source, 
            bool throwIfNoSuchFile
        ) {
            std::ostringstream configurationText;
            std::ifstream configurationFile;
            configurationFile.open(filePath);
            if (!configurationFile.is_open()) {
                if (throwIfNoSuchFile) {
                    throw std::runtime_error("Cannot open configuration file: " + filePath);
                } else {
                    return;
                }
            }
            std::string lineText;
            while (std::getline(configurationFile, lineText)) {
                configurationText << lineText << std::endl;
            }
            insertSettingsFromText(configurationText.str());
        }

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
                    help << setting.str() << std::endl;
                }
            }

            return help.str();
        }
    }
}
