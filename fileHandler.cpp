#include "fileHandler.h"
#include "dataContainer.h"
#include <fstream>
#include <string>

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    std::ifstream file("PCSVsin.csv"); // Open file
    
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    //std::vector<std::vector<double>> data; // Store the CSV values
    std::string line;
    int ArraySize = 0;
    int ite = 0;

    while (std::getline(file, line)) { // Read line by line
        ArraySize++;
    }

    point* pointArray = new point[ArraySize];

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string x_str, z_str;
        
        // Read the two values separated by a comma
        if (std::getline(ss, x_str, ',') && std::getline(ss, z_str, ',')) {
            pointArray[ite].x = std::stod(x_str);
            pointArray[ite].z = std::stod(z_str);
        }
    }

    file.close(); // Close file

    // // Print the extracted data
    // for (const auto& row : data) {
    //     for (double val : row) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}

// point* FileHandler::read(string fileName){
//     ifstream input;
//     if(!input.open(fileName)){
//         //throw error maybe?
//     }
//     double xval,zval;
//     vector<point> import;
//     point a;
//     double doubletoignore;//there is unnecessary doubles that are just zero
//     int nameOrorderofpoints;//there are int val inputs to ignore in each line
//     string lastLineBefInput;
//     while(!input.eof()&&(lastLineBefInput.std::find("// X,Y,Z,C,Lock")!=string::npos)){//"// X,Y,Z,C,Lock" is the last line before data
//         getline(input, lastLineBefInput);
//     }
//     while(!input.eof()){
//         input >> nameOrorderofpoints;
//         input >> xval;
//         input >> doubletoignore;
//         input >> zval;
//         input >> doubletoignore;
//         input >> nameOrorderofpoints;
//         a.x=xval;
//         a.z=zval;
//         import.push_back(a);
//     }
//     input.close();
//     point* array=new point[import.size()];//make so array doesnt get deleted after function ends
//     unsigned long long int a= import.size()// add long(s) if number of points possible needs to be bigger
//     unsigned long long int i=0;
//     while(i < a){
//         array[i]= import.at(i);
//         ++i;
//     }
//     return array;
// }