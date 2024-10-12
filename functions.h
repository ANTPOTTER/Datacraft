// my_functions.h
#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include <filesystem>
#include <algorithm>
#include <vector>

// File Reading
std::string ReadFile(const std::string& FileName);
void WriteToFile(const std::string& FileName, const std::string& Content);

// Miscellaneous Functions
std::string replace(std::string str, int oldSubstr, int newSubstr);
int command_count();
std::string processVectorUntilChar(std::vector<std::string> vec, int startIndex, std::string targetChar);

#endif