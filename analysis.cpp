#include "analysis.h"
#include "formula.cpp"
#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>
#include <stdexcept>

void analysis::singleAnalysis(DataContainer& data, double (*method)(double, double, double, double, double, double), int numPoints, int minScale, int maxScale){

    std::cout << "Single Analysis" << std::endl;
        
    //populate cuvatureScaleArray
    double curvature;

    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales
        for(int point = scale; point < numPoints - scale; point++){ //iterate over points
            // point is the center point 
            // Call the function on the points
            curvature = method(
                data.getPoint(point - scale).x, data.getPoint(point - scale).z, 
                data.getPoint(point).x, data.getPoint(point).z, 
                data.getPoint(point + scale).x, data.getPoint(point + scale).z ); 

            data.putData(scale, point, curvature); //add curvature to data
        }
    }
}

// //void dataContainer::hybridAnalysis() { //    std::cout << "Hybrid Analysis" << std::endl; // //    // Define a map of method names to corresponding functions //    static const std::unordered_map<std::string, std::function<double(double,double,double,double,double,double)>> functionKey = { //        {"herons", herons}, //        {"parabola", parabola}, //        {"diffslopes", diffOfSlopes}, //        {"lagrangian", lagrangian}, //        {"FDA", finiteDiffAnalysis} //    }; //    //    // Find the corresponding function //    auto it = functionKey.find(method); // //    if(it == functionKey.end()){ //        throw std::invalid_argument("Unknown method: " + method); //    } // //    //populate cuvatureScaleArray //    double curvature; // //    for(int scale = minScale; scale <= maxScale; scale++){ //iterate over scales //        for(int point = scale; point < numPoints - scale; point++){ //iterate over points //            // point is the center point //            // Call the function on the points //            curvature = it->second( //                pointArray[point - scale].x, pointArray[point - scale].z, 
//                pointArray[point].x, pointArray[point].z, 
//                pointArray[point + scale].x, pointArray[point + scale].z ); 
//
//        }
//    }
//}
