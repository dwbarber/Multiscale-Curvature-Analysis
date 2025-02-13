#ifndef USERDATA_H
#define USERDATA_H
#include <string>
using namespace std;
class UserData{
    public:
        //setters
        int setScaleBounds(double min, double max);
        bool setAnalyisType(int method);
        bool setHybridSelection(int obtusemethod, int acutemethod);
        bool setInputFilePath(string path);


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
    
        DataContainer dataContainer;

        int analysisType;
        bool hybrid;
        int hybridSelection[2];
        bool logScale;
};
#endif


