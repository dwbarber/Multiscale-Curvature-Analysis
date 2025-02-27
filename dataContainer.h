#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include <cstring>
#include <cmath>
#include <cstdint>
/**
* 
*/

// Point data type to store x value and z value
typedef struct{
    double x;
    double z;
}point;

// This struct stores an array of curvatures and the scale at whitch they were calculated
class CurvatureScale {

    public:

        // constructors
        CurvatureScale();
        CurvatureScale(double *curvatureArray, int dataLength, double scale, point *pointArray);

        // destructor
        ~CurvatureScale(){};
        
        // getters
        double getCurvature(int index);
        double getScale();
        int getLength();
        point getPoint(int index);

        
        //----------------------------------------------------------------------------------------------------------------
        // setters
        
        // sets the curvature array from an external array
        void setCurvatureArray(double* curvatureArray, int dataLength);
        void setCurvatureArray(int dataLength);
        
        // sets curvature at index
        void setCurvature(double curvature, int index);
        
        /**
        * Function: setScale()
        * Sets the value of the scale parameter
        * @param scale: The scale at which this data was calculated
        */
        void setScale(double scale);

    private:
        double scale;
        double* curvatureArray;
        point* pointArray;
        int dataLength;

};

class DataContainer {

    public:

        // Constructors 
        DataContainer() {};
        DataContainer(point* pointArray, int dataLength);
        
        // Destructor deletes the arrays and pointers so memory is not leaked
        ~DataContainer ();
        
        // getters
        CurvatureScale* getIndex(int index);
        CurvatureScale* getScale(double scale);
        int getCurvatureArrayLength();



        point getPoint(int index);
        int getPointArrayLength();
        point* getPointAddress(int index);
        double getMinLength();
        double getMaxLength();
       
        double getmaxHalfIntervalPossible();
        // setters
        void setIndex(int index, CurvatureScale* data);
        void putData(int scale, int index, double curvature);
        void setPointArray(point *pointArray, int dataLength);
        void setPointArray(int dataLength);
        void setCurvatureScaleArray(int dataLength);
        void setPoint(int index, point point);
        void setmaxhalfinterval();
        void numOps(const int& minScale, const int& maxScale);        
        
        friend class UserData;
        
    private:
        // This array stores the height data from input file
        point* pointArray;
        int pointArrayLength;
        
        // This array stores a list of curvature scale objects. Each object stores the curvature array at a scale
        CurvatureScale* curvatureScaleArray;
        int curvatureArrayLength;

        //Properties of data
        double minLength;
        double maxLength;
        int maxHalfIntervalPossible;
        bool odd;
};

#endif
