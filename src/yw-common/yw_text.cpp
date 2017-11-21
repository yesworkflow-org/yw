#include "yw_text.h"
#include <algorithm>

namespace yw {

    std::string tolower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    std::string toupper(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    }
}