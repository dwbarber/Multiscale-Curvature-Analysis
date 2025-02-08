#include "dataContainer.h"
#include <iostream>
#include <fstream>
#include <string>

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