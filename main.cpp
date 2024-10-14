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
