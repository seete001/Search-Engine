#ifndef INVERTED_INDEX_HPP
#define INVERTED_INDEX_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstddef>

struct Posting{
    std::size_t documentId;
    std::size_t termFrequency;
};

class InvertedIndex{
private:
    std::unordered_map<std::string, std::vector<Posting>> index;

    std::unordered_map<std::size_t, std::size_t> documentLength;

    std::unordered_set<std::size_t> indexedDocuments;

public:
    void addDocument(std::size_t documentId, const std::vector<std::string>& tokens);

    const std::vector<Posting>& getPostings(const std::string& term) const;

    std::size_t getDocumentFrequency(const std::string& term) const;

    std::size_t getDocumentCount() const;

    std::size_t getDocumentLength(std::size_t documentId) const;
};


#endif