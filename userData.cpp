#include "userData.h"
#include "dataContainer.h"
#include "userInputCLI.h"
#include "fileHandler.h"
#include <string>
using namespace std;

    //setters

    bool UserData::setDataContainer(DataContainer dataContainer){
        // Assuming dataContainer is a DataContainer object
        // You might need to implement a mapping from string to DataContainer
        UserData::dataContainer = dataContainer;
        return true;
    }
    int UserData::setScaleBounds(double min, double max){
        //returns 0 if valid, 1 if minscale is invalid, 2 if maxscale is invalid, 3 if both are invalid

        int minint = floor(min / getDataContainer().getMinLength());
        int maxint = ceil(max / getDataContainer().getMinLength());
        bool minValid = true;
        bool maxValid = true;

        if(minint < 1){
            minValid = false;
        }
        if(maxint > getDataContainer().getmaxHalfIntervalPossible()){
            maxValid = false;
        }

        if(minValid && maxValid){
            userMinScale = minint;
            userMaxScale = maxint;
            return 0;
        }
        else if(!minValid && !maxValid){
            //cerr << "Both min and max scale are invalid" << endl;
            return 3;
        }
        else if(!minValid){
            //cerr << "Min scale is invalid" << endl;
            return 1;
        }
        else{
            //cerr << "Max scale is invalid" << endl;
            return 2;
        }
    }
    bool UserData::setAnalyisType(int method){
        // Assuming analysisType is an integer representation of the method
        // You might need to implement a mapping from string to int
        analysisType = method;
        return true;
    }
    bool UserData::setHybridSelection(int method1, int method2){
        // Assuming hybridSelection is an integer representation of the methods
        // You might need to implement a mapping from string to int
        hybridSelection[0] = method1;
        hybridSelection[1] = method2;
        return true;
    }
    bool UserData::setInputFilePath(string path){
        //returns true if file is valid        
        inputFilepath = path;
        return true;
    }

    //getters
    string UserData::getInputFilePath(){
        return inputFilepath;
    }
    DataContainer UserData::getDataContainer(){
        return dataContainer;
    }
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