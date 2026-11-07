#include "InvertedIndex.hpp"

#include <stdexcept>

void InvertedIndex::addDocument(std::size_t documentId, const std::vector<std::string>& tokens){
    if(indexedDocuments.find(documentId) != indexedDocuments.end())
        throw std::invalid_argument("Document has been already indexed");

    indexedDocuments.insert(documentId);

    documentLength[documentId] = tokens.size();

    std::unordered_map<std::string, std::size_t> frequencies;

    for(const auto& token: tokens)
        ++frequencies[token];

    for(const auto& [term, frequency]: frequencies)
        index[term].push_back({documentId, frequency});
}

const std::vector<Posting>& InvertedIndex::getPostings(const std::string& term) const{
    auto it = index.find(term);

    if(it == index.end()){
        static const std::vector<Posting> empty;
        return empty;
    }

    return it->second;
}

std::size_t InvertedIndex::getDocumentFrequency(const std::string& term) const{
    auto it = index.find(term);

    if(it == index.end())
        return 0;

    return it->second.size();
}

std::size_t InvertedIndex::getDocumentCount() const{
    return indexedDocuments.size();
}

std::size_t InvertedIndex::getDocumentLength(std::size_t documentId) const{
    auto it = documentLength.find(documentId);

    if(it == documentLength.end())
        return 0;

    return it->second;
}
