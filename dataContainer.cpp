#include "dataContainer.h"
#include <cstring>

CurvatureScale::CurvatureScale(double *curvatureArray, int dataLength, double scale, point *pointArray) {
    CurvatureScale::curvatureArray = new double[dataLength];
    memcpy(CurvatureScale::curvatureArray, curvatureArray, dataLength * sizeof(double));
    CurvatureScale::scale = scale;
    CurvatureScale::pointArray = pointArray;
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

DataContainer::DataContainer(point* pointArray, int dataLength) {
    curvatureScaleArray = new CurvatureScale*[(dataLength*(dataLength+1))/2];
}

// Destructor deletes the arrays and pointers so memory is not leaked
DataContainer::~DataContainer() {
    delete[] curvatureScaleArray;
}

// getters
CurvatureScale* DataContainer::getIndex(int index) {
    return curvatureScaleArray[index];
}

// CurvatureScale* DataContainer::getScale(double scale){

// }

point DataContainer::getPoint(int index) {
    return pointArray[index];
}

int DataContainer::getPointArrayLength() {
    return pointArrayLength;
}

int DataContainer::getCurvatureArrayLength() {
    return curvatureArrayLength;
}

// setters
void DataContainer::setIndex(int index, CurvatureScale* data) {
    curvatureScaleArray[index] = data;
}

// void DataContainer::putData(int index, CurvatureScale* data) {
    
// }

void DataContainer::setPointArray(point *pointArray, int dataLength) {
    delete[] DataContainer::pointArray;
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
    delete[] curvatureScaleArray;
    curvatureScaleArray = new CurvatureScale*[(dataLength*(dataLength+1))/2];
}

void DataContainer::setPoint(int index, point point) {
    pointArray[index] = point;
}
