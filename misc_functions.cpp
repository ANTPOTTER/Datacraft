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

std::vector<std::string> ProcessStringUntilClose(const std::vector<std::string>& code, int startIndex, std::string close_char = "}") {
    std::vector<std::string> brace_content;
    std::string temp;
    std::string open_char;
    bool confirmation;
    int addon = 0;
    int num = startIndex;
    int error = 0;
    if (close_char == "}") {
        open_char = "{";
    }
    else if (close_char == ")") {
        open_char = "(";
    }
    else if (close_char == "]") {
        open_char = "[";
    }
    while (confirmation = 0) {
        if ((code[num] == close_char) && (error != 0)) {
            error -= 1;
        }
        else if (code[num] == open_char) {
            error += 1;
        }
        else if ((code[num] == close_char) && (error = 0)) {
            startIndex += 1;
            while (confirmation = 0) {
                if (startIndex < num) {
                    brace_content.push_back(code[startIndex]);
                }
                else if (startIndex >= num) {
                    return brace_content;
                }
                startIndex += 1;
            }
        }
        num += 1;
    }
}

bool containsAnyCharacter(const std::string& str, const char arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; ++i) { 
        if (str.find(arr[i]) != std::string::npos) {
            return true; 
        }
    }
    return false;
}

bool vectorcontainsword(std::string str, std::vector<std::string> vector, int skip_count = 1) {
    int total;
    while (total <= vector.size()) {
        if (str.find(vector[total]) != std::string::npos) {
            return true;
        }
        total += skip_count;
    }
    return false;
}

std::string concatenateVector(const std::vector<std::string>& vec) {
    std::ostringstream oss;
    
    for (const auto& str : vec) {
        oss << str << " ";
    }

    return oss.str();
}

std::vector<std::string> splitString(const std::string& str, char splitter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, splitter)) {
        tokens.push_back(token);
    }
    return tokens;
}
