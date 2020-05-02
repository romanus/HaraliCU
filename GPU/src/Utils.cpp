#include "Utils.h"

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void Utils::create_directories(std::string folderPath){
    try
    {
        fs::create_directories(folderPath);
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        std::exit(1);
    }
}

// Removing the path and keeping filename+extension
std::string Utils::stem(const std::string& pathname){
    const auto pathName = fs::path{ pathname };
    return pathName.stem().string();
}

std::vector<std::string> Utils::directory_iterator(const std::string& folderPath)
{
    const auto folder = fs::path{ folderPath };
    if (!fs::is_directory(folder))
    {
        std::cerr << "Folder is not valid: " << folderPath << std::endl;
        std::exit(1);
    }
    if (!fs::exists(folder))
    {
        std::cerr << "Folder doesn't exist: " << folderPath << std::endl;
        std::exit(1);
    }

    auto imagePaths = std::vector<std::string>{};
    for (const auto& pathIter : fs::directory_iterator(folder))
    {
        imagePaths.emplace_back(pathIter.path().string());
    }

    return imagePaths;
}