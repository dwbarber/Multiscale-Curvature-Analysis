#ifndef USERDATA_H
#define USERDATA_H
#include <string>
using namespace std;
class UserData{
    public:
        //setters
        void setScaleBounds(int min, int max);
        void setAnalyisType(int method);
        void setHybridSelection(int method1, int method2);
        void setInputFilePath(string path);

        //getters
        int getMinScale();
        int getMaxScale();
        int getAnalysisType();
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


