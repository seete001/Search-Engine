#include "SearchEngine.hpp"

#include <algorithm>

SearchEngine::SearchEngine(
    InvertedIndex& index, 
    Tokenizer& tokenizer, 
    const std::vector<Document>& documents) : index(index), tokenizer(tokenizer){

    for(const auto& document: documents){
        this->documents.emplace(document.getId(), document);
    }
}

std::vector<std::size_t> SearchEngine::search(
    const std::string& query, 
    MatchMode mode) const{

    auto tokens = tokenizer.tokenize(query, true);

    if(tokens.empty()) return {};

    std::unordered_map<std::size_t, std::size_t> matches;

    for(const auto& token : tokens){
        const auto& postings = index.getPostings(token);

        for(const auto& posting : postings){
            ++matches[posting.documentId];
        }
    }

    std::vector<std::size_t> results;

    for (const auto& [documentId, matchedTerms] : matches) {

        bool matchesQuery;

        if (mode == MatchMode::OR) {
            matchesQuery = matchedTerms > 0;
        }
        else {
            matchesQuery = matchedTerms == tokens.size();
        }

        if (
            matchesQuery &&
            documents.find(documentId) != documents.end()
        ) {
            results.push_back(documentId);
        }
    }

    // Make result order deterministic for now
    std::sort(results.begin(), results.end());

    return results;
}
