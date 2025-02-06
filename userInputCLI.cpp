#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


string getString(string message){
    cout << message << "\n";
    string userInput;
    cin >> userInput;
    return userInput;
}

int getInt(string message){
    cout << message << "\n";
    string userInput;
    cin >> userInput;
    int retVal;
    try {
        retVal = stoi(userInput);
    }
    catch (std::exception& e){
        std::cerr << "Integer Input Error" << e.what() << endl;
    }
}

double getDouble(string message){
    cout << message << "\n";
    string userInput;
    cin >> userInput;
    int retVal;
    try {
        retVal = stod(userInput);
    }
    catch (std::exception& e){
        std::cerr << "Double Input Error" << e.what() << endl;
    }
}

bool getYesNo(string message){
    cout << message << "\n";
    string userInput;
    cin >> userInput;

}





