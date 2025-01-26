#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"

//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(int *method, int numPoints, int minScale, int maxScale, point pointArray[], CurvatureScale cuvatureScaleArray[]);
        void hybridAnalysis();
};

#endif
