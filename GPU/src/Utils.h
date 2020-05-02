#pragma once

#include <string>
#include <vector>

using namespace std;

class Utils {
public:
    // std::filesystem::create_directories
    static void create_directories(std::string folderPath);

    // std::filesystem::path::stem
    static std::string stem(const std::string& pathname);

    // std::filesystem::directory_iterator
    static std::vector<std::string> directory_iterator(const std::string& folderPath);
};
