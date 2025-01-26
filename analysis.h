#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "dataContainer.h"

//extension of dataContainer class to include analysis functions
class analysis{
    public:
        void singleAnalysis(int numPoints, int minScale, int maxScale, point pointArray[], curvatureScale cuvatureScaleArray[]);
        void hybridAnalysis();
};

#endif
