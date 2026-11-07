
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <stdexcept>

#include "InvertedIndex.hpp"

int main() {

    std::cout << "Running InvertedIndex tests...\n";

    InvertedIndex index;

    // Document 1
    std::vector<std::string> doc1 = {
        "apple",
        "revenue",
        "apple",
        "growth"
    };

    // Document 2
    std::vector<std::string> doc2 = {
        "microsoft",
        "revenue",
        "growth"
    };

    // Document 3
    std::vector<std::string> doc3 = {
        "nvidia",
        "gpu",
        "sales"
    };

    // Add documents
    index.addDocument(1, doc1);
    index.addDocument(2, doc2);
    index.addDocument(3, doc3);


    // Test document count
    assert(index.getDocumentCount() == 3);


    // Test apple postings
    {
        const auto& postings = index.getPostings("apple");

        assert(postings.size() == 1);
        assert(postings[0].documentId == 1);
        assert(postings[0].termFrequency == 2);
    }


    // Test revenue postings
    {
        const auto& postings = index.getPostings("revenue");

        assert(postings.size() == 2);

        assert(postings[0].documentId == 1);
        assert(postings[0].termFrequency == 1);

        assert(postings[1].documentId == 2);
        assert(postings[1].termFrequency == 1);
    }


    // Test document frequency
    assert(index.getDocumentFrequency("revenue") == 2);
    assert(index.getDocumentFrequency("apple") == 1);
    assert(index.getDocumentFrequency("unknown") == 0);


    // Test document length
    assert(index.getDocumentLength(1) == 4);
    assert(index.getDocumentLength(2) == 3);
    assert(index.getDocumentLength(3) == 3);
    assert(index.getDocumentLength(99) == 0);


    // Test nonexistent term
    assert(index.getPostings("unknown").empty());


    // Test duplicate document protection
    {
        bool exceptionThrown = false;

        try {
            index.addDocument(1, doc1);
        }
        catch (const std::invalid_argument&) {
            exceptionThrown = true;
        }

        assert(exceptionThrown);
    }


    std::cout << "All InvertedIndex tests passed!\n";

    return 0;
}
