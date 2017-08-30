
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#ifdef USING_STD_FILESYSTEM
#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;
#endif

namespace yw {

    #ifndef USING_STD_FILESYSTEM
    
        struct path_struct {
            std::string path;
            std::string string() { return path; }
            path_struct append(std::string suffix) { path += suffix; return *this; }
        };
    
        inline path_struct temp_directory_path() { return path_struct{ std::string{getenv("TEMP")} +"/" }; }

    #endif

    inline std::string writeTempFile(std::string fileName, std::string sourceText) {
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

    inline std::string wchar2string(const wchar_t * w_message) {
        if (w_message == nullptr) {
            return std::string("");
        } else {
            size_t newsize = (wcslen(w_message) + 1) * 2;
            char* c_message = new char[newsize];
            wcstombs(c_message, w_message, newsize);
            std::string s(c_message);
            delete[] c_message;
            return s;
        }
    }

    inline std::string getFileName(std::string filePath) {
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
}