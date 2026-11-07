
#include <iostream>
#include <cassert>
#include <fstream>
#include <filesystem>
#include <algorithm>

#include "Loader.hpp"

namespace fs = std::filesystem;

int main() {

    std::cout << "Running Loader tests...\n";

    // Create temporary test directory
    fs::path testDir = "build/test_documents";

    fs::remove_all(testDir);
    fs::create_directories(testDir);

    // Create first test document
    {
        std::ofstream file(testDir / "Apple_2026.txt");

        file << "Apple reported strong revenue growth.";
    }

    // Create second test document
    {
        std::ofstream file(testDir / "Microsoft_2026.txt");

        file << "Microsoft reported cloud revenue growth.";
    }

    // Test loading
    Loader loader;

    auto documents = loader.loadDirectory(
        testDir.string()
    );

    // Test number of documents
    assert(documents.size() == 2);

    // Check document titles and contents
    bool appleFound = false;
    bool microsoftFound = false;

    for (const auto& doc : documents) {

        if (doc.getTitle() == "Apple_2026") {

            appleFound = true;

            assert(
                doc.getContent() ==
                "Apple reported strong revenue growth."
            );
        }

        if (doc.getTitle() == "Microsoft_2026") {

            microsoftFound = true;

            assert(
                doc.getContent() ==
                "Microsoft reported cloud revenue growth."
            );
        }
    }

    assert(appleFound);
    assert(microsoftFound);

    // Test invalid directory
    auto emptyDocuments =
        loader.loadDirectory("build/nonexistent_directory");

    assert(emptyDocuments.empty());

    // Cleanup
    fs::remove_all(testDir);

    std::cout << "All Loader tests passed!\n";

    return 0;
}
