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
