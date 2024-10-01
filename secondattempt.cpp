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

std::vector<std::string> code_words(std::vector<std::string> program_vector, int program_count) {
    char valid_nums[11] = {'~', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    program_vector[program_count];
    if ((program_vector[program_count] == "if") && (program_vector[program_count + 2] == "==")) {
        if (program_vector[program_count + 1] == "block") {

        }
    else if (program_vector[program_count + 2].find(valid_nums) != std::string::npos) {

    }
    }
    // Else, Range, Var, Print, Sleep, Random, Version, Anchor, Spawn, @(Const), Range(Coordinates)
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