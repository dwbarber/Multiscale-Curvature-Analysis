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
    return retVal;
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
    return retVal;
}

bool getYesNo(string message){
    cout << message << " (Yes/No)\n";
    string userInput;
    cin >> userInput;
    if(userInput == "Yes"){
        return true;
    }
    else{
        return false;
    }
}





