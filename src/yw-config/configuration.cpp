#include "configuration.h"
#include "yw_config_parser_builder.h"
#include "yw_text.h"
#include <iomanip>
#include <string>

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
                auto valueText = setting->settingValue()->unquotedValue()->getText();

                std::vector<std::string> valueVector{};
                for (auto wordContext : setting->settingValue()->unquotedValue()->word()) {
                    valueVector.push_back(wordContext->getText());
                }

                auto s = Setting{ key, valueText, valueVector, source };
                insert(s);

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
            insertSettingsFromText(configurationText.str(), source);
        }

        void Configuration::insert(const Setting& newSetting) {
            auto oldSettingEntry = settings.find(newSetting.key);
            if (oldSettingEntry == settings.end()) {
                settings.emplace(newSetting.key, newSetting);
            }
            else {
                Setting& oldSetting = oldSettingEntry->second;
                if (newSetting.source >= oldSetting.source) {
                    auto newSettingValue = yw::toupper(newSetting.valueText.getValue());
                    if (oldSetting.isAllowedValue(newSettingValue)) {
                        auto updatedSetting = oldSetting.getUpdatedSetting(newSetting);
                        settings.erase(oldSetting.key);
                        settings.emplace(newSetting.key, updatedSetting);
                    }
                    else {
                        throw std::domain_error(
                            "Setting value " + newSettingValue + " " + 
                            "is not one of the allowed values (" + oldSetting.allowedValuesStr() + ") " +
                            "for setting '" + newSetting.key + "'."
                        );
                    }
                }
            }
        }

        void Configuration::insertAll(const Configuration& other) {
            for (auto setting : other.settings) {
                insert(setting.second);
            }
        }

        bool Configuration::contains(const std::string& key) {
            return settings.find(yw::tolower(key)) != settings.end();
        }

        const Setting& Configuration::getSetting(const std::string& key) {
            auto it = settings.find(yw::tolower(key));
            if (it != settings.end()) {
                return it->second;
            }
            else {
                return Setting::NO_SETTING;
            }
        }

        std::string Configuration::getValueText(const std::string& key) {
            auto setting = getSetting(key);
            if (!setting.valueText.hasValue()) {
                throw std::domain_error("Option '" + key + "' requires a value.");
            }
            return setting.valueText.getValue();
        }

        std::vector<std::string> Configuration::getValueVector(const std::string& key) {
            return getSetting(key).getValueVector();
            //std::vector<std::string> items;
            //auto setting = getSetting(key);
            //if (setting.valueText.hasValue()) {
            //    std::istringstream ss(setting.valueText.getValue());
            //    std::string item;
            //    while (std::getline(ss, item, ' ')) {
            //        items.push_back(item);
            //    }         
            //}
            //return items;
        }

        int Configuration::getIntValue(const std::string& key) {
            auto stringValue = getValueText(key);
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
            auto stringValue = getValueText(key);
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

        std::string Configuration::help(Setting::Visibility settingVisibility) {

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
