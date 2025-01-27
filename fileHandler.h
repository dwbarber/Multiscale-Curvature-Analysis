#ifdef FILEHANDLER_H
#define FILEHANDLER_H

#include<string>
#include<fstream>
#include<vector>
using std::vector;
class FileHandler{

	int validateType();

	void inheritData();

	point* read(std::string fileName);

};

#endif
