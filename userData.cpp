#include "userData.h"
#include <string>
using namespace std;
    
    //setters
    void UserData::setScaleBounds(int min, int max){
        userMinScale = min;
        userMaxScale = max;
    }
    void UserData::setAnalyisType(int method){
        analysisType = method;
    }
    void UserData::setHybridSelection(int method1, int method2){
        hybridSelection[0] = method1;
        hybridSelection[1] = method2;
    }
    void UserData::setInputFilePath(string path){
        inputFilepath = path;
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