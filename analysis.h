#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"
#include "userInputCLI.h"
#include "userData.h"


//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(UserData& uData, DataContainer& data, double (*method)(point,point,point), int numpoints);
        void hybridAnalysis(UserData& uData, DataContainer& data, double (*method1)(point,point,point), double (*method2)(point,point,point), int numPoints);
};

#endif
