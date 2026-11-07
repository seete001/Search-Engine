#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>
#include <unordered_set>

class Tokenizer{
private:
    std::string normalize(const std::string& text) const;

    std::unordered_set<std::string> stopWords;

    void initializeStopWords();
public:
    Tokenizer();
    
    std::vector<std::string> tokenize(const std::string& text, bool removeStopWords = false) const;

};

#endif