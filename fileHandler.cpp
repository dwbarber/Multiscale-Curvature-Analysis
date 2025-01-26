#include "fileHandler.h"
#include "dataContainer.h"
#include <fstream>
#include <string>
using namespace std;

point* FileHandler::read(string fileName){
    ifstream input;
    if(!input.open(fileName)){
        //throw error maybe?
    }
    double xval,zval;
    vector<point> import;
    point a;
    double doubletoignore;//there is unnecessary doubles that are just zero
    int nameOrorderofpoints;//there are int val inputs to ignore in each line
    string lastLineBefInput;
    while(!input.eof()&&(lastLineBefInput.std::find("// X,Y,Z,C,Lock")!=string::npos)){//"// X,Y,Z,C,Lock" is the last line before data
        getline(input, lastLineBefInput);
    }
    while(!input.eof()){
        input >> nameOrorderofpoints;
        input >> xval;
        input >> doubletoignore;
        input >> zval;
        input >> doubletoignore;
        input >> nameOrorderofpoints;
        a.x=xval;
        a.z=zval;
        import.push_back(a);
    }
    input.close();
    point* array=new point[import.size()];//make so array doesnt get deleted after function ends
    unsigned long long int a= import.size()// add long(s) if want to
    unsigned long long int i=0;
    while(i < a){
        array[i]= import.at(i);
        ++i;
    }
    return array;
}