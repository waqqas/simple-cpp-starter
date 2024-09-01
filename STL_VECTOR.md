
# std::vector

`std::vector` is a dynamic array container in C++ that is part of the Standard Template Library (STL). It provides a flexible and efficient way to store and manipulate sequences of elements.

Key features of std::vector:
- Automatic resizing
- Contiguous memory storage
- Random access to elements

## Important functions

1. Constructors:
   - `vector<T>()`: Default constructor
   - `vector<T>(size_t n)`: Construct with n default-inserted elements
   - `vector<T>(size_t n, const T& val)`: Construct with n copies of val

2. Element access:
   - `operator[]`: Access element by index (no bounds checking)
   - `at()`: Access element by index (with bounds checking)
   - `front()`: Access the first element
   - `back()`: Access the last element
   - `data()`: Get pointer to the underlying array

3. Capacity:
   - `size()`: Get the number of elements
   - `capacity()`: Get the current capacity
   - `empty()`: Check if the vector is empty
   - `reserve(size_t n)`: Reserve space for at least n elements
   - `shrink_to_fit()`: Reduce capacity to fit the current size

4. Modifiers:
   - `push_back(const T& val)`: Add element to the end
   - `pop_back()`: Remove the last element
   - `insert(iterator pos, const T& val)`: Insert element at position
   - `erase(iterator pos)`: Remove element at position
   - `clear()`: Remove all elements

5. Iterators:
   - `begin()` / `end()`: Get iterators to the start/end
   - `rbegin()` / `rend()`: Get reverse iterators

Example usage:


#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    vec.push_back(6);
    vec.pop_back();
    
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    
    return 0;
}


This will output: 1 2 3 4 5
