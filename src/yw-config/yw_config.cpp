#include "yw_config.h"

namespace yw {
    namespace config {

        void Configuration::insert(const Setting& setting) {
            settings.emplace(setting.key, setting);
        }

        bool Configuration::contains(const std::string& key) {
            return settings.find(key) != settings.end();
        }

        const Setting& Configuration::get(const std::string& key) {
            auto it = settings.find(key);
            if (it != settings.end()) {
                return (*it).second;
            }
            else {
                return UNDEFINED;
            }
        }
    }
}
