#include "Document.hpp"

Document::Document(std::size_t id,
    const std::string& title,
    const std::string& company,
    int year,
    const std::string& content
) : 
    id(id), title(title), company(company), year(year), content(content){}

std::size_t Document::getId() const { return id;}

const std::string& Document::getTitle() const { return title;}

const std::string& Document::getCompany() const { return company;}

int Document::getYear() const { return year;}

const std::string& Document::getContent() const { return content;}