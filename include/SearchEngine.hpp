#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include "Loader.hpp"
#include "Tokenizer.hpp"
#include "InvertedIndex.hpp"

#include <vector>
#include <string>
#include <unordered_map>
#include <cstddef>

enum class MatchMode{
    OR, AND
};

class SearchEngine{
private:
    InvertedIndex& index;
    Tokenizer& tokenizer;

    std::unordered_map<std::size_t, Document> documents;

public:
    SearchEngine(InvertedIndex& index, Tokenizer& tokenizer, const std::vector<Document>& documents);

    std::vector<std::size_t> search(const std::string& query, MatchMode mode = MatchMode::OR) const;
};



#endif