

int maxIntervalIndex(double& minLength, double& maxLength, int& arraylength, double arr[]){
    //we find the length of the input array
    int arraylength = sizeof(arr)/sizeof(arr[0]);
    //we find the minimum length by averaging the length across the entire data
    double minLength = (arr[0] + arr[arraylength]) / (arraylength - 1);
    int maxIntervalIndex;
    double maxLength;
    if(arraylength % 2 == 0){
        //data is even length
        //odd number of intervals
        maxIntervalIndex = (arraylength / 2) - 1;
    }
    else{
        //data is odd length
        //even number of intervals
        maxIntervalIndex = (arraylength - 1) / 2;
    }
    return maxIntervalIndex;
}