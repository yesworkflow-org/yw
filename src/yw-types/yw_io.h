
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#if defined(_MSC_VER)
#include <experimental/filesystem>
using namespace std::experimental::filesystem::v1;
#else
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

namespace yw {

    inline std::string wstring2string(const wchar_t * w_message) {
        if (w_message == nullptr) w_message = L"";
        size_t newsize = (wcslen(w_message) + 1) * 2;
        char* c_message = new char[newsize];
        wcstombs_s(nullptr, c_message, newsize, w_message, _TRUNCATE);
        std::string s(c_message);
        delete c_message;
        return s;
    }

    inline std::string getFileName(std::string filePath) {

        #if defined(_MSC_VER)
            path p = filePath;
            return yw::wstring2string(p.filename().c_str());
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