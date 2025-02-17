#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include<string>
#include<fstream>
#include<vector>
using std::vector;
class FileHandler{
    public:
    	static int validateType();
        static point* fileRead(string input); 
        static int fileWrite(DataContainer& XSC);
        static bool validPath(const std::string& path);
        static std::string pathExtension(const std::string& path);
        static string remove_quotes(const string& input);

    	static void inheritData();

        static point* read(std::string fileName);

};

#endif
