#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"
#include "userInputCLI.h"
#include "userData.h"


//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(UserData& uData, DataContainer& data, double (*method)(point,point,point), int numpoints);
        void hybridAnalysis(UserData& uData, DataContainer& data, double (*method1)(double, double, double, double, double, double), double (*method2)(double, double, double, double, double, double), int numPoints);
};

#endif
