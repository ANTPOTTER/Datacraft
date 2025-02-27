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

std::vector<std::string> splitByNthOccurrence(const std::string& str, char delimiter, int n) {
    std::vector<std::string> result;
    std::string current;
    int occurrence = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == delimiter) {
            occurrence++;
            if (occurrence == n) {
                result.push_back(current);
                current.clear();
                occurrence = 0;
            } else {
                current += str[i];
            }
        } else {
            current += str[i];
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

bool isInt(const std::string& str) {
    if (str.empty()) return false;
    size_t i = (str[0] == '-') ? 1 : 0;
    return i < str.size() && std::all_of(str.begin() + i, str.end(), ::isdigit);
}

bool isFloat(const std::string& str) {
    if (str.empty()) return false;
    std::istringstream ss(str);
    float f;
    ss >> f;
    return ss.eof() && !ss.fail();
}

int checkType(const std::string& str) {
    if (isInt(str)) {
        return 0;
    } else if (isFloat(str)) {
        return 1;
    } else {
        return 2;
    }
}
