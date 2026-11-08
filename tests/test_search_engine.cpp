
#include <iostream>
#include <cassert>
#include <vector>

#include "SearchEngine.hpp"

int main() {

    std::cout << "Running SearchEngine tests...\n";

    Tokenizer tokenizer;
    InvertedIndex index;

    std::vector<Document> documents;

    documents.emplace_back(
        1, "Apple_2026", "Apple", 2026,
        "apple revenue growth"
    );

    documents.emplace_back(
        2, "Microsoft_2026", "Microsoft", 2026,
        "microsoft cloud revenue"
    );

    documents.emplace_back(
        3, "Nvidia_2026", "Nvidia", 2026,
        "nvidia gpu sales"
    );

    documents.emplace_back(
        4, "Amazon_2026", "Amazon", 2026,
        "amazon revenue growth"
    );

    // Build the index
    for (const auto& document : documents) {

        auto tokens = tokenizer.tokenize(
            document.getContent(),
            true
        );

        index.addDocument(
            document.getId(),
            tokens
        );
    }

    SearchEngine engine(
        index,
        tokenizer,
        documents
    );

    // Test 1: Single-term search
    {
        auto results = engine.search("revenue");

        assert(results.size() == 3);
        assert(results[0] == 1);
        assert(results[1] == 2);
        assert(results[2] == 4);
    }

    // Test 2: OR search
    {
        auto results = engine.search(
            "revenue growth",
            MatchMode::OR
        );

        assert(results.size() == 3);
    }

    // Test 3: AND search
    {
        auto results = engine.search(
            "revenue growth",
            MatchMode::AND
        );

        assert(results.size() == 2);
        assert(results[0] == 1);
        assert(results[1] == 4);
    }

    // Test 4: Unknown term
    {
        auto results = engine.search("bitcoin");

        assert(results.empty());
    }

    // Test 5: Empty query
    {
        auto results = engine.search("");

        assert(results.empty());
    }

    // Test 6: Stop-word-only query
    {
        auto results = engine.search("the and is");

        assert(results.empty());
    }

    std::cout << "All SearchEngine tests passed!\n";

    return 0;
}
