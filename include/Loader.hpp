#ifndef LOADER_HPP
#define LOADER_HPP

#include "Document.hpp"

#include <string>
#include <vector>


class Loader{
public:
    Loader();

    std::vector<Document> loadDirectory(const std::string& path);
};

#endif