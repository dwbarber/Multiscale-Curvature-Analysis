#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"

//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(userInputCLI& userInput ,DataContainer& data, double (*method)(double, double, double, double, double, double), int numPoints);
        void analysis::hybridAnalysis(userInputCLI& userInput, DataContainer& data, double (*method1)(double, double, double, double, double, double), double (*method2)(double, double, double, double, double, double), int numPoints);
        void hybridAnalysis();
};

#endif
