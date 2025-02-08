#ifndef USERINPUTCLI_H
#define USERINPUTCLI_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class UserInput{
    //constructor
    public:
        UserInput();
    public:
        //functions to get data from command line
        string getString(string message);
        int getInt(string message);
        double getDouble(string message);
        bool getYesNo(string message);
};


#endif