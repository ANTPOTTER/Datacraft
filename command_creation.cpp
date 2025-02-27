#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "functions.h"

std::string print_statement(std::string text) {
    return "say " + text;
}

std::string print_big_statement(std::string text, std::string target, std::string location, float FadeIn, float Stay, float FadeOut) {
    if (location != "title") {
        return "title " + target + std::to_string(FadeIn) + std::to_string(Stay) + std::to_string(FadeOut) + "\\ntitle " + target + location + text + "\\ntitle " + target + "title" + ' ';
    } else {
    return "title " + target + std::to_string(FadeIn) + std::to_string(Stay) + std::to_string(FadeOut) + "\\ntitle " + target + location + text;
    }
}

std::string print_personal_statement(std::string text, std::string target) {
    return "tell " + target + text;
}
