#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "dataContainer.h"
#include<string>
#include<fstream>
#include<vector>
using std::vector;
class FileHandler{
    public:
        FileHandler();
    	static int validateType();
        static void fileRead(std::string input, DataContainer* data); 
        static int fileWrite(DataContainer* XSC);
        static bool validPath(const std::string& path);
        static std::string pathExtension(const std::string& path);
        static std::string remove_quotes(const std::string& input);

    	static void inheritData();

        static point* read(std::string fileName);
    private:
        DataContainer* data;
};

#endif
