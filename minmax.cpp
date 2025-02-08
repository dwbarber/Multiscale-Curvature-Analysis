#include <cstdint>

int maxHalfIntervalPossible(double& minLength, double& maxLength, int& arraylength, bool& odd, const double arr[]){
    //we find the length of the input array
    int arraylength = sizeof(arr)/sizeof(arr[0]);
    //we find the minimum length by averaging the length across the entire data, that is, the smallest distance between two points
    double minLength = (arr[0] + arr[arraylength]) / (arraylength - 1);
    int maxHalfIntervalPossible;
    double maxLength;
    //we calculate the maximum length possible. First, we check to see if the data has an even or odd number of points
    //an even number of points results in an odd number of intervals. the number of intervals is always one less than the number of points
    //an odd number of points results in an even number of intervals.
    //we want to find the maximum interval possible that fits in twice within the data.
    //the following formulas calculate the maximum interval possible given the data.
    if(arraylength % 2 == 0){
        //data is even length
        //odd number of intervals
        //example: 4 points. this means there are 3 intervals, and the maximum half interval possible is 1.
        maxHalfIntervalPossible = (arraylength / 2) - 1;
        odd = false;
    }
    else{
        //data is odd length
        //even number of intervals
        //example: 5 points. this means there are 4 intervals, and the maximum half interval possible is 2.
        maxHalfIntervalPossible = (arraylength - 1) / 2;
        odd = true;
    }
    //finally, for the user, we multiply the minimum length by the maximum half interval possible to get the maximum length possible.
    //this value is shown later to the user as they select their bounds, as it represents the upper limit of what is possible to enter into the bounds.
    maxLength = minLength * maxHalfIntervalPossible;
    return maxHalfIntervalPossible;
}


int64_t numops(const bool& odd, const int& maxHalfIntervalPossible, const int& minScale, const int& maxScale){
    int64_t retval;
    //formula is different for calculating the number of operations if the data is odd or even.
    int minops = maxHalfIntervalPossible - minScale + 1;
    int maxops = maxHalfIntervalPossible - maxScale;
    retval = minops * minops - maxops * maxops;
    if (odd){
        //the only part that is different depending on if the data is odd or even.
        retval += minops - maxops;
    }
    //the total number of operations to be performed.
    return retval;
}

int numscales()
