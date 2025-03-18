#include<stdio.h> 
#include<stdlib.h>
#include<iostream>

#include "dataContainer.h"
#include"userInputCLI.h"
#include<string>
using namespace std;

//testing single execution method
#include "fileHandler.h"
#include "userData.h"
#include "analysis.h"
#include "formula.h"


int main() {
  
  std::cout << "This program was developed by Worcester Polytechnic Institute's Surface Metrology Lab.\nFor more information, please visit https://www.surfacemetrology.org/ and https://wp.wpi.edu/surfacemetrology/.\nThis software is distributed under the GPL-3.0 License.\n";

  //prog flow starts here. create uData and data objects
  UserData uData;
  DataContainer data;


  //get file path, store it into the uData.
  uData.setInputFilePath(cliInput::getString("Please enter the file path"));
  

  //read the file, store the data into the data object.
  FileHandler::fileRead(uData.getInputFilePath(), &data);

  //find the max half interval.
  data.setmaxhalfinterval();


  //print the minimum length and maximum length possible.
  std::cout << "The minimum length is: " << data.getMinLength() << std::endl;
  std::cout << "The maximum length possible is: " << data.getMaxLength() << std::endl;

  //get the minimum and maximum scales from the user.
  int minscale = cliInput::getDouble("Please enter the minimum scale");
  int maxscale = cliInput::getDouble("Please enter the maximum scale");

  //set the scales into the uData object.
  uData.setScaleBounds(minscale, maxscale);

  //create the curvature array according to the minscale and maxscale.
  data.numOps(minscale, maxscale);

  //print the number of operations to be performed.
  std::cout << "The number of operations to be performed is: " << data.getCurvatureArrayLength() << std::endl;

  //standard or hybrid analysis?
  bool analysisType = cliInput::getYesNo("Would you like to perform a hybrid analysis?");
  uData.setIsHybrid(analysisType);

  //if hybrid, which methods?
  if(analysisType){
    int obtuseMethod = cliInput::getInt("Please enter the method for obtuse angles");
    int acuteMethod = cliInput::getInt("Please enter the method for acute angles");
    uData.setHybridSelection(obtuseMethod, acuteMethod);
  }
  else{
    int method = cliInput::getInt("Please enter the method for standard analysis");
    uData.setAnalyisType(method);
  }

  //set variables for function pointers
  //create the map variable (use auto to make life easy)
  auto functionMapping = Formula::funcMap();

 
  //confirm user input to start analysis.
  bool confirm = cliInput::getYesNo("Would you like to start the analysis?");
  if (confirm){
  
    //start the analysis
    if(uData.getHybrid()){
      //if hybrid, declare *method2
      int methodKey1 = uData.getHybridSelection(0);
      int methodKey2 = uData.getHybridSelection(1);
      if (functionMapping.find(methodKey1) == functionMapping.end()) {
        std::cerr << "Error: Method " << methodKey1 << " not found in function mapping." << std::endl;  
      }
      if (functionMapping.find(methodKey2) == functionMapping.end()) {
        std::cerr << "Error: Method " << methodKey2 << " not found in function mapping." << std::endl;  
      }
      double (*method1)(point*,point*,point*) = functionMapping[methodKey1];
      double (*method2)(point*,point*,point*) = functionMapping[methodKey2];
      analysis::hybridAnalysis(&uData, &data, method1, method2, data.getPointArrayLength());
      
      
    }
    else{
      int methodKey1 = uData.getAnalysisType();
      if (functionMapping.find(methodKey1) == functionMapping.end()) {
        std::cerr << "Error: Method " << methodKey1 << " not found in function mapping." << std::endl;  
      }
      double (*method1)(point*,point*,point*) = functionMapping[methodKey1];
      analysis::singleAnalysis(&uData, &data, method1, data.getPointArrayLength());
    }
  }
  else{
    std::cout << "Analysis aborted" << std::endl;
  }
  
  

  // UserInput cli;
  // // point pointArray[] = {{0,0},{1,1},{2,0}};
  // // DataContainer data = DataContainer();
  // // data.setPointArray(pointArray, 3);
  // // CurvatureScale *curv = data.getIndex(0);
  // // curv->setScale(0.5);
  
}
 
