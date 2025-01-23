#include"dataContainer.h"
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
    
}

// Destructor deletes the arrays and pointers so memory is not leaked
DataContainer::~DataContainer() {
    
}

// getters
CurvatureScale* DataContainer::getIndex(int index) {
    return curvatureArray[index];
}

// CurvatureScale* DataContainer::getScale(double scale){

// }

point DataContainer::getPoint(int index) {
    return pointArray[index];
}

// setters
void DataContainer::setIndex(int index, CurvatureScale* data) {
    curvatureArray[index] = data;
}

void DataContainer::putData(int index, CurvatureScale* data) {
    
}

void DataContainer::setPointArray(point *pointArray, int dataLength) {
    delete[] DataContainer::pointArray;
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
}

void DataContainer::setPoint(int index, point point) {
    pointArray[index] = point;
}
