#include "dataContainer.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "fileHandler.h"

using namespace std;

FileHandler::FileHandler() {}

// Function is meant to read a CSV file and return an array of points
void FileHandler::fileRead(string input, DataContainer* data) {
    string filePath = remove_quotes(input); // Remove quotes from the input string

    // Check if the file exists
    if (!validPath(filePath)) {
        std::cerr << "Error: File does not exist!" << std::endl;
        return;
    }

    // Check if the file extension is ".csv"
    // PathExtension function is used to make the file type case insensitive
    if (pathExtension(filePath) != ".csv" && pathExtension(filePath) != ".txt" && pathExtension(filePath) != ".x3p") {
        std::cerr << "Error: Invalid file type! Expected a .csv file." << std::endl;
        std::cerr << pathExtension(filePath) << std::endl;
        return;
    }

    std::ifstream file(filePath); // Open file
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;        }
    else{
        // First loop: Count the number of lines
        std::string line;
        int ArraySize = 0;
        while (std::getline(file, line)) {
            ArraySize++;
        }

        // Reset file pointer
        file.clear();               
        file.seekg(0, ios::beg);    

        // Allocate point array
        data->setPointArray(ArraySize);
        
        // Second loop: Read data into array
        int ite = 0;
        
        // Read each line from the file until EOF (end of file) is reached
        while (std::getline(file, line)) {  
            // Create a stringstream object from the line to parse values separately
            std::stringstream ss(line);  
            std::string x_str, z_str;  // Strings to store the extracted x and z values

            // Extract values separated by a comma
            // - Reads the first value (x) into x_str
            // - Reads the second value (z) into z_str
            if (std::getline(ss, x_str, ',') && std::getline(ss, z_str, ',')) {  
                // Convert extracted string values to double and store in pointArray
                data->setPoint(ite, {std::stod(x_str), std::stod(z_str)});
                
                // Increment index to store the next point in the array
                ite++;  
            }
        }

        file.close(); 

        // //Print the points read from the file and file type, use for TESTING
        // std::cout << "File Type: " << pathExtension(filePath) << std::endl;
        // ite = 0;
        // while(ite < ArraySize){
        //     std::cout << "Point " << ite << ": " << pointArray[ite].x << ", " << pointArray[ite].z << std::endl;
        //     ite++;
        // }

        std::cout << "Data was read successfully.\n";
    }
}

// Function is meant to write data to a CSV file
int FileHandler::fileWrite(DataContainer* XSC){
    std::string fileName;

    std::cout << "Enter file Name: ";
    std::cin >> fileName;
    fileName += ".csv";
    std::ofstream myFile(fileName); // Creates or overwrites file

    if (myFile.is_open()) {
        int ScaleSwitching = 0;
        int CurvatureSwitching;
        int BroadArraySize = XSC->getCurvatureArrayLength(); // Length of the Array holding ALL of the Curvature Data
        int CurvatureArraySize; // Length of the Array holding the Curvature Data for a Specific Scale
        myFile << "X-Position" << "," << "Scale" << "," << "Curvature" << std::endl;
        while (ScaleSwitching < BroadArraySize) {
            CurvatureArraySize = XSC->getIndex(ScaleSwitching)->getLength();
            CurvatureSwitching = 0; // Resetting the index for Array of points
            while (CurvatureSwitching < CurvatureArraySize){
                myFile << XSC->getIndex(ScaleSwitching)->getPoint(CurvatureSwitching).x << "," 
                       << XSC->getIndex(ScaleSwitching)->getScale() << "," 
                       << XSC->getIndex(ScaleSwitching)->getCurvature(CurvatureSwitching) << std::endl;
                CurvatureSwitching++; // Changing the index for Array of points
            }
            ScaleSwitching++; // Changing the index for Array of Curvature Data
        }

        myFile.close();
        std::cout << "Data written to file successfully." << std::endl;
    } 
    else {
        std::cerr << "Unable to open file." << std::endl;
        return 1; // Indicate an error
    }

    return 0;
}

//File checking:
// Function to check if a file exists
bool FileHandler::validPath(const std::string& path) {
    return std::filesystem::exists(path);
}

// Function to get file extension
std::string FileHandler::pathExtension(const std::string& path) { 
    if (path.size() < 3) { 
        return std::filesystem::path(path).extension().string();; 
    }

    //std::cout << path << std::endl; // for testing

    string result = path.substr(0, path.size() - 3); 

    result += tolower(path[path.size() - 3]); 
    result += tolower(path[path.size() - 2]); 
    result += tolower(path[path.size() - 1]); 

    //std::cout << result << std::endl; // for testing

    return std::filesystem::path(result).extension().string(); 
}

// Function to read a CSV file and return a vector of doubles
// std::vector<double> readCSV(std::string path){
//     std::ifstream file(path);
//     std::string line;
//     std::vector<double> data;

//     while(std::getline(file, line) ){
//         std::stringstream ss(line);
//         std::string value;
//         while( std::getline(ss, value, ',') ){
//             data.push_back(std::stod(value));
//         }
//     }
// }

// Function to remove quotes from a string
string FileHandler::remove_quotes(const string& input) {
    string result = input;
  
    if (result.size() >= 2 && result[0] == '"' && result[result.size() - 1] == '"') {
        result = result.substr(1, result.size() - 2); 
    }
  
    return result;
}      

//for testing purposes
// int main() {
//     FileHandler fh;
//     fh.fileRead();
//     return 0;
// }