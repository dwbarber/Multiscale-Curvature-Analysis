#ifdef FILEHANDLER_H
#define FILEHANDLER_H
#ifndef DATACONTAINER_CPP
#define DATACONTAINER_CPP

#include<string>
#include<fstream>
#include<vector>
using std::vector;
class FileHandler{

	int validateType();

	void inheritData();

	point* read(std::string fileName);

}

#endif
