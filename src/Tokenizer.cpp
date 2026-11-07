#include "Tokenizer.hpp"

#include <cstddef>

Tokenizer::Tokenizer(){
    initializeStopWords();
}

void Tokenizer::initializeStopWords(){
    stopWords = {
        "a", "an", "the",
        "and", "or", "but",
        "is", "are", "was", "were",
        "in", "on", "at", "to",
        "of", "for", "from",
        "with", "by", "as",
        "it", "its", "this", "that",
        "be", "been", "being",
        "have", "has", "had",
        "do", "does", "did"
    };
}

std::string Tokenizer::normalize(const std::string& text) const{
    std::string result;

    for(unsigned char ch : text)
        result += (std::isalnum(ch)) ? static_cast<char>(std::tolower(ch)) : ' ';
    
    return result;
}

std::vector<std::string> Tokenizer::tokenize(const std::string& text, bool removeStopWords) const{
    std::vector<std::string> tokens;

    std::string normalized = normalize(text);

    std::string token;

    for(char ch: normalized){
        if(ch != ' '){
            token += ch;
        }else{

            if(!token.empty()){
                if(!removeStopWords || stopWords.find(token) == stopWords.end())
                    tokens.push_back(token);

                token.clear();
            }
        }
    }

    if(!token.empty())
        if(!removeStopWords || stopWords.find(token) == stopWords.end())
            tokens.push_back(token);

    return tokens;
}