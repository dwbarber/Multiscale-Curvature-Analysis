#include "analysis.h"
#include "formula.cpp"
#include "datacontainer.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <stdexcept>

void analysis::singleAnalysis(UserInput& uInput, DataContainer& data, double (*method)(point,point,point), int minScale, int maxScale){
    //inputs: data, pointer to desired analysis method

    std::cout << "Single Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int numPoints = data.getPointArrayLength();
    int minScale = uInput.getMinScale();
    int maxScale = uInput.getMaxScale();

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            // Call the function on the points
            curvature = method( data.getPoint(point - scale), data.getPoint(point), data.getPoint(point + scale)); 

            data.putData(scale, point, curvature); //add curvature to data
        }
    }
}

void analysis::hybridAnalysis(UserInput& uInput, DataContainer& data, double (*method1)(point,point,point), double (*method2)(point,point,point), int numPoints, int minScale, int maxScale){

    std::cout << "Hybrid Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;
    int numPoints = data.getPointArrayLength();
    int minScale = uInput.getMinScale();
    int maxScale = uInput.getMaxScale();
    
    //determine if points are acute

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            //determine weather points are acute or not
            bool acute = Formula.isAcute(getPoint(point-scale),getPoint(point), getPoint(point+scale));

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
