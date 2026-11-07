 MiniSearch — TODO

A small financial document search engine built from scratch in C++20.

Phase 0 — Project Setup

* [ ]	Create GitHub repository
* [ ]	Configure C++20 and CMake
* [ ]	Set up project directory structure
* [ ]	Create initial executable
* [x]	Configure Git and .gitignore

Phase 1 — Financial Dataset

* [ ]	Collect public financial documents (SEC 10-K, annual reports)
* [ ]	Support TXT document loading
* [ ]	Define Document structure and unique IDs
* [ ]	Store document metadata

Phase 2 — Text Processing

* [ ]	Implement Tokenizer
* [ ]	Implement text normalization
* [ ]	Handle punctuation and special characters
* [ ]	Add optional Stop Words filtering

Phase 3 — Inverted Index

* [ ]	Implement Inverted Index
* [ ]	Build term-to-document mappings
* [ ]	Calculate Term Frequency (TF)
* [ ]	Store document statistics
* [ ]	Support index serialization and loading

Phase 4 — Query Processing

* [ ]	Parse search queries
* [ ]	Implement term lookup
* [ ]	Support multi-term queries
* [ ]	Retrieve matching documents

Phase 5 — Ranking

* [ ]	Implement TF-IDF
* [ ]	Sort results by relevance score
* [ ]	Implement BM25
* [ ]	Compare ranking algorithms

Phase 6 — Evaluation & Optimization

* [ ]	Create test queries and relevance judgments
* [ ]	Measure Precision@K and Recall@K
* [ ]	Benchmark indexing time
* [ ]	Benchmark query latency
* [ ]	Compare linear search with Inverted Index
* [ ]	Optimize memory usage and performance

Phase 7 — Finalization

* [ ]	Add unit and integration tests
* [ ]	Improve error handling
* [ ]	Add CLI search interface
* [ ]	Document architecture and algorithms
* [ ]	Add usage examples to README
* [ ]	Publish benchmark results
* [ ]	Prepare GitHub release

Future Extensions

* [ ]	Positional Index
* [ ]	Phrase Search
* [ ]	Boolean Search (AND / OR / NOT)
* [ ]	Incremental Indexing
* [ ]	Connect MiniSearch to Database Engine
* [ ]	Explore Vector Search for MiniRAG

⸻

Main Goal: Build a functional search engine from scratch and understand the fundamentals of Information Retrieval, indexing, ranking, and search performance.
