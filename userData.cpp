#include "userData.h"
#include "dataContainer.h"
#include <string>
using namespace std;

    //setters
    int UserData::setScaleBounds(double min, double max){
        //returns 0 if valid, 1 if minscale is invalid, 2 if maxscale is invalid, 3 if both are invalid
        
        
        userMinScale = min;
        userMaxScale = max;
        if(( <= min) && (min <= max)){
            return 0;
        }
        else if()

        int DataContainer::getCurvatureArrayLength() {
            return curvatureArrayLength;
        }

        CurvatureScale* DataContainer::getIndex(int index) {
            return &(curvatureScaleArray[index]);
        }

    }
    bool UserData::setAnalyisType(int method){
        // Assuming analysisType is an integer representation of the method
        // You might need to implement a mapping from string to int
        analysisType = method;
        return true;
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