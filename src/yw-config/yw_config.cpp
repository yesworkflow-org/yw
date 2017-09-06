#include "yw_config.h"

namespace yw {
    namespace config {

        void YWConfiguration::insert(const YWConfiguration::Setting& setting) {
            settings.emplace(setting.name, setting);
        }
    }
}
