#include<stdio.h> 
#include<stdlib.h>
#include<iostream>

#include "dataContainer.h"
#include"userInputCLI.h"
#include<string>
using namespace std;


int main() {
  
  std::cout << "This program was developed by Worcester Polytechnic Institute's Surface Metrology Lab.\nFor more information, please visit https://www.surfacemetrology.org/ and https://wp.wpi.edu/surfacemetrology/.\nThis software is distributed under the GPL-3.0 License.\n";

  // UserInput cli;
  // // point pointArray[] = {{0,0},{1,1},{2,0}};
  // // DataContainer data = DataContainer();
  // // data.setPointArray(pointArray, 3);
  // // CurvatureScale *curv = data.getIndex(0);
  // // curv->setScale(0.5);
  string message = "Please enter a string";
  string userInput = cliInput::getString(message);
  double userDouble = cliInput::getDouble("please enter a double");
  cout << userInput << endl;
  cout << "This is a double " << userDouble << endl;

}
 
