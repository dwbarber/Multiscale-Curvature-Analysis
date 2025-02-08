#include "dataContainer.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class FileHandler {
    public:

// Function is meant to read a CSV file and return an array of points
    point* fileRead() {
        std::ifstream file("PCSVsin.csv"); // Open file
        
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            point* error = new point[1];
            error[0].x = -1;
            error[0].z = -1;
            return error;
        }
        else{
            // First loop: Count the number of lines
            std::string line;
            int ArraySize = 0;
            
            while (std::getline(file, line)) {
                ArraySize++;
            }

            // Reset file pointer
            file.clear();               // Clear any error flags
            file.seekg(0, ios::beg);    // Move pointer to the beginning of the file

            // Allocate dynamic array
            point* pointArray = new point[ArraySize];

            // Second loop: Read data into array
            int ite = 0;
            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::string x_str, z_str;
                
                // Read the two values separated by a comma
                if (std::getline(ss, x_str, ',') && std::getline(ss, z_str, ',')) {
                    pointArray[ite].x = std::stod(x_str);
                    pointArray[ite].z = std::stod(z_str);
                    ite++;  // Increment index
                }
            }
            file.close(); // Close file

            std::cout << "Data was read successfully.\n";

            // for testing purposes
            // // Print the extracted data
            // for (int i = 0; i < ArraySize; i++) {
            //     std::cout << "X: " << pointArray[i].x << ", Z: " << pointArray[i].z << std::endl;
            // }

            return pointArray;
        }
    }

// Function is meant to write data to a CSV file
    int fileWrite(DataContainer& XSC){
        int ScaleSwitching = 0;
        int CurvatureSwitching = 0;
        std::string fileName;
    
        std::cout << "Enter file Name: ";
        std::cin >> fileName;
        fileName += ".csv";
        std::ofstream myFile(fileName); // Creates or overwrites example.txt
    
        if (myFile.is_open()) {
            int BroadArraySize = XSC.getCurvatureArrayLength(); // Length of the Array holding ALL of the Curvature Data
            int CurvatureArraySize; // Length of the Array holding the Curvature Data for a Specific Scale
            myFile << "X-Position" << "," << "Scale" << "," << "Curvature" << std::endl;
            while (ScaleSwitching < BroadArraySize) {
                CurvatureArraySize = XSC.getIndex(ScaleSwitching)->getLength();
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