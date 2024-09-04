
# std::unordered_map in C++

`std::unordered_map` is a container in C++ that stores key-value pairs in an unordered manner. It provides fast access to elements using unique keys, with average constant-time complexity for insertion, deletion, and lookup operations.

## Key Features

- Unordered storage: Elements are not stored in any particular order.
- Fast access: O(1) average time complexity for most operations.
- Unique keys: Each key in the map must be unique.
- Hash-based: Uses a hash function to organize elements internally.

## Basic Usage


#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map
    std::unordered_map<std::string, int> age_map;

    // Insert elements
    age_map["Alice"] = 30;
    age_map["Bob"] = 25;
    age_map.insert({"Charlie", 35});

    // Access elements
    std::cout << "Alice's age: " << age_map["Alice"] << std::endl;

    // Check if a key exists
    if (age_map.find("David") != age_map.end()) {
        std::cout << "David's age found" << std::endl;
    } else {
        std::cout << "David's age not found" << std::endl;
    }

    // Iterate through the map
    for (const auto& pair : age_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Remove an element
    age_map.erase("Bob");

    // Get the size of the map
    std::cout << "Map size: " << age_map.size() << std::endl;

    return 0;
}


## Common Functions

1. `insert(key, value)`: Inserts a key-value pair.
2. `erase(key)`: Removes the element with the specified key.
3. `find(key)`: Returns an iterator to the element with the specified key.
4. `at(key)`: Accesses the value associated with the key (throws exception if not found).
5. `operator[]`: Accesses or inserts an element with the given key.
6. `size()`: Returns the number of elements in the map.
7. `empty()`: Checks if the map is empty.
8. `clear()`: Removes all elements from the map.
9. `count(key)`: Returns the number of elements with the specified key (0 or 1).
10. `begin()` and `end()`: Return iterators to the first element and one past the last element.

## Performance Considerations

- Average time complexity: O(1) for insert, erase, and find operations.
- Worst-case time complexity: O(n) when many collisions occur in the hash table.
- Space complexity: O(n), where n is the number of elements in the map.

`std::unordered_map` is ideal for scenarios where fast lookup and insertion are required, and the order of elements is not important. For ordered key-value pairs, consider using `std::map` instead.
