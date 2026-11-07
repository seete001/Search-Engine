
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

#include "Tokenizer.hpp"

int main() {

    std::cout << "Running Tokenizer tests...\n";

    Tokenizer tokenizer;

    // Test 1: Basic tokenization
    {
        auto tokens = tokenizer.tokenize(
            "Apple reported strong revenue growth."
        );

        std::vector<std::string> expected = {
            "apple",
            "reported",
            "strong",
            "revenue",
            "growth"
        };

        assert(tokens == expected);
    }

    // Test 2: Lowercase normalization
    {
        auto tokens = tokenizer.tokenize(
            "APPLE Apple aPpLe"
        );

        std::vector<std::string> expected = {
            "apple",
            "apple",
            "apple"
        };

        assert(tokens == expected);
    }

    // Test 3: Punctuation
    {
        auto tokens = tokenizer.tokenize(
            "Hello, World! Revenue."
        );

        std::vector<std::string> expected = {
            "hello",
            "world",
            "revenue"
        };

        assert(tokens == expected);
    }

    // Test 4: Numbers
    {
        auto tokens = tokenizer.tokenize(
            "Revenue 2026 increased by 15 percent."
        );

        std::vector<std::string> expected = {
            "revenue",
            "2026",
            "increased",
            "by",
            "15",
            "percent"
        };

        assert(tokens == expected);
    }

    // Test 5: Empty input
    {
        auto tokens = tokenizer.tokenize("");

        assert(tokens.empty());
    }

    // Test 6: Multiple spaces
    {
        auto tokens = tokenizer.tokenize(
            "Apple     reported    revenue"
        );

        std::vector<std::string> expected = {
            "apple",
            "reported",
            "revenue"
        };

        assert(tokens == expected);
    }

    // Test 7: Last token without trailing space
    {
        auto tokens = tokenizer.tokenize(
            "Apple Microsoft NVIDIA"
        );

        assert(tokens.size() == 3);
        assert(tokens.back() == "nvidia");
    }

    std::cout << "All Tokenizer tests passed!\n";


    // Test 8: Stop-word filtering
    {
        auto tokens = tokenizer.tokenize(
            "Apple is the leader in technology",
            true
        );

        std::vector<std::string> expected = {
            "apple",
            "leader",
            "technology"
        };

        assert(tokens == expected);
    }

    // Test 9: Stop-word filtering disabled
    {
        auto tokens = tokenizer.tokenize(
            "Apple is the leader",
            false
        );

        std::vector<std::string> expected = {
            "apple",
            "is",
            "the",
            "leader"
        };

        assert(tokens == expected);
    }

    // Test 10: Only stop words
    {
        auto tokens = tokenizer.tokenize(
            "the and is of",
            true
        );

        assert(tokens.empty());
    }

    return 0;
}
