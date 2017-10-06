#pragma once

#ifdef _MSC_VER
    #define USING_STD_FILESYSTEM
#endif

#include "nullable.h"
#include "yw_io.h"


inline std::string trimmargins(const std::string& untrimmedText) {

    std::stringstream trimmed;
    std::istringstream sourceStream{ untrimmedText };
    std::string untrimmedLine;
    size_t leftMargin = std::string::npos;

    while (std::getline(sourceStream, untrimmedLine)) {

        if (leftMargin == std::string::npos) {
            auto firstNonSpace = untrimmedLine.find_first_not_of(" ");
            if (firstNonSpace != std::string::npos) {
                leftMargin = firstNonSpace;
                trimmed << untrimmedLine.substr(leftMargin) << std::endl;
            }
        }
        else {
            if (untrimmedLine.size() < leftMargin) break;
            trimmed << untrimmedLine.substr(leftMargin) << std::endl;
        }
    }

    return trimmed.str();
}
