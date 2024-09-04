
# STL Containers in C++

STL (Standard Template Library) containers are pre-built data structures in C++ that store and organize data efficiently. They are template classes that can hold different types of data.

## Types of STL Containers

STL containers can be categorized into three main types:

1. Sequence Containers
2. Associative Containers
3. Container Adapters

### 1. Sequence Containers

Sequence containers store elements in a linear sequence and allow fast insertion and deletion operations.

- **vector**: Dynamic array that grows automatically
- **list**: Doubly-linked list
- **deque**: Double-ended queue
- **array**: Fixed-size array (C++11)
- **forward_list**: Singly-linked list (C++11)

### 2. Associative Containers

Associative containers store elements in a sorted manner, allowing for fast search, insertion, and deletion.

- **set**: Collection of unique keys, sorted by keys
- **multiset**: Collection of keys, sorted by keys (allows duplicates)
- **map**: Collection of key-value pairs, sorted by keys, keys are unique
- **multimap**: Collection of key-value pairs, sorted by keys (allows duplicate keys)

### 3. Container Adapters

Container adapters are interfaces built on top of other containers, providing a specific functionality.

- **stack**: LIFO (Last-In-First-Out) data structure
- **queue**: FIFO (First-In-First-Out) data structure
- **priority_queue**: Queue with highest priority element always at the front

### 4. Unordered Associative Containers (C++11)

These containers use hash tables for faster access but do not maintain any order of elements.

- **unordered_set**: Collection of unique keys, hashed by keys
- **unordered_multiset**: Collection of keys, hashed by keys (allows duplicates)
- **unordered_map**: Collection of key-value pairs, hashed by keys, keys are unique
- **unordered_multimap**: Collection of key-value pairs, hashed by keys (allows duplicate keys)

Each container type has its own strengths and is suitable for different use cases depending on the requirements of the program.
