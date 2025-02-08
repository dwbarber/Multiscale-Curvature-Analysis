#ifndef USERDATA_H
#define USERDATA_H
#include <string>
using namespace std;
class UserData{
    public:
        //setters
        void setScaleBounds(int min, int max);
        void setAnalyisType(string method);
        void setHybridSelection(string method1, string method2);
        void setInputFilePath(string path);

        //getters
        int getMinScale();
        int getMaxScale();
        string getAnalysisType();
        bool getHybrid();
        int getHybridSelection(int index);
        bool getLogScale();
        void setLogScale(bool logScale);
        
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
#endif


