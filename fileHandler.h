#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include<string>
#include<fstream>
#include<vector>
using std::vector;
class FileHandler{

	int validateType();
    point* fileRead(); 
    int fileWrite(DataContainer& XSC);
    bool validPath(const std::string& path);
    std::string pathExtension(const std::string& path);
    string remove_quotes(const string& input);

	void inheritData();

	point* read(std::string fileName);

};

#endif
