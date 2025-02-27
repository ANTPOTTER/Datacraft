#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "functions.h"

// Version, Variables, If, Else if, Else, Print, Sleep, Random, @ (Const, Dropless), Range

std::vector<std::string> parser(std::vector<std::string> program) {
    // Vectors
    std::vector<std::string> variable_name_vector;
    std::vector<std::string> variable_content_vector;
    std::vector<int> variable_type_vector;
    std::vector<std::string> variables_temp_insert_vector;
    std::vector<std::string> variable_temp_content;
    std::vector<std::string> if_statement_content;
    // Strings
    std::string variable_name;
    std::string variable_content;
    std::string variable_token;
    // Integers
    static int program_counter = 0;
    static int program_counter_if_statement = 0;
    int variable_temp = 0;
    int variable_type = 0;
    int if_statement_closing_brace_checker = 0;
    int if_statement_toggle_checker = 0;
    // Bools
    bool if_statement_bool = false;

    if (2 > program.size()) {
        std::cerr << "ERROR: File Too Short" << std::endl;
    }
    else {
    if (program[0] != "version" && program[1] != "==") {
        std::cerr << "ERROR: No Version Control" << std::endl;
    } else {
        std::unordered_map<std::string, int> version_map {
            {"1.21", 1},
            {"1.20", 2}
        };
        int version = 0;
        auto it = version_map.find(program[2]);
        if (it != version_map.end()) {
            version = it->second;
        }
        program.erase(program.begin(), program.begin() + 3);
        while (program_counter <= program.size()) {

            if (find(variable_name_vector.begin(), variable_name_vector.end(), program[program_counter]) != variable_name_vector.end()) {
                auto variable_temp = find(variable_name_vector.begin(), variable_name_vector.end(), program[program_counter]);
                int variable_temp_int;
                if (variable_temp != variable_name_vector.end()) {
                    size_t variable_temp_int = std::distance(variable_name_vector.begin(), variable_temp);
                } else {
                    std::cerr << "ERROR: Variable Name Not Found" << std::endl;
                }
                
                std::istringstream tokenStream(variable_content_vector[variable_temp_int]);
                while (std::getline(tokenStream, variable_token, ' ')) {
                    variable_temp_content.push_back(variable_token);
                }
                program.insert(program.begin() + program_counter, variable_temp_content.begin(), variable_temp_content.end());
            } else {
                std::cerr << "Error: Variable Not Found" << std::endl;
            }

            if (program[program_counter] == "var") {
                variable_name_vector.push_back(program[program_counter + 1]);
                if (checkType(program[program_counter + 3]) == 0 || 1 || 2) {
                    variable_type_vector.push_back(checkType(program[program_counter + 3]));
                } else std::cerr << "ERROR: Invalid Variable Type";
                variable_content_vector.push_back(processVectorUntilChar(program, program_counter, "\""));
            }

            if (program[program_counter] == "if") {
                program_counter_if_statement = program_counter;

                while (if_statement_toggle_checker) {
                    
                }

                for (size_t i = program_counter + ; i < vec.size(); ++i) {
                    if ((vec[i] == ')') && (vec[i-1] != "\\")) {
                        break;
                    }
                    result += vec[i];
                }

                parser(processVectorUntilChar(program, program_counter, "{"));
            }

            if (program[program_counter] == "else") {

            }
            if (program[program_counter] == "print") {
                
            }
            if (program[program_counter] == "print_big") {

            }
            if (program[program_counter] == "print_personal") {

            }
            if (program[program_counter] == "sleep") {

            }
            if (program[program_counter] == "random") {

            }
        }
    }
    }
}
