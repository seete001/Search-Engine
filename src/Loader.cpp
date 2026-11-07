#include "Loader.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

namespace fs = std::filesystem;

Loader::Loader(){}

std::vector<Document> Loader::loadDirectory(const std::string& path){
     std::vector<Document> documents;

     if(!fs::exists(path) || !fs::is_directory(path)){
        std::cerr << "Invalid directory: " << path << "\n";
        return documents;
     }

     size_t id = 1;

     for(const auto& entry : fs::directory_iterator(path)){
        if(!entry.is_regular_file()) continue;

        if(entry.path().extension() != ".txt") continue;

        std::ifstream file(entry.path());

        if(!file.is_open()){
            std::cerr << "Could not open : " << entry.path() << "\n";
            continue;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string content = buffer.str();

        std::string title = entry.path().stem().string();

        Document document(
            id++,
            title,
            "Unknown",
            0,
            content
        );

        documents.push_back(document);
     }

     return documents;
}