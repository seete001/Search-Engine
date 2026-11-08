# MiniSearch

A small financial document search engine built from scratch in C++20. It indexes SEC filings (10-K and similar annual reports) and finds documents that match a text query.

The goal is to learn the fundamentals of Information Retrieval: tokenization, inverted indexes, query processing, and ranking.

# Features
Document loader: reads every .txt file in a directory and assigns each a unique ID

Tokenizer: lowercases text, strips punctuation, and optionally removes stop words

Inverted index: maps each term to a postings list of (documentId, termFrequency), and stores document lengths

Search: multi-term queries with OR (any term) or AND (all terms) matching

Data extractor: a Python script that downloads an SEC filing and converts it to clean text
# Project Structure
```text
include/                  Header files (Document, Loader, Tokenizer, InvertedIndex, SearchEngine)
src/                      Implementations and main.cpp
tests/                    Unit tests (one executable per component)
data/documents/           Plain-text filings to index
```
document_extractor.py     SEC filing downloader and HTML-to-text converter
# Build and Run

Requires CMake 3.16+ and a C++20 compiler.

```bash
cmake -S . -B build
cmake --build build
./build/searchengine

Run the tests:

bash
cd build && ctest
Getting Documents

Install the Python dependencies, then pass a filing URL and an output filename:

bash
pip install requests beautifulsoup4
python document_extractor.py <sec-filing-url> Apple_2026.txt
```
The text is saved to data/documents/. The sample dataset covers Apple, Amazon, Microsoft, and Nvidia (2026).

# Status

Work in progress. The loader, tokenizer, inverted index, and AND/OR search are implemented. Search results are currently returned in document-ID order, and the CLI in main.cpp only loads and prints the documents.

# Planned next steps (see TODO.md):

TF-IDF and BM25 ranking
Command-line search interface
Index serialization
Evaluation (Precision@K, Recall@K) and benchmarks
Phrase search and NOT queries
