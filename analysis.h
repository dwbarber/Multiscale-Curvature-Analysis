#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"

//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(DataContainer& data, double (*method)(double, double, double, double, double, double), int numPoints, int minScale, int maxScale);
        void analysis::hybridAnalysis(DataContainer& data, double (*method1)(double, double, double, double, double, double), double (*method2)(double, double, double, double, double, double), int numPoints, int minScale, int maxScale);
        void hybridAnalysis();
};

#endif
