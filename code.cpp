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

int command_count() {
    static int counter = 0;
    return counter++;
}

std::string command_creation(int command_type, std::string content, int program_counter) {
    static std::string commands;
    // Version
    if (command_type = 0) {

    }
    // Anchor
    else if (command_type = 1) {

    }

    // Spawn
    else if (command_type = 2) {

    }

    // IF
    else if (command_type = 3) {

    }

    // Else
    else if (command_type = 4) {

    }

    // Print
    else if (command_type = 5) {
        int temp;
        temp << command_count();
        std::string temp2 = std::to_string(temp);
        std::string command_temp = "say " + content;
        std::string command_temp1 = "\\nfunction funcs:" + temp2;
        if (program_counter < 1) {
            commands += command_temp + command_temp1;
        }
        else {
            commands += "\\n" + command_temp + command_temp1;
        }
    }

    // Sleep
    else if (command_type = 6) {

    }

    // Random
    else if (command_type = 7) {

    }

}

std::vector<std::string> code_words(std::vector<std::string> program_vector, int program_count, std::vector<std::string> commands_vector, int commands_count) {
    char valid_nums[11] = {'~', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    program_vector[program_count];
    int next_func_num;
    std::string next_func = "function functions:";
    
    if ((program_vector[program_count] == "if") && (program_vector[program_count + 2] == "==")) {
        if (program_vector[program_count + 1] == "coordinates") {

        }
    }
    else if ((program_vector[program_count] == "if") && (program_vector[program_count + 2].find(valid_nums) != std::string::npos)) {
        
    }

    else if (program_vector[program_count] == "else") {

    }

    else if (program_vector[program_count] == "print") {
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

    else if (program_vector[program_count] == "sleep") {

    }

    else if (program_vector[program_count] == "random") {

    }

    else if (program_vector[program_count] == "@") {

    }

    else if (program_vector[program_count] == "range") {

    }
    // Var, Version, Anchor, Spawn, @(Const, droppless), Range(Coordinates)
}

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
