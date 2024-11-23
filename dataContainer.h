#ifndef DATACONTAINER_H
#define DATACONTAINER_H

/**
* 
*/

// Point data type to store x value and z value
typedef struct{
	double x;
	double z;
		
}point;

// This struct stores an array of curvatures and the scale at whitch they were calculated
class curvatureScale {

 public:

  // constructors
  curvatureScale();
  curvatureScale(double* curvatureArray, int dataLength, double scale, double positionStep, double positionStart);

  // destructor
  ~curvatureScale();
  
  // getters
  double getCurvature(int index);
  double getScale();
  int getLength();
  double getPosition(int index);

  //----------------------------------------------------------------------------------------------------------------
  // setters
  
  // sets the curvature array from an external array
  void setCurvatureArray(double* curvatureArray, int dataLength);

  // sets curvature at index
  void setCurvature(int index);
  
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

class dataContainer {

 public:

  // Constructors 
  dataContainer();
  dataContainer(double* heightArray, int dataLength);

  // Destructor deletes the arrays and pointers so memory is not leaked
  ~dataContainer ();

  // getters
  curvatureScale* getIndex(int index);
  curvatureScale* getScale(double scale);
  double getHeight(int index);

  // setters
  void setIndex(int index, curvatureScale* data);
  void putData(int index, curvatureScale* data);
  void setHeightArray(double* heightArray, int dataLength);
  void setHeight(int index, double height);
   
 private:
  // This array stores the height data from input file
  double* heightDataArray;
  int hightArrayLength;

  // This array stores a list of curvature scale objects. Each object stores the curvature array at a scale
  curvatureScale** curvatureArray;
  int curvatureArrayLength;
  
};

#endif
