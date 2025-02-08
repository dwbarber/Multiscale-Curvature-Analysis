#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "datacontainer.h"
#include <map>

using namespace std;

bool validPath(std::string path){
    return std::filesystem::exists(path);
}



void functionA(){};
void functionB(){};

const std::map<std::string, void(*)()> dataTypes = {
    {".csv", &functionA},
    {".txt", &functionB}
};

std::string pathExtension(std::string path){
    return std::filesystem::path(path).extension().string();
}


template <typename T, size_t N>
std::array<point,N> readAny(std::array<T, N> arr, string path){
    if !(validPath(path)){
        throw std::invalid_argument("Invalid Path");
    }
    //path is now valid
    void (*function)() = dataTypes[pathExtension(path)];
    outputarray = new std::array<point,N>;
    outputarray = function(arr, path);
};


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




