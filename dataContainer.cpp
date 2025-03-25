#include "dataContainer.h"


#include <iostream> // for testing purposes only

// CurvatureScale functions ---------------------------------------------------------------------------------------------------

CurvatureScale::CurvatureScale(double *curvatureArray, int dataLength, double scale, point *pointArray) {
    CurvatureScale::curvatureArray = new double[dataLength];
    memcpy(CurvatureScale::curvatureArray, curvatureArray, dataLength * sizeof(double));
    CurvatureScale::scale = scale;
    CurvatureScale::pointArray = pointArray;
    CurvatureScale::dataLength = dataLength;
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

void CurvatureScale::setCurvatureArray(int dataLength) {
    delete[] CurvatureScale::curvatureArray;
    CurvatureScale::curvatureArray = new double[dataLength];
    CurvatureScale::dataLength = dataLength;
}

void CurvatureScale::setCurvature(double curvature, int index) {
    curvatureArray[index] = curvature;
}

void CurvatureScale::setScale(double scale) {
    CurvatureScale::scale = scale;
}

// DataContainer functions ---------------------------------------------------------------------------------------------------


DataContainer::DataContainer(point* pointArray, int dataLength) : pointArray(nullptr) {
    setPointArray(pointArray, dataLength);
}

// Destructor deletes the arrays and pointers so memory is not leaked
DataContainer::~DataContainer() {
    delete[] curvatureScaleArray;
}

// getters
CurvatureScale* DataContainer::getIndex(int index) {
    return &(this->curvatureScaleArray[index]);
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

int64_t DataContainer::getCurvatureArrayLength() {
    return curvatureArrayLength;
}

double DataContainer::getMinLength() {
    return DataContainer::minLength;
}

double DataContainer::getMaxLength() {
    return (DataContainer::minLength * DataContainer::maxHalfIntervalPossible);
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
    this->curvatureScaleArray[scale].setCurvature(curvature, index); // puts the data into the array for a particular scale
    // std::cout<<this->curvatureScaleArray[scale].getCurvature(index)<<std::endl; //check if data is actually being put correctly
    // std::cout<<this->curvatureScaleArray[scale].getLength()<<std::endl;
}

void DataContainer::setCurvatureScaleArray(int dataLength) {
    delete[] DataContainer::curvatureScaleArray;
    DataContainer::curvatureScaleArray = new CurvatureScale[dataLength];
    DataContainer::curvatureArrayLength = dataLength;
}

void DataContainer::setPointArray(point *pointArray, int dataLength) {
    delete[] DataContainer::pointArray;
    DataContainer::pointArray= new point[dataLength];
    memcpy(DataContainer::pointArray, pointArray, dataLength * sizeof(point));
    DataContainer::pointArrayLength = dataLength;
}

void DataContainer::setPointArray(int dataLength) {
    std::cout<<"setting point array with length " << dataLength << std::endl;
    if(this->pointArray){
        std::cout<<"array already exists, clearing"<<std::endl;
        if (this->pointArray) {
            delete[] this->pointArray;
            this->pointArray = nullptr;
        }
    }
    std::cout<<"make new array"<<std::endl;
    this->pointArray= new point[dataLength];
    this->pointArrayLength = dataLength;
}

void DataContainer::setmaxhalfinterval(){
    //we find the minimum length by averaging the length across the entire data, thatis, the smallest distance between two points
   this->minLength = fabs(((DataContainer::pointArray[pointArrayLength-1].x)-(DataContainer::pointArray[0].x)) / (DataContainer::pointArrayLength - 1));
    
    //FOR DEBUGGING
    // std::cout<< DataContainer::pointArray[pointArrayLength-1].x << std::endl;
    // std::cout<< DataContainer::pointArray[0].x << std::endl;

    // std::cout << ((DataContainer::pointArray[pointArrayLength-1].x)-(DataContainer::pointArray[0].x)) << std::endl;
    // std::cout <<9.9 / 99 << std::endl;
    // std::cout <<9.9/99.<< std::endl;
    // std::cout<< DataContainer::pointArrayLength - 1 << std::endl;
    // std::cout<< minLength << std::endl;


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
        this->odd = false;
        std::cout<<"even"<<std::endl;
    }
    else{
        //data is odd length
        //even number of intervals
        //example: 5 points. this means there are 4 intervals, and the maximum half interval possible is 2.
        DataContainer::maxHalfIntervalPossible = (DataContainer::pointArrayLength - 1) / 2;
        this->odd = true;
        
    }
    //finally, for the user, we multiply the minimum length by the maximum half interval possible to get the maximum length possible.
    //this value is shown later to the user as they select their bounds, as it represents the upper limit of what is possible to enter into the bounds.
    DataContainer::maxLength = DataContainer::minLength * DataContainer::maxHalfIntervalPossible;
}

// this function takes in the maximum measurement parameters from the function defined above, as well as the user's preferred measurement parameters in order
// to determine how many curvatures will be calculated (Number of Operations: numops)
void DataContainer::numOps(const int& minScale, const int& maxScale){
    int64_t retval;
    //formula is different for calculating the number of operations if the data is odd or even.
    int minops = (DataContainer::pointArrayLength - 2*minScale);
    std::cout<<"minops"<<minops<<std::endl;
    int maxops = (DataContainer::pointArrayLength - 2*maxScale);
    std::cout<<"maxops"<<maxops<<std::endl;
    retval = (((minops - maxops)/2+1)*(minops + maxops))/2;
    std::cout<<"minscale"<<minScale<<std::endl;
    std::cout<<"maxscale"<<maxScale<<std::endl;


    //retval is the total number of curvatures to be made. 
    //the total number of operations to be performed = indexes in the array.
    
    try {
        DataContainer::curvatureScaleArray = new CurvatureScale[retval];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
    for (int i = minScale; i < maxScale+1; i++){ //set the length of each array
        //print the length to be set
        std::cout << "Setting length of array " << i << " to " << DataContainer::pointArrayLength  - 2*i << std::endl;
        DataContainer::curvatureScaleArray[i].setCurvatureArray(DataContainer::pointArrayLength - 2*i);
    }
    DataContainer::curvatureArrayLength = retval;
}
