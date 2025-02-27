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

// Commands
std::vector<std::string> code_words(std::vector<std::string> program_vector, int program_count, std::vector<std::string> commands_vector, int commands_count, std::vector<std::string> commandType);
std::string command_creation(int command_type, std::string content, int program_counter, std::vector<std::string> last_operation);

// Range
std::vector<std::string> range_loop(std::vector<std::string> program_vector, int program_count);

// File Reading
std::string ReadFile(const std::string& FileName);
void WriteToFile(const std::string& FileName, const std::string& Content);

// Miscellaneous Functions
std::string replace(std::string str, int oldSubstr, int newSubstr);
int command_count();
std::string processVectorUntilChar(std::vector<std::string> vec, int startIndex, std::string targetChar);
std::vector<std::string> ProcessStringUntilClose(const std::vector<std::string>& code, int startIndex, std::string close_char = "}");
bool containsAnyCharacter(const std::string& str, const char arr[], size_t arrSize);
bool vectorcontainsword(std::string str, std::vector<std::string> vector, int skip_count = 1);
std::string concatenateVector(const std::vector<std::string>& vec);
std::vector<std::string> splitString(const std::string& str, char splitter);
std::vector<std::string> splitByNthOccurrence(const std::string& str, char delimiter, int n);
bool isInt(const std::string& str);
bool isFloat(const std::string& str);
int checkType(const std::string& str);

#endif
