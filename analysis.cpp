#include "analysis.h"
#include "formula.h"
#include "dataContainer.h"
#include "userData.h" // Add this line to include the definition of UserData
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <stdexcept>

void analysis::singleAnalysis(UserData& uData, DataContainer& data, double (*method)(point,point,point), int numPoints){
    //inputs: data, pointer to desired analysis method

    std::cout << "Single Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int minScale = uData.getMinScale();
    int maxScale = uData.getMaxScale();

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            // Call the function on the points
            curvature = method( data.getPoint(point - scale), data.getPoint(point), data.getPoint(point + scale)); 

            data.putData(scale, point, curvature); //add curvature to data
        }
    }
}

void analysis::hybridAnalysis(UserData& uData, DataContainer& data, double (*method1)(double, double, double, double, double, double), double (*method2)(double, double, double, double, double, double), int numPoints){

    std::cout << "Hybrid Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int minScale = uData.getMinScale();
    int maxScale = uData.getMaxScale();
    
    //determine if points are acute

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            bool acute = isAcute(data.getPoint(point-scale), data.getPoint(point), data.getPoint(point+scale));
            

            // Call the function on the points
            if(acute){
                curvature = method1( data.getPoint(point - scale), data.getPoint(point), data.getPoint(point + scale)); 

            }
            else{
                curvature = method2( data.getPoint(point - scale), data.getPoint(point), data.getPoint(point + scale)); 

            }

            data.putData(scale, point, curvature); //add curvature to data
        }
    }
}
