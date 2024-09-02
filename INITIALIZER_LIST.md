
# std::initializer_list

`std::initializer_list` is a lightweight proxy object that provides access to an array of objects of type `const T`. It is commonly used to allow list initialization of objects and to pass a varying number of arguments to functions.

## Key features:

1. Defined in the `<initializer_list>` header
2. Always contains constant elements (cannot modify elements through the initializer list)
3. Cheap to copy (only the start pointer and length are copied)
4. Does not own the underlying array (lifetime of elements is that of the original initializer)

## Usage examples:

### 1. Constructor with initializer list:


#include <initializer_list>
#include <vector>

class MyContainer {
public:
    MyContainer(std::initializer_list<int> list) : data(list) {}
private:
    std::vector<int> data;
};

// Usage
MyContainer c = {1, 2, 3, 4, 5};


### 2. Function accepting initializer list:


#include <initializer_list>
#include <iostream>

void printNumbers(std::initializer_list<int> numbers) {
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// Usage
printNumbers({10, 20, 30, 40, 50});


### 3. Range-based for loop:


#include <initializer_list>

int sum(std::initializer_list<int> values) {
    int total = 0;
    for (int val : values) {
        total += val;
    }
    return total;
}

// Usage
int result = sum({1, 2, 3, 4, 5});


### 4. std::initializer_list methods:


#include <initializer_list>
#include <iostream>

void displayInfo(std::initializer_list<int> list) {
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "First element: " << *list.begin() << std::endl;
    std::cout << "Last element: " << *(list.end() - 1) << std::endl;
}

// Usage
displayInfo({5, 10, 15, 20, 25});


Remember that `std::initializer_list` is designed for temporary use and does not own the underlying array. If you need to store the data for longer, consider copying it to a container like `std::vector`.
