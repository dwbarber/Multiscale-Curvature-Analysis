
#include <string>
using namespace std;
class UserInput{
    public:
        //functions to get data from command line
        string getString(string message);
        int getInt(string message);
        double getDouble(string message);
        bool getYesNo(string message);


        //setters
        void setScaleBounds(int min, int max);
        void setAnalyisType(string method);
        void setHybridSelection(string method1, string method2);
        
    private:
        //filepath
        string inputFilepath;

        //scale data
        int userMinScale;
        int userMaxScale;
        

        int analysisType;
        bool hybrid;
        int hybridSelection[2];
        bool logScale;
};


