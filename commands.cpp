#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include <filesystem>
#include <algorithm>
#include <vector>
#include "functions.h"

std::vector<std::string> variables;

std::vector<std::string> code_words(std::vector<std::string> program_vector, int program_count, std::vector<std::string> commands_vector, int commands_count, std::vector<std::string> commandType) {
    static int if_statement_toggle;
    static bool Contains_GUI;
    static std::vector<std::string> end_commands;
    std::string if_statement_toggle_string;
    static std::vector<std::string> last_operation;
    char valid_nums[12] = {'~', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int next_func_num;
    int counter;
    std::string next_func;
    std::string if_chunk;

    std::string switch_var = program_vector[program_count];
    next_func = "function functions:";
    while (program_count <= program_vector.size()) {
        // VARIABLES
        if (program_vector[program_count] == "var" || vectorcontainsword(program_vector[program_count], variables, 2)) {
            if (program_vector[program_count] == "var") {
                variables.push_back(program_vector[program_count + 1]);
                std::vector<std::string> temp3;
                temp3 = (ProcessStringUntilClose(program_vector, program_count + 4, ")"));
                std::string variable_formatting = program_vector[program_count + 3] + " ( " + concatenateVector(temp3);
                variables.push_back(variable_formatting);
            }
            else if (vectorcontainsword(program_vector[program_count], variables, 2)) {
                    int total = 1;
                    while (total <= variables.size()) {
                        if (program_vector[program_count].find(variables[total]) != std::string::npos) {
                            std::vector<std::string> temp_vector = splitString(variables[total + 1], ' ');
                            program_vector.erase(program_vector.begin() + total);
                            program_vector.insert(program_vector.begin() + total, temp_vector.begin(), temp_vector.end());
                        }
                        total += 2;
                    }
            }
            counter += 1;
        }
        
        // IF
        if (program_vector[program_count] == "if") {
            if (program_vector[program_count + 2].find(valid_nums) != std::string::npos) {
                if (program_vector[program_count + 1] == "(") {
                    if (containsAnyCharacter(program_vector[program_count + 2], valid_nums, 12)) {
                        std::vector<std::string> ifstatementvector;
                        ifstatementvector = ProcessStringUntilClose(program_vector, program_count + 8, "}");
                        if (if_statement_toggle = 0) {
                            if_statement_toggle_string = "OUTER";
                        }
                        if (if_statement_toggle = 1) {
                            if_statement_toggle_string = "NESTED";
                        }
                        if_statement_toggle++;
                        std::vector<std::string> if_requirement_vector;
                        if_requirement_vector.push_back(program_vector[program_count + 2]);
                        if_requirement_vector.push_back(" ");
                        if_requirement_vector.push_back(program_vector[program_count + 3]);
                        if_requirement_vector.push_back(" ");
                        if_requirement_vector.push_back(program_vector[program_count + 4]);
                        if_requirement_vector.push_back(" ");
                        std::vector<std::string> if_command_creation = if_requirement_vector;
                        if_command_creation.push_back(program_vector[program_count + 6]);
                        std::vector<std::string> if_code_word_pass;
                        if_code_word_pass.insert(if_requirement_vector.end(), ifstatementvector.begin(), ifstatementvector.end());

                        if_chunk = command_creation(3, concatenateVector(if_command_creation), program_count, last_operation) + "";
                        
                        std::vector<std::string> temp_result = code_words(if_code_word_pass, 0, commands_vector, commands_count, commandType);
                        last_operation.push_back(concatenateVector(if_requirement_vector));
                        last_operation.push_back(if_statement_toggle_string);
                        last_operation.push_back("IF");
                        if_statement_toggle--;
                    }
                }
            }
        }
        // ELSE
        else if (program_vector[program_count] == "else") {
            if (counter != 0) {
                if (last_operation.back() == "IF") {
                std::vector<std::string> elsestatementvector;
                elsestatementvector = ProcessStringUntilClose(program_vector, program_count + 1, ")");
                std::vector<std::string> temp_result = code_words(elsestatementvector, 0, commands_vector, commands_count, commandType);
                last_operation.push_back("ELSE");

                }
            }
        }

        // PRINT
        else if (program_vector[program_count] == "print") {
            if (program_vector[program_count + 1] == "(") {
                if (program_vector[program_count + 2] == "str") {
                    if (program_vector[program_count + 3] == "(") {
                        std::vector<std::string> temp_vector;
                        temp_vector.erase(temp_vector.begin(), temp_vector.begin() + program_count + 3);
                        std::string say_content = processVectorUntilChar(temp_vector, program_count + 3, ")");
                        end_commands.push_back(command_creation(5, say_content, program_count, last_operation));
                        last_operation.push_back("PRINT");
                    }
                }
            }
        }

        // SLEEP
        else if (program_vector[program_count] == "sleep") {
            if (program_vector[program_count + 1] == "(") {
                if (program_vector[program_count + 3] == ")") {
                    std::string contents = program_vector[program_count + 2];
                    command_creation(6, contents, program_count, last_operation);
                }
            }
        }

        // RANDOM
        else if (program_vector[program_count] == "random") {
                int temp_int = std::stoi(program_vector[program_count + 2]);
                int temp_int2 = std::stoi(program_vector[program_count + 4]);
                    std::string contents = program_vector[program_count + 2];
                command_creation(7, contents, program_count, last_operation);

        }

        // @
        else if (program_vector[program_count] == "@") {

        }

        // RANGE
        else if (program_vector[program_count] == "range") {
            randge_loop(program_vector, program_count);
        }

        // GUI
        else if (program_vector[program_count] == "GUI") {
            Contains_GUI = true;
        }

        // Var, Version, Anchor, Spawn, @(Const, droppless), Range(Coordinates)
        counter += 1;
    }
}














std::string command_creation(int command_type, std::string content, int program_counter, std::vector<std::string> last_operation) {
    static bool if_toggle;
    static int if_counter = 0;
    static std::string commands;
    int temp;
    int command_formatting;
    std::string command_formatted = std::to_string(command_formatting);
    std::string command_temp;
    std::string command_temp1;
    std::string command_template;
    std::string temp1;
    std::vector<std::string> requirements;

    switch(command_type) {
        // Version
        case 0:
            /*
            1: 1.6.1 – 1.8.9
            2: 1.9 – 1.10.2
            3: 1.11 – 1.12.2
            4: 1.13 – 1.14.4
            5: 1.15 – 1.16.1
            6: 1.16.2 – 1.16.5
            7: 1.17 – 1.17.1
            8: 1.18 – 1.18.2
            9: 1.19 – 1.19.2
            11: 22w42a – 22w44a
            12: 1.19.3
            13: 1.19.4
            14: 23w14a – 23w16a
            15: 1.20 – 1.20.1
            16: 23w31a
            17: 23w32a – 1.20.2-pre1
            18: 1.20.2
            19: 23w42a
            20: 23w43a - 23w44a
            21: 23w45a - 23w46a
            22: 1.20.3 - 1.20.4
            24: 24w03a - 24w04a
            25: 24w05a - 24w05b
            26: 24w06a - 24w07
            28: 24w09a - 24w10a
            29: 24w11a
            30: 24w12a
            31: 24w13a - 1.20.5-pre3
            32: 1.20.5-pre4 - 1.20.5
            34: 1.21 - onwards
            */
            break;
        
        // Anchor
        case 1:

            break;

        // Spawn
        case 2:

            break;

        // If
        case 3:
            if_counter += 1;
            requirements = splitString(content, ' ');
            command_template = "execute as @s at @s if block " + requirements[0] + " " + requirements[1] + " " +requirements[2] + " " + requirements[3] + "\n";
            return command_template = command_template + "function funcs:if_" + std::to_string(if_counter) + "_" + std::to_string(command_count());
            break;

        // Else
        case 4:

            break;

        // Print
        case 5:
            command_temp = "execute as @s at @s run say " + content + "\n";

            if (if_toggle = true) {
                command_temp1 = "function funcs:if_" + if_counter + '_' + std::to_string(command_count()) + "[ NEW_COMMAND ]";
            }
            else if (if_toggle = false) {
                command_temp1 = "function funcs:" + std::to_string(command_count()) + "[ NEW_COMMAND ]";
            }
            else {
                std::cerr << "genuinely, what the actual fuck have you done bro??" << std::endl;
            }
            commands = command_temp + command_temp1;
            temp = 0;
            temp1 = "";
            command_temp = "";
            command_temp1 = "";
            return commands;
            break;

        // Sleep
        case 6:
            temp1 = content.back();
            content.rbegin();
            content = content.back();
    
            if (program_counter < 1) {
                if (content == "") {
                    command_temp = "schedule function func:1" + content + "t append";
                }
                else {
                    std::string temp = std::string(temp);
                    command_temp = "schedule function func:1" + content + temp + "append";
                }
            }
            else {
                if (content == "") {
                    command_temp = "schedule function func:" + command_formatted + content + "t append";
                }
                else {
                    command_temp = "schedule function func:" + command_formatted + content + temp1 + "append";
                }
            }
        command_temp1 =  "";
        temp = 0;
        temp1 = "";
        return command_temp + "\n";
            break;

        // Random
        case 7:
            if (version == "1.20.2" || "1.20.3") {

            }
            else {

            }
            break;
        
        // GUI
        case 8:

            break;
    }
}
