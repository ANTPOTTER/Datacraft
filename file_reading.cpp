#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include <filesystem>

std::string ReadFile(const std::string& FileName) {
    std::ifstream File(FileName);
    if (!File) {
        std::cerr << "Could not open file: " << FileName << std::endl;
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(File)),
                        std::istreambuf_iterator<char>());
    return content;
}

void WriteToFile(const std::string& FileName, const std::string& Content) {
    std::ofstream OutputFile(FileName);
    if (!OutputFile) {
        std::cerr << "Could not create file: " << FileName << std::endl;
        return;
    }
    OutputFile << Content;
}
