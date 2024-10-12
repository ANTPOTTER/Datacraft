#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include <filesystem>
#include <algorithm>
#include <vector>

std::string replace(std::string str, int oldSubstr, int newSubstr) {
    for (char& c : str) {
        if (c == oldSubstr) {
            c = newSubstr;
        }
        if ((c == '.') && (c+1 == '.') && (c+2 == '.')) {
            c = '...';
        }
    }
    return str;
}

int command_count() {
    static int counter = 0;
    return counter++;
}

std::string processVectorUntilChar(const std::vector<std::string>& vec, int startIndex, std::string targetChar) {
    std::string result;
    for (size_t i = startIndex; i < vec.size(); ++i) {
        if ((vec[i] == targetChar) && (vec[i-1] != "\\")) {
            break;
        }
        result += vec[i];
    }

    return result;
}