#include "dataContainer.h"

// CurvatureScale functions ---------------------------------------------------------------------------------------------------

CurvatureScale::CurvatureScale(double *curvatureArray, int dataLength, double scale, point *pointArray) {
    CurvatureScale::curvatureArray = new double[dataLength];
    memcpy(CurvatureScale::curvatureArray, curvatureArray, dataLength * sizeof(double));
    CurvatureScale::scale = scale;
    CurvatureScale::pointArray = pointArray;
}

CurvatureScale::CurvatureScale() {
    curvatureArray = new double[10];
}

// Getters

double CurvatureScale::getCurvature(int index) {
    return curvatureArray[index];    
}

double CurvatureScale::getScale() {
    return scale;
}

int CurvatureScale::getLength() {
    return dataLength;
}

point CurvatureScale::getPoint(int index) {
    return pointArray[index];
}

// Setters

void CurvatureScale::setCurvatureArray(double* curvatureArray, int dataLength) {
    delete[] CurvatureScale::curvatureArray;
    CurvatureScale::curvatureArray = new double[dataLength];
    memcpy(CurvatureScale::curvatureArray, curvatureArray, dataLength * sizeof(double));
}

void CurvatureScale::setCurvature(double curvature, int index) {
    curvatureArray[index] = curvature;
}

void CurvatureScale::setScale(double scale) {
    CurvatureScale::scale = scale;
}

// DataContainer functions ---------------------------------------------------------------------------------------------------

DataContainer::DataContainer(point* pointArray, int dataLength) {
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
    curvatureScaleArray = new CurvatureScale[(dataLength*(dataLength+1))/2];
}

// Destructor deletes the arrays and pointers so memory is not leaked
DataContainer::~DataContainer() {
    delete[] curvatureScaleArray;
}

// getters
CurvatureScale* DataContainer::getIndex(int index) {
    return &(curvatureScaleArray[index]);
}

// CurvatureScale* DataContainer::getScale(double scale){

// }

point DataContainer::getPoint(int index) {
    return pointArray[index];
}

point* DataContainer::getPointAddress(int index) {
    return &pointArray[index];
}

int DataContainer::getPointArrayLength() {
    return pointArrayLength;
}

int DataContainer::getCurvatureArrayLength() {
    return curvatureArrayLength;
}

double DataContainer::getMinLength() {
    return minLength;
}

double DataContainer::getMaxLength() {
    return (minLength * maxHalfIntervalPossible);
}

double DataContainer::getmaxHalfIntervalPossible() {
    return maxHalfIntervalPossible;
} 

// setters
void DataContainer::setIndex(int index, CurvatureScale* data) {
    curvatureScaleArray[index] = *data;
}
void DataContainer::setPoint(int index, point point) {
    pointArray[index] = point;
}
void DataContainer::putData(int scale, int index, double curvature) {
    this->curvatureScaleArray[scale].setCurvature(curvature, index);
}

void DataContainer::setPointArray(point *pointArray, int dataLength) {
    delete[] DataContainer::pointArray;
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
    delete[] curvatureScaleArray;
    curvatureScaleArray = new CurvatureScale[(dataLength*(dataLength+1))/2];
}
// intializes the original data to zero, automatially calculates data length
void DataContainer::initDataZero(point *pointArray) {
    delete[] DataContainer::pointArray;
    int dataLength = sizeof(pointArray)/sizeof(pointArray[0]);
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
    delete[] curvatureScaleArray;
    curvatureScaleArray = new CurvatureScale[(dataLength*(dataLength+1))/2];
}

void DataContainer::setmaxhalfinterval(){
    //we find the minimum length by averaging the length across the entire data, thatis, the smallest distance between two points
    DataContainer::minLength = abs((DataContainer::pointArray[pointArrayLength].x)-(DataContainer::pointArray[0].x) / (DataContainer::pointArrayLength - 1));
    //we calculate the maximum length possible. First, we check to see if the data has an even or odd number of points
    //an even number of points results in an odd number of intervals. the number of intervals is always one less than the number of points
    //an odd number of points results in an even number of intervals.
    //we want to find the maximum interval possible that fits in twice within the data.
    //the following formulas calculate the maximum interval possible given the data.
    if(DataContainer::pointArrayLength % 2 == 0){
        //data is even length
        //odd number of intervals
        //example: 4 points. this means there are 3 intervals, and the maximum half interval possible is 1.
        DataContainer::maxHalfIntervalPossible = (DataContainer::pointArrayLength / 2) - 1;
        DataContainer::odd = false;
    }
    else{
        //data is odd length
        //even number of intervals
        //example: 5 points. this means there are 4 intervals, and the maximum half interval possible is 2.
        DataContainer::maxHalfIntervalPossible = (DataContainer::pointArrayLength - 1) / 2;
        DataContainer::odd = true;
    }
    //finally, for the user, we multiply the minimum length by the maximum half interval possible to get the maximum length possible.
    //this value is shown later to the user as they select their bounds, as it represents the upper limit of what is possible to enter into the bounds.
    DataContainer::maxLength = DataContainer::minLength * DataContainer::maxHalfIntervalPossible;
}

