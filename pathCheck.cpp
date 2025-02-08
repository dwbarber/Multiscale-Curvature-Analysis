#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "pathCheck.h"

bool validPath(const std::string& path) {
    return std::filesystem::exists(path);
}

std::string pathExtension(const std::string& path) {
    return std::filesystem::path(path).extension().string();
}

std::vector<double> readCSV(std::string path){
    std::ifstream file(path);
    std::string line;
    std::vector<double> data;

    while(std::getline(file, line) ){
        std::stringstream ss(line);
        std::string value;
        while( std::getline(ss, value, ',') ){
            data.push_back(std::stod(value));
        }
    }
}

