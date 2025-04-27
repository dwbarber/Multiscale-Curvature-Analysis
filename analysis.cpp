#include "analysis.h"
#include "formula.h"
#include "dataContainer.h"
#include "userData.h" // Add this line to include the definition of UserData
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <stdexcept>

void analysis::singleAnalysis(UserData* uData, DataContainer* data, double (*method)(point*,point*,point*), int numPoints){
    //inputs: data, pointer to desired analysis method

    std::cout << "Single Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int minScale = uData->getMinScale();
    int maxScale = uData->getMaxScale();

    // Parallelize the outer loop for better performance
    #pragma omp parallel for private(curvature) schedule(dynamic)
    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            // Call the function on the points
            curvature = method( data->getPointAddress(point - scale), data->getPointAddress(point), data->getPointAddress(point + scale)); 
            // Store the result in the data container
            data->putCurvature(scale - minScale, point-scale, curvature); //add curvature to data
        }
    }
}

void analysis::hybridAnalysis(UserData* uData, DataContainer* data, double (*method1)(point*,point*,point*), double (*method2)(point*,point*,point*), int numPoints){

    std::cout << "Hybrid Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int minScale = uData->getMinScale();
    int maxScale = uData->getMaxScale();
    
    //determine if points are acute
    #pragma omp parallel for private(curvature) schedule(dynamic)
    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            bool acute = Formula::isAcute(data->getPointAddress(point-scale), data->getPointAddress(point), data->getPointAddress(point+scale));
            

            // Call the function on the points(point *point1, point *point2, point *point3);
            if(acute){
                curvature = method1( data->getPointAddress(point - scale), data->getPointAddress(point), data->getPointAddress(point + scale)); 
            }
            else{
                curvature = method2( data->getPointAddress(point - scale), data->getPointAddress(point), data->getPointAddress(point + scale)); 
            }

            data->putCurvature(scale-minScale, point-scale, curvature); //add curvature to data
        }
    }
}


void analysis::percentError(UserData* uData, DataContainer* data,int numPoints){

    std::cout << "Percent Error" << std::endl;
        
    //populate cuvatureScaleArray
    double percentError;
    int minScale = uData->getMinScale();
    int maxScale = uData->getMaxScale();
    
    #pragma omp parallel for 

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            //determine percent Error:
            float percentError = 0;//FLAG: Change to formula

            data->putPE(scale-minScale, point-scale, percentError); //add curvature to data
        }
    }
}

