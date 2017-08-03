
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
inline path_struct temp_directory_path() { return path_struct{ "/tmp/" }; }
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
