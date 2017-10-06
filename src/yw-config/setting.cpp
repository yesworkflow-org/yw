#include "setting.h"
#include <iomanip>

namespace yw {
    namespace config {

        const std::string Setting::NO_RESOURCE = "yw::config::Setting::NO_RESOURCE";
        const Setting Setting::NO_SETTING = Setting{ "", "" };

        std::string Setting::allowedValuesStr() {

            std::stringstream ss;

            auto count = allowedValues.size();
            switch (count) {

            case 0: 
                break;

            case 1:
                ss << allowedValues[0]; 
                break;

            case 2:
                ss << allowedValues[0] << " or " << allowedValues[1];
                break;

            default:
                size_t i;
                for (i = 0; i < count - 1; ++i) {
                    ss << allowedValues[i] << ", ";
                }
                ss << "or " << allowedValues[i];
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
