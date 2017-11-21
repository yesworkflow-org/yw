#include "yw_io.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <functional> 
#include <iostream>
#include <locale>
#include <sstream>

#ifdef USING_STD_FILESYSTEM
#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;
#endif

namespace yw {

    std::string writeTempFile(std::string fileName, std::string sourceText) {
        auto tempFilePath = temp_directory_path().append(fileName);
        std::ofstream tempFile(tempFilePath.string());
        if (!tempFile.is_open()) {
            throw std::runtime_error("Source loader cannot open source file " + tempFilePath.string());
        }
        std::istringstream sourceStream(sourceText);
        std::string lineText;
        while (std::getline(sourceStream, lineText)) {
            tempFile << lineText << std::endl;
        }
        tempFile.close();
        return tempFilePath.string();
    }

    std::string wchar2string(const wchar_t * w_message) {
        if (w_message == nullptr) {
            return std::string("");
        }
        else {
            size_t newsize = (wcslen(w_message) + 1) * 2;
            char* c_message = new char[newsize];
            wcstombs(c_message, w_message, newsize);
            std::string s(c_message);
            delete[] c_message;
            return s;
        }
    }

    std::string getFileName(std::string filePath) {
        #ifdef USING_STD_FILESYSTEM
            path p = filePath;
            return p.filename().string();
        #else
            auto lastSeparatorPosition = filePath.find_last_of("/\\");
            if (lastSeparatorPosition == std::string::npos) {
                return filePath;
            }
            else {
                return filePath.substr(lastSeparatorPosition + 1);
            }
        #endif
    }

    void trimright(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    }

    std::string ctrimright(std::string s) {
        trimright(s);
        return s;
    }

    std::string trimmargins(const std::string& untrimmedText) {

        std::stringstream trimmed;
        std::istringstream sourceStream{ untrimmedText };
        std::string untrimmedLine;
        size_t leftMargin = std::string::npos;

        while (std::getline(sourceStream, untrimmedLine)) {

            if (leftMargin == std::string::npos) {
                auto firstNonSpace = untrimmedLine.find_first_not_of(" ");
                if (firstNonSpace != std::string::npos) {
                    leftMargin = firstNonSpace;
                    trimmed << ctrimright(untrimmedLine.substr(leftMargin)) << std::endl;
                }
            }
            else {
                if (untrimmedLine.size() < leftMargin) break;
                trimmed << ctrimright(untrimmedLine.substr(leftMargin)) << std::endl;
            }
        }

        return trimmed.str();
    }
}