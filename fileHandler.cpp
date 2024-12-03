#include"fileHandler.h"
#ifndef DATACONTAINER_CPP
#define DATACONTAINER_CPP

point* FileHandler::read(std::string fileName){
    if(!ifstream input.open(fileName)){
        //throw error maybe?
    }
    //if() what should i check for? file type any iterations that cant be looped/info thats important
    double xval,zval;
    vector<point> import;
    point a;
    double doubletoignore;
    int nameOrorderofpoints;//ask abt numbers and stuff in example file
    std::string lastLineBefInput;
    while(!input.eof()&&(lastLineBefInput!="// X,Y,Z,C,Lock")){//forgot what i need to do to make// work in a stringor if its just\\ 
        getline(input, lastLineBefInput);//might need to use .ignore bc reading lines but delete comment if works as is
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
    point* array=new point[import.size()];
    array*= import;
    return array;
}