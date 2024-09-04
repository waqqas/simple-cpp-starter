
# STL Iterators

STL (Standard Template Library) iterators are a crucial part of C++ programming, providing a uniform way to access elements in containers. They act as a bridge between algorithms and containers, allowing for efficient traversal and manipulation of data structures.

## Types of Iterators

1. Input Iterator: Read-only, forward-moving
2. Output Iterator: Write-only, forward-moving
3. Forward Iterator: Read-write, forward-moving
4. Bidirectional Iterator: Read-write, can move forward and backward
5. Random Access Iterator: Read-write, can jump to any element

## Examples

### Vector Iterator


#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using iterator to traverse the vector
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


### List Iterator


#include <iostream>
#include <list>

int main() {
    std::list<std::string> fruits = {"apple", "banana", "orange"};

    // Using iterator to modify elements
    for (std::list<std::string>::iterator it = fruits.begin(); it != fruits.end(); ++it) {
        *it = "fresh_" + *it;
    }

    // Printing modified list
    for (const auto& fruit : fruits) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;

    return 0;
}


### Map Iterator


#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 35}};

    // Using iterator to access key-value pairs
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
        std::cout << it->first << " is " << it->second << " years old." << std::endl;
    }

    return 0;
}


### Reverse Iterator


#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using reverse iterator to traverse the vector backwards
    for (std::vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}


These examples demonstrate the versatility and power of STL iterators in C++. They provide a consistent interface for working with different container types and enable the creation of generic algorithms that can work with any container that supports the required iterator type.
