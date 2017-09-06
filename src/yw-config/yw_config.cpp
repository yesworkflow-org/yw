#include "yw_config.h"

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

        const Setting& Configuration::get(const std::string& key) {
            auto it = settings.find(key);
            if (it != settings.end()) {
                return it->second;
            }
            else {
                return Setting::NO_SETTING;
            }
        }
    }
}
