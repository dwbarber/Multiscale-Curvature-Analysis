#include <iostream>
#include <filesystem>

bool validPath(std::string path){
    return std::filesystem::exists(path);
}

