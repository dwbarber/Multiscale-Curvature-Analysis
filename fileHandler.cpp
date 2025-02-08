#include "dataContainer.h"
#include "pathCheck.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class FileHandler {
    public:

// Function is meant to read a CSV file and return an array of points
    point* fileRead() {
        std::string filePath;
        std::cout << "Enter the absolute file path: ";
        std::getline(std::cin, filePath);

        // Check if the file exists
        if (!validPath(filePath)) {
            std::cerr << "Error: File does not exist!" << std::endl;
            point* error = new point[1];
            error[0].x = -1;
            error[0].z = -1;
            return error;
        }

        // Check if the file extension is ".csv"
        if (pathExtension(filePath) != ".csv") {
            std::cerr << "Error: Invalid file type! Expected a .csv file." << std::endl;
            std::cerr << pathExtension(filePath) << std::endl;
            point* error = new point[1];
            error[0].x = -1;
            error[0].z = -1;
            return error;
        }

        std::ifstream file(filePath); // Open file
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            point* error = new point[1];
            error[0].x = -1;
            error[0].z = -1;
            return error;
        }

        // First loop: Count the number of lines
        std::string line;
        int ArraySize = 0;
        while (std::getline(file, line)) {
            ArraySize++;
        }

        // Reset file pointer
        file.clear();               
        file.seekg(0, ios::beg);    

        // Allocate dynamic array
        point* pointArray = new point[ArraySize];

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
                pointArray[ite].x = std::stod(x_str);  
                pointArray[ite].z = std::stod(z_str);
                
                // Increment index to store the next point in the array
                ite++;  
            }
        }

        file.close(); 

        ite = 0;
        while(ite < ArraySize){
            std::cout << "Point " << ite << ": " << pointArray[ite].x << ", " << pointArray[ite].z << std::endl;
            ite++;
        }

        std::cout << "Data was read successfully.\n";
        return pointArray;
    }

// Function is meant to write data to a CSV file
    int fileWrite(DataContainer& XSC){
        std::string fileName;
    
        std::cout << "Enter file Name: ";
        std::cin >> fileName;
        fileName += ".csv";
        std::ofstream myFile(fileName); // Creates or overwrites example.txt
    
        if (myFile.is_open()) {
            int ScaleSwitching = 0;
            int CurvatureSwitching;
            int BroadArraySize = XSC.getCurvatureArrayLength(); // Length of the Array holding ALL of the Curvature Data
            int CurvatureArraySize; // Length of the Array holding the Curvature Data for a Specific Scale
            myFile << "X-Position" << "," << "Scale" << "," << "Curvature" << std::endl;
            while (ScaleSwitching < BroadArraySize) {
                CurvatureArraySize = XSC.getIndex(ScaleSwitching)->getLength();
                CurvatureSwitching = 0; // Resetting the index for Array of points
                while (CurvatureSwitching < CurvatureArraySize){
                    myFile << XSC.getIndex(ScaleSwitching)->getPoint(CurvatureSwitching).x << "," 
                           << XSC.getIndex(ScaleSwitching)->getScale() << "," 
                           << XSC.getIndex(ScaleSwitching)->getCurvature(CurvatureSwitching) << std::endl;
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
};

// int main() {
//     FileHandler fh;
//     fh.fileRead();
//     return 0;
// }