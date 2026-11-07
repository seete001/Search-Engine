#include <iostream>

#include "Document.hpp"

int main(){
    Document appleReport(
        1,
        "Annual Report 2025",
        "Apple Inc.",
        2025,
        "Apple reported strong revenue growth."
    );

    std::cout << "Document ID: "
              << appleReport.getId() << '\n';

    std::cout << "Title: "
              << appleReport.getTitle() << '\n';

    std::cout << "Company: "
              << appleReport.getCompany() << '\n';

    std::cout << "Year: "
              << appleReport.getYear() << '\n';

    std::cout << "Content: "
              << appleReport.getContent() << '\n';

    return 0;
}