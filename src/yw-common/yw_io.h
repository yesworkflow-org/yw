#pragma once

#include <string>

#ifdef _MSC_VER
#define USING_STD_FILESYSTEM
#endif

namespace yw {

    std::string getFileName(std::string filePath);
    std::string trimmargins(const std::string& untrimmedText);
    std::string wchar2string(const wchar_t * w_message);
    std::string writeTempFile(std::string fileName, std::string sourceText);

    #ifndef USING_STD_FILESYSTEM
    
        struct path_struct {
            std::string path;
            std::string string() { return path; }
            path_struct append(std::string suffix) { path += suffix; return *this; }
        };
    
        inline path_struct temp_directory_path() { return path_struct{ std::string{getenv("TEMP")} +"/" }; }

    #endif
}