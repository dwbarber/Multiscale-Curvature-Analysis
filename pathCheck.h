#ifndef PATHCHECK_H
#define PATHCHECK_H

#include <string>
#include <vector>

// Function to check if a file exists
bool validPath(const std::string& path);

// Function to get file extension
std::string pathExtension(const std::string& path);

// Function to read a CSV file and return a vector of doubles
std::vector<double> readCSV(const std::string& path);

#endif // PATHCHECK_H]