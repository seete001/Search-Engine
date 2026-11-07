
#include <iostream>
#include <cassert>

#include "Document.hpp"

int main() {

    std::cout << "Running Document tests...\n";

    Document doc(
        1,
        "Annual Report 2026",
        "Apple Inc.",
        2026,
        "Apple reported strong revenue growth."
    );

    // Test ID
    assert(doc.getId() == 1);

    // Test title
    assert(doc.getTitle() == "Annual Report 2026");

    // Test company
    assert(doc.getCompany() == "Apple Inc.");

    // Test year
    assert(doc.getYear() == 2026);

    // Test content
    assert(
        doc.getContent() ==
        "Apple reported strong revenue growth."
    );

    std::cout << "All Document tests passed!\n";

    return 0;
}
