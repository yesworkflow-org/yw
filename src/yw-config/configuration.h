#pragma once

#include "setting.h"

#include <map>
#include <vector>

namespace yw {
    namespace config {

        class Configuration {

        private:

            std::map<std::string, Setting> settings;
        
        public:
            
            Configuration() {}
            
            void insertSettingsFromText(
                const std::string& text, 
                Setting::SettingSource source = Setting::SettingSource::UNSPECIFIED
            );

            void insertSettingsFromFile(
                const std::string& filePath,
                Setting::SettingSource source = Setting::SettingSource::UNSPECIFIED,
                bool throwIfNoSuchFile = true
            );

            bool contains(const std::string& key);
            const Setting& getSetting(const std::string& key);
            int getIntValue(const std::string& key);
            double getDoubleValue(const std::string& key);
            size_t getSizeValue(const std::string& key);
            std::string getValueText(const std::string& key);
            std::vector<std::string> getValueVector(const std::string& key);
            void insert(const Setting& setting);
            void insertAll(const Configuration& settings);
            size_t size() { return settings.size(); }
            std::string str(Setting::Visibility minimumVisibility = Setting::Visibility::BASIC);
        };
    }
}
