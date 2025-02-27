#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No file specified. Please open a file with this program.\n";
        return 1;
    }

    std::string FilePath = argv[1];
    std::cout << "Opening file: " << FilePath << std::endl;

    std::filesystem::path path_obj(FilePath);
    std::string file_name = path_obj.filename().string();

    std::string FileContent = ReadFile(FilePath);

    if (FileContent.empty()) {
        std::cerr << "Error reading file.\n";
        return 1;
    }

    FileContent = replace(FileContent, '\n', ' ');
    FileContent = replace(FileContent, ',', ' ,');

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

    std::vector<std::string> commands_vector;
    std::vector<std::string> command_type;

    // Comment
    int program_count = 0;
    code = code_words(code_vector, 0, commands_vector, 0, command_type);

    std::vector<std::string> formal_code;
    std::stringstream ss(code);
    std::string token;
    while (std::getline(ss, token, "[ NEW_COMMAND ]")) {
        formal_code.push_back(token);
    }


    while (control <= file) {
        if (control = 0) {
            WriteToFile("starter, formal_code[control++];
        }
        else {
            WriteToFile("file" + control, formal_code[control++];
        }
    }




    std::string ResultFilePath = gen_pack += "/example.txt";
    WriteToFile(ResultFilePath, FileContent);
    std::cout << "File content has been written to " << ResultFilePath << std::endl;
    std::cout << "Press Enter to exit... ";
    std::cin.get();
    return 0;
}
