#include <iostream>

#include "Loader.hpp"

const std::string PATH = "data/documents";

int main(){
    Loader loader;
    std::vector<Document> documents = loader.loadDirectory(PATH);

    for(const auto& document: documents){
        std::cout << "ID: "
        << document.getId() << '\n';

        std::cout << "Title: "
        << document.getTitle() << '\n';

        std::cout << "Content: "
        << document.getContent() << '\n';

        std::cout << "-------------------\n";
    }
    return 0;
}