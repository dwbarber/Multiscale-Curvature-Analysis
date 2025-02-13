#include "userData.h"
#include "userInputCLI.h"
#include "fileHandler.h"
int UserData::setScaleBounds(int min, int max) {
    userMinScale = min;
    userMaxScale = max;

    //returns 0 if valid, 1 if minscale is invalid, 2 if maxscale is invalid, 3 if both are invalid
}

bool UserData::setAnalyisType(string method) {
    // Assuming analysisType is an integer representation of the method
    // You might need to implement a mapping from string to int

    //returns true if analysis is valid
}

bool UserData::setHybridSelection(string method1, string method2) {
    // Assuming hybridSelection is an integer representation of the methods
    // You might need to implement a mapping from string to int

    //returns true if HybridSelection
}

bool UserData::setInputFilePath(string path) {
    inputFilepath = path;

    //returns true if file is valid


}

int UserData::getMinScale() {
    return userMinScale;
}

int UserData::getMaxScale() {
    return userMaxScale;
}

string UserData::getAnalysisType() {
    // Assuming analysisType is an integer representation of the method
    // You might need to implement a mapping from int to string
    return "";
}

bool UserData::getHybrid() {
    return hybrid;
}

int UserData::getHybridSelection(int index) {
    if (index >= 0 && index < 2) {
        return hybridSelection[index];
    }
    return -1; // or some error value
}

bool UserData::getLogScale() {
    return logScale;
}

void UserData::setLogScale(bool logScale) {
    this->logScale = logScale;
}
