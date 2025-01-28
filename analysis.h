#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"

//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(DataContainer& data, double (*method)(double, double, double, double, double, double), int numPoints, int minScale, int maxScale);
        void hybridAnalysis();
};

#endif
