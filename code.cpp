#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  
#include <filesystem>
#include <algorithm>
#include <vector>

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

std::string replace(std::string str, const std::string& oldSubstr, const std::string& newSubstr) {
    size_t pos = 0;
    while ((pos = str.find(oldSubstr, pos)) != std::string::npos) {
        str.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length();
    }

    return str;
}



std::string processVectorUntilChar(const std::vector<std::string>& vec, size_t startIndex, std::string targetChar) {
    std::string result;
    for (size_t i = startIndex; i < vec.size(); ++i) {
        if ((vec[i] == targetChar) && (vec[i-1] != "\\")) {
            break;
        }
        result += vec[i];
    }

    return result;
}

std::string processstringuntilclose(const std::vector<std::string>& code, int startIndex, std::string close_char = "}") {
    std::string temp;
    std::string open_char;
    bool confirmation;
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
        if ((code[num] == close_char) && (error = 0)) {
            confirmation = 1;
            return "FINISHED";
        }
        else if ((code[num] == close_char) && (error != 0)) {
            error -= 1;
        }
        else if (code[num] == open_char) {
            error += 1;
        }
        else {
            num += 1;
        }
    }
}


int command_count() {
    static int counter = 0;
    return counter++;
}

std::string command_creation(int command_type, std::string content, int program_counter) {
    int temp;
    int command_formatting;
    command_formatting << command_count();
    std::string command_formatted = std::to_string(command_formatting);
    std::string command_temp;
    std::string command_temp1;

    std::string temp1;

    static std::string commands;


    switch(command_type) {
        // Version
        case 0:
            // 1: 1.6.1 – 1.8.9
            // 2: 1.9 – 1.10.2
            // 3: 1.11 – 1.12.2
            // 4: 1.13 – 1.14.4
            // 5: 1.15 – 1.16.1
            // 6: 1.16.2 – 1.16.5
            // 7: 1.17 – 1.17.1
            // 8: 1.18 – 1.18.2
            // 9: 1.19 – 1.19.2
            // 11: 22w42a – 22w44a
            // 12: 1.19.3
            // 13: 1.19.4
            // 14: 23w14a – 23w16a
            // 15: 1.20 – 1.20.1
            // 16: 23w31a
            // 17: 23w32a – 1.20.2-pre1
            // 18: 1.20.2
            // 19: 23w42a
            // 20: 23w43a - 23w44a
            // 21: 23w45a - 23w46a
            // 22: 1.20.3 - 1.20.4
            // 24: 24w03a - 24w04a
            // 25: 24w05a - 24w05b
            // 26: 24w06a - 24w07
            // 28: 24w09a - 24w10a
            // 29: 24w11a
            // 30: 24w12a
            // 31: 24w13a - 1.20.5-pre3
            // 32: 1.20.5-pre4 - 1.20.5
            // 34: 1.21 - onwards
            
            // LINK: https://minecraft.fandom.com/wiki/Pack_format
            break;
        
        // Anchor
        case 1:

            break;

        // Spawn
        case 2:

            break;

        // If
        case 3:

            break;

        // Else
        case 4:

            break;

        // Print
        case 5:
            command_temp = "say " + content;
            command_temp1 = "\\nfunction funcs:" + temp;
            if (program_counter < 1) {
                commands += command_temp + "//nfunction funcs:1";
            }
            else {
                commands += "\\n" + command_temp + command_temp1;
            }
            temp = 0;
            temp1 = "";
            command_temp = "";
            command_temp1 = "";
            break;

        // Sleep
        case 6:
            temp1 = content.back();
            content.rbegin();
            content = content.back();
    
            if (program_counter < 1) {
                if (content == "") {
                    command_temp = "schedule function func:1" +content + "t append";
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
        commands += "//n" + command_temp;
        
        command_temp = "";
        command_temp1 =  "";
        temp = 0;
        temp1 = "";
            break;

        // Random
        case 7:
        
            break;
    }
    


}

std::vector<std::string> code_words(std::vector<std::string> program_vector, int program_count, std::vector<std::string> commands_vector, int commands_count) {
    char valid_nums[11] = {'~', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    program_vector[program_count];
    int next_func_num;
    std::string next_func = "function functions:";

    std::string switch_var = program_vector[program_count];
    
        // IF
        if (program_vector[program_count] == "if") {
            if (program_vector[program_count + 2].find(valid_nums) != std::string::npos) {
                if (program_vector[program_count + 1] == "(") {

                    command_creation(3, "", 0);
                }
            }
        }

        // ELSE
        if (program_vector[program_count] == "else") {

        }

        // PRINT
        if (program_vector[program_count] == "print") {
            if (program_vector[program_count + 1] == "(") {
                if (program_vector[program_count + 2] == "str") {
                    if (program_vector[program_count + 3] == "(") {
                        std::vector<std::string> temp_vector;
                        temp_vector.erase(temp_vector.begin(), temp_vector.begin() + program_count+3);
                          std::string say_content = processVectorUntilChar(temp_vector, program_count+3, ")");
                        command_creation(5, say_content, program_count);
                    }
                }
            }
        }

        // SLEEP
        if (program_vector[program_count] == "sleep") {
            if (program_vector[program_count + 1] == "(") {
                if (program_vector[program_count + 3] == ")") {
                    std::string contents = program_vector[program_count + 2];
                    command_creation(6, contents, program_count);
                }
            }
        }

        // RANDOM
        if (program_vector[program_count] == "random") {

        }

        // @
        if (program_vector[program_count] == "@") {

        }

        // RANGE
        if (program_vector[program_count] == "range") {

        }

    }
    // Var, Version, Anchor, Spawn, @(Const, droppless), Range(Coordinates)




int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No file specified. Please open a file with this program.\n";
        return 1;
    }

    std::string FilePath = argv[1];
    std::cout << "Opening file: " << FilePath << std::endl;

    std::string FileContent = ReadFile(FilePath);
    
    if (FileContent.empty()) {
        std::cerr << "Error reading file.\n";
        return 1;
    }

    // Generate Folder Structure
    std::filesystem::path OriginalPath(FilePath);
    std::filesystem::path Directory = OriginalPath.parent_path(); 
    std::filesystem::path gen_pack = Directory / "Generated Datapack/data/func/functions";
    std::filesystem::create_directory(gen_pack);


    // creating Code vector
    std::string text = FileContent;
    std::vector<std::string> code_vector;
    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        code_vector.push_back(token);
    }


    // Comment
    int program_count = 0;
    while (program_count < code_vector.size()) {
        
        program_count += 1;
    }






    std::string ResultFilePath = gen_pack += "/example.txt";  
    WriteToFile(ResultFilePath, FileContent);
    std::cout << "File content has been written to " << ResultFilePath << std::endl;
    std::cout << "Press Enter to exit... ";
    std::cin.get();
    return 0;
}
