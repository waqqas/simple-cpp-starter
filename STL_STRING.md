
# std::string

`std::string` is a class in the C++ Standard Template Library (STL) that represents a sequence of characters. It provides a convenient and efficient way to handle strings in C++.

## Important Functions and Usage

1. Constructor:
   - `string()`: Creates an empty string
   - `string(const char* s)`: Creates a string from a C-style string
   - `string(size_t n, char c)`: Creates a string with n copies of character c

2. Element Access:
   - `operator[]`: Access individual characters
   - `at()`: Access with bounds checking
   - `front()`: Access the first character
   - `back()`: Access the last character

3. Capacity:
   - `size()` or `length()`: Returns the number of characters
   - `empty()`: Checks if the string is empty
   - `capacity()`: Returns the current capacity
   - `resize()`: Changes the size of the string

4. Modifiers:
   - `clear()`: Erases all characters
   - `insert()`: Inserts characters
   - `erase()`: Removes characters
   - `push_back()`: Appends a character
   - `pop_back()`: Removes the last character
   - `append()`: Appends characters to the end
   - `operator+=`: Appends characters or strings

5. String Operations:
   - `substr()`: Returns a substring
   - `copy()`: Copies characters to an array
   - `find()`: Finds the first occurrence of a substring
   - `rfind()`: Finds the last occurrence of a substring
   - `replace()`: Replaces a portion of the string

6. Non-member functions:
   - `operator+`: Concatenates strings
   - `operator==`, `operator!=`, `operator<`, etc.: Compares strings

7. Input/Output:
   - Can be used with `cin` and `cout` for easy I/O operations

Example usage:


#include <string>
#include <iostream>

int main() {
    std::string s1 = "Hello";
    std::string s2 = " World";
    
    s1 += s2;  // Concatenation
    std::cout << s1 << std::endl;  // Output: Hello World
    
    std::cout << s1.substr(0, 5) << std::endl;  // Output: Hello
    
    std::cout << s1.find("World") << std::endl;  // Output: 6
    
    s1.replace(0, 5, "Hi");
    std::cout << s1 << std::endl;  // Output: Hi World
    
    return 0;
}


`std::string` provides a rich set of functions for string manipulation, making it a powerful tool for handling text in C++ programs.
