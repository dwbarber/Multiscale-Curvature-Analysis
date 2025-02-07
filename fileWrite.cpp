#include "dataContainer.h"
#include <iostream>
#include <fstream>
#include <string>

int fileWrite(DataContainer& XSC){
    int ite = 0;
    std::string fileName;

    std::cout << "Enter file Name: ";
    std::cin >> fileName;
    fileName += ".csv";
    std::ofstream myFile(fileName); // Creates or overwrites example.txt

    if (myFile.is_open()) {
         myFile << "X-Position" << "," << "Scale" << "," << "Curvature" << std::endl;
        while (ite < sizeof(XSC)/sizeof(XSC[0])) {
            myFile << ite << "," << XSC[ite] << "," << (ite + 1) << std::endl;
            ite++;
        }
        
        // std::string name = "John Doe";
        // int age = 30;
        // myFile << "Name: " << name << ", Age: " << age << std::endl;

        myFile.close();
        std::cout << "Data written to file successfully." << std::endl;
    } 
    else {
        std::cerr << "Unable to open file." << std::endl;
        return 1; // Indicate an error
    }

    return 0;
}