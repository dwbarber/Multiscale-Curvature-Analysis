#include "userData.h"
#include <string>
using namespace std;
    
    //setters
    int UserData::setScaleBounds(int min, int max){
        userMinScale = min;
        userMaxScale = max;
    }
    bool UserData::setAnalyisType(int method){
        analysisType = method;
    }
    bool UserData::setHybridSelection(int method1, int method2){
        hybridSelection[0] = method1;
        hybridSelection[1] = method2;
    }
    bool UserData::setInputFilePath(string path){
        inputFilepath = path;
    }
#include "userInputCLI.h"
#include "fileHandler.h"
int UserData::setScaleBounds(int min, int max) {
    userMinScale = min;
    userMaxScale = max;


    //returns 0 if valid, 1 if minscale is invalid, 2 if maxscale is invalid, 3 if both are invalid
}

bool UserData::setAnalyisType(int method) {
    // Assuming analysisType is an integer representation of the method
    // You might need to implement a mapping from string to int

    //returns true if analysis is valid
}

bool UserData::setHybridSelection(int obtusemethod, int acutemethod) {
    // Assuming hybridSelection is an integer representation of the methods
    // You might need to implement a mapping from string to int

    //returns true if HybridSelection is valid
}

bool UserData::setInputFilePath(string path) {
    inputFilepath = path;

    //returns true if file is valid


}

    //getters
    int UserData::getMinScale(){
        return userMinScale;
    }
    int UserData::getMaxScale(){
        return userMaxScale;
    }
    int UserData::getAnalysisType(){
        return analysisType;
    }
    bool UserData::getHybrid(){
        return hybrid;
    }
    int UserData::getHybridSelection(int index){
        return hybridSelection[index];
    }
    bool UserData::getLogScale(){
        return logScale;
    }
    void UserData::setLogScale(bool logScale){
        UserData::logScale = logScale;
    }