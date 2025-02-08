#ifndef PATHCHECK_H
#define PATHCHECK_H

#include <string>
#include <vector>

// Function to check if a file path is valid
bool validPath(const std::string& path);

// Function to get the file extension from a path
std::string pathExtension(const std::string& path);

// Function to read a CSV file and return a vector of doubles
std::vector<double> readCSV(const std::string& path);

#endif // PATHCHECK_H]