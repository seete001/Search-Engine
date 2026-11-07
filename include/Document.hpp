#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
#include <cstddef>

class Document{

private:
    std::size_t id;
    std::string title;
    std::string company;
    int year;
    std::string content;

public:
    Document(
        std::size_t id,
        const std::string& title,
        const std::string& company,
        int year,
        const std::string& content
    );

    std::size_t getId() const;
    const std::string& getTitle() const;
    const std::string& getCompany() const;
    int getYear() const;
    const std::string& getContent() const;
};

#endif